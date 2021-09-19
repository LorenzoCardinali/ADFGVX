//
// Created by Cardif on 16/09/2021.
//

#ifndef LORENZOCARDINALI105789_ADFGVX_H
#define LORENZOCARDINALI105789_ADFGVX_H

/**
 * Definizione di un tipo "byte" (0-255).
 */
typedef unsigned char byte;

/**
 * Definizione tipo per struttura dati della chiave di criptazione.
 */
typedef struct struct_key {
    /**
     * Buffer usato per memorizzare un singolo byte.
     */
    byte buffer;

    /**
     * Array che definisce 16 permutazioni (colonne).
     */
    byte C[16];

    /**
     * Array che definisce 16 permutazioni (righe).
     */
    byte R[16];

    /**
     * Array che definisce 256 permutazioni (matrice).
     */
    byte K[16][16];
} t_key;

/**
 * # # # Funzioni principali # # #
 */

/**
 * Codifica un file in input utilizzando una chiave.
 * La codifica viene salvata in un secondo file di output.
 *
 * @param key_file      chiave codifica
 * @param input_file    file di input
 * @param output_file   file di output
 */
void encode(char *key_file, char *input_file, char *output_file);

/**
 * De-Codifica un file in input utilizzando una chiave.
 * La de-codifica viene salvata in un secondo file di output.
 *
 * @param key_file      chiave codifica
 * @param input_file    file di input
 * @param output_file   file di output
 */
void decode(char *key_file, char *input_file, char *output_file);

/**
 * Genera una chiave di codifica che viene salvata in un file
 *
 * @param key_file  file di output
 * @param s1        parametro 1 per la generazione
 * @param k1        parametro 2 per la generazione
 * @param s2        parametro 3 per la generazione
 * @param k2        parametro 4 per la generazione
 * @param s3        parametro 5 per la generazione
 * @param k3        parametro 6 per la generazione
 */
void genkey(char *key_file, char *s1, char *k1, char *s2, char *k2, char *s3, char *k3);

/**
 * # # # Funzioni di utilita' # # #
 */


/**
 * # # # Funzioni file # # #
 */

/**
 * Apre fine in lettura (input).
 *
 * @param name nome file di input.
 * @return puntatore al file di input.
 */
FILE *open_input_file(char *name);

/**
 * Apre file in scrittura (output).
 *
 * @param name nome file di output.
 * @return puntatore al file di output.
 */
FILE *open_output_file(char *name);

/**
 * Chiude un file
 *
 * @param file FIle da chiudere.
 */
void close_file(FILE *file);

/**
 * # # # Funzioni Linked List # # #
 */

/**
 * Definisco il tipo della linked list.
 */
typedef struct node lklist;

/**
 * Struttura nodo della linked list.
 */
struct node {
    byte value;
    struct node *next;
};

/**
 * Aggiunge un nodo alla fine della lista.
 *
 * @param head Testa della lista.
 * @return Testa della lista.
 */
lklist *add_node(lklist *head, byte value);

/**
 * Rimuove un nodo dalla lista alla posizione immessa.
 *
 * @param head Testa della lista.
 * @param index Posizione nodo.
 * @return Testa della lista.
 */
lklist *remove_node(lklist *head, int index);

/**
 * Stampa la lista
 *
 * @param head Testa della Lista.
 */
void print_list(lklist *head);

/**
 * Elimina una lista.
 *
 * @param head Testa della lista.
 * @return La testa della lista eliminata.
 */
lklist *delete_list(lklist *head);

/**
 * Ritorna il nodo alla posizione immessa nella lista.
 *
 * @param head Testa della lista.
 * @param index Posizione immessa.
 * @return il nodo alla posizione immessa nella lista.
 */
byte get_node(lklist *head, int index);

/**
 * Restituisce il numero di nodi presenti nella lista.
 *
 * @param head Testa della lista.
 * @return il numero di nodi presenti nella lista.
 */
int countNodes(lklist *head);


#endif //LORENZOCARDINALI105789_ADFGVX_H