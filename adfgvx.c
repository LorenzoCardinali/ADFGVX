//
// Created by Lorenzo Cardinali on 18/09/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "adfgvx.h"
#include "linklistlib.h"
#include "filelib.h"

/**
 * Divisione euclidea che permette il modulo dei numeri negativi.
 *
 * @param val1 Parametro 1.
 * @param val2 Parametro 2.
 * @return Divisione euclidea.
 */
int euc_mod(int val1, int val2);

/**
 * Riempie una lista con una serie definita.
 *
 * @param head Testa della lista.
 * @param max Numero massimo elementi serie.
 * @return una lista con una serie definita.
 */
lklist *fill_list(lklist *head, int max);

/**
 * Riempie un array leggendo un quantitativo di N caratteri da un file.
 *
 * @param input_file File da leggere.
 * @param array Array da riempire.
 * @param count Quantità di elementi da leggere.
 * @return Puntatore all'array riempito.
 */
void fill_array(FILE *input_file, byte *array, int count);

/**
 * Carica i dati necessari per utilizzare la chiave di criptazione.
 *
 * @param key File della chiave.
 * @param keytable Tabella della chiave.
 * @return Puntatore alla tabella della chiave.
 */
void fill_table(FILE *key, t_key *keytable);

/**
 * Cripta un file usando una chiave precedentemente caricata in memoria.
 *
 * @param key_table Chiave caricata in memoria.
 * @param input_file File da criptare.
 * @param output_file File criptato.
 */
void encode_file(t_key *key_table, FILE *input_file, FILE *output_file);

/**
 * De-cripta un file usando una chiave precedentemente caricata in memoria.
 *
 * @param key_table Chiave caricata in memoria.
 * @param input_file File da de-criptare.
 * @param output_file File de-criptato.
 */
void decode_file(t_key *key_table, FILE *input_file, FILE *output_file);

/**
 * Ricerca la posizione di un byte in una matrice k
 *
 * @param key_table Struct dove la matrice e' memorizzata.
 * @param position Posisizione da aggiornare.
 */
void find_byte(t_key *key_table, t_pos *position);

/**
 * Divide un byte in 2 nibble e ricerca la loro posizione in 2 array.
 *
 * @param key_table Struct dove gli array sono memorizzati.
 * @param position Posisizione da aggiornare.
 */
void find_nibble(t_key *key_table, t_pos *position);

/**
 * # # # Funzioni principali # # #
 */

void encode(char *key_file, char *input_file, char *output_file) {
    FILE *key = open_input_file(key_file);
    t_key *keytable = malloc(sizeof(t_key));
    fill_table(key, keytable);

    FILE *input = open_input_file(input_file);
    FILE *output = open_output_file(output_file);

    encode_file(keytable, input, output);

    close_file(key);
    close_file(input);
    close_file(output);
}

void decode(char *key_file, char *input_file, char *output_file) {
    FILE *key = open_input_file(key_file);
    t_key *keytable = malloc(sizeof(t_key));
    fill_table(key, keytable);

    FILE *input = open_input_file(input_file);
    FILE *output = open_output_file(output_file);

    decode_file(keytable, input, output);

    close_file(key);
    close_file(input);
    close_file(output);
}

void genkey(char *key_file, char *s1, char *k1, char *s2, char *k2, char *s3, char *k3) {
    FILE *keyfile = open_output_file(key_file);
    lklist *L1 = NULL;

    const int key_lenght[] = {16, 16, 256};
    const int vars[6] = {strtol(s1, NULL, 16), strtol(k1, NULL, 36),
                         strtol(s2, NULL, 16), strtol(k2, NULL, 36),
                         strtol(s3, NULL, 16), strtol(k3, NULL, 36)};

    for (int i = 0; i < 3; ++i) {
        L1 = fill_list(L1, key_lenght[i]);

        int c = euc_mod(vars[i * 2], key_lenght[i]), n = countNodes(L1);

        while (n != 0) {
            byte v = get_node(L1, c);
            L1 = remove_node(L1, c);
            fputc(v, keyfile);
            n = countNodes(L1);
            c = euc_mod(c + vars[i * 2 + 1], n);
        }
    }

    close_file(keyfile);
}

/**
 * # # # Funzioni di utilita' # # #
 */

void encode_file(t_key *key_table, FILE *input_file, FILE *output_file) {
    t_pos *position = malloc(sizeof(t_pos));
    size_t file_length = file_size(input_file);
    byte b2;

    for (position->k = 0; position->k < file_length; ++position->k) {
        position->b = fgetc(input_file);
        find_byte(key_table, position);

        b2 = key_table->C[euc_mod(position->i + position->k, 16)] << 4 ^
             key_table->R[euc_mod(position->j + position->k, 16)];

        fputc(b2, output_file);
    }
}

void decode_file(t_key *key_table, FILE *input_file, FILE *output_file) {
    t_pos *position = malloc(sizeof(t_pos));
    size_t file_length = file_size(input_file);
    byte b2;

    for (position->k = 0; position->k < file_length; ++position->k) {
        position->b = fgetc(input_file);
        find_nibble(key_table, position);

        b2 = key_table->K[euc_mod(position->j - position->k, 16)]
        [euc_mod(position->i - position->k, 16)];

        fputc(b2, output_file);
    }
}

int euc_mod(int val1, int val2) {
    if (val2 == 0)
        return 0;

    int result = val1 % val2;

    if (result < 0)
        result += val2;

    return result;
}

lklist *fill_list(lklist *head, int max) {
    for (int i = 0; i < max; ++i)
        head = add_node(head, i);

    return head;
}

void fill_table(FILE *key, t_key *keytable) {

    if (file_size(key) != 288) {
        perror("Keyfile non valido\n");
        exit(1);
    }

    fill_array(key, keytable->C, 16);
    fill_array(key, keytable->R, 16);
    for (int i = 0; i < 16; ++i)
        fill_array(key, keytable->K[i], 16);
}

void fill_array(FILE *input_file, byte *array, int count) {
    for (int i = 0; i < count; ++i)
        array[i] = fgetc(input_file);
}

void find_byte(t_key *key_table, t_pos *position) {
    for (position->i = 0; position->i < 16; ++position->i) {
        for (position->j = 0; position->j < 16; ++position->j) {
            if (position->b == key_table->K[position->j][position->i])
                return;
        }
    }
}

void find_nibble(t_key *key_table, t_pos *position) {
    byte v1 = (position->b >> 4) & 0x0F, v2 = position->b & 0x0F;

    for (position->i = 0; position->i < 16; ++position->i) {
        if (v1 == key_table->C[position->i])
            break;
    }

    for (position->j = 0; position->j < 16; ++position->j) {
        if (v2 == key_table->R[position->j])
            break;
    }
}