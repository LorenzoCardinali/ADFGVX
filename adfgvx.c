//
// Created by Cardif on 18/09/2021.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "adfgvx.h"

/**
 * Divisione euclidea che permette il modulo dei numeri negativi.
 *
 * @param val1 Parametro 1.
 * @param val2 Parametro 2.
 * @return Divisione euclidea.
 */
int euc_mod(int val1, int val2);

/**
 * Genera un nuovo nodo.
 *
 * @param value Valore da assegnare al nuovo nodo.
 * @return Nodo creato.
 */
lklist *newNode(int value);

/**
 * Rimuove la testa della lista.
 *
 * @param head Testa della lista.
 * @return La nuova testa.
 */
lklist *remove_head(lklist *head);

/**
 * Riempie una lista con una serie definita.
 *
 * @param head Testa della lista.
 * @param max Numero massimo elementi serie.
 * @return una lista con una serie definita.
 */
lklist *fill_list(lklist *head, int max);

/**
 * Genera la permutazione di una lista.
 *
 * @param head1 Testa della lista 1
 * @param head2 Testa della lista 2
 * @return Testa della lista permutata (lista 2)
 */
lklist *perm_list(lklist *head1, lklist *head2);

/**
 * # # # Funzioni principali # # #
 */

/*
 * perm[0][i],perm[1][i], perm[2][i]
 * serie 1 -> 16  , s1 , k1
 * serie 2 -> 16  , s2 , k2
 * serie 3 -> 255 , s3 , k3
 */

//int perm[3][3] = {{16,                   16,                   255},
//                  {strtol(s1, NULL, 10), strtol(s2, NULL, 10), strtol(s3, NULL, 10)},
//                  {strtol(k1, NULL, 10), strtol(k2, NULL, 10), strtol(k3, NULL, 10)}};

void genkey(char *key_file, char *s1, char *k1, char *s2, char *k2, char *s3, char *k3) {

    FILE *keyfile = open_output_file("key");
    lklist *L1, *L2;

    int perm[3][3] = {{100, 100, 100},
                      {9,  9,  9},
                      {9,  9,  9}};

    for (int i = 0; i < 3; ++i) {

        L1 = fill_list(L1, perm[0][i]);
        L2 = NULL;
        int c = euc_mod(perm[1][i], perm[0][i]), n = countNodes(L1);

        while (n != 0) {
            byte v = get_node(L1, c);
            L1 = remove_node(L1, c);
            fputc(v, keyfile);
            //printf("%d \n", v);
            L2 = add_node(L2, v);
            n = countNodes(L1);
            c = euc_mod(c + perm[2][i], n);
        }
        print_list(L2);

    }

    close_file(keyfile);

    FILE *keyfile2 = open_input_file("key");

    //lklist *L3 = NULL;

/*    for (int i = 0; i < 300; ++i) {
        printf("%d ", fgetc(keyfile2));
        //L3 = add_node(L3, fgetc(keyfile2));
    }*/

    size_t f_len, f_actualread;

    char *buffer = NULL;

    fseek(keyfile2, 0, SEEK_END);
    f_len = ftell(keyfile2);
    rewind(keyfile2);

    buffer = malloc(f_len + 1);

    if(buffer == NULL)
    {
        puts("malloc failed");
        return;
    }

    f_actualread = fread(buffer, 1, f_len, keyfile2);
    buffer[f_actualread] = 0;

    for (int i = 0; i < f_actualread; ++i) {
        printf("%d -> ", buffer[i]);
    }

    free(buffer);
    buffer = NULL;
    
    close_file(keyfile2);
}

/**
 * # # # Funzioni file # # #
 */

FILE *open_input_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL)
        perror("Errore apertura file input.");
    return file;
}

FILE *open_output_file(char *name) {
    FILE *file = fopen(name, "w");
    if (file == NULL)
        perror("Errore apertura file output.");
    return file;
}

void close_file(FILE *file) {
    if (file != NULL) {
        fclose(file);
    }
}

/**
 * # # # Funzioni di utilita' # # #
 */

int euc_mod(int val1, int val2) {
    if (val2 == 0)
        return 0;

    int result = val1 % val2;

    if (result < 0)
        result += val2;

    return result;
}

lklist *fill_list(lklist *head, int max) {
    for (int i = 0; i < max; ++i) {
        head = add_node(head, i);
    }
    return head;
}

/*lklist *perm_list(lklist *head1, lklist *head2) {

}*/

/**
 * # # # Funzioni Linked List # # #
 */

lklist *add_node(lklist *head, byte value) {
    if (head == NULL)
        return newNode(value);
    else
        head->next = add_node(head->next, value);
    return head;
}

lklist *remove_node(lklist *head, int index) {

    if (index == 0)
        return remove_head(head);

    lklist *tmp, *iterator = head;

    while (index != 1) {
        iterator = iterator->next;
        index--;
    }

    tmp = iterator->next->next;
    free(iterator->next);
    iterator->next = tmp;
    return head;
}

byte get_node(lklist *head, int index) {
    lklist *iterator = head;
    while (index != 0) {
        iterator = iterator->next;
        index--;
    }
    return iterator->value;
}

lklist *delete_list(lklist *head) {
    if (head != NULL) {
        delete_list(head->next);
        free(head);
    }
    return NULL;
}

void print_list(lklist *head) {
    if (head != NULL) {
        printf("%d -> ", head->value);
        print_list(head->next);
    } else
        printf("NULL\n\n");
}

int countNodes(lklist *head) {
    if (head == NULL)
        return 0;
    else
        return 1 + countNodes(head->next);
}

lklist *newNode(int value) {
    lklist *node = (lklist *) malloc(sizeof(lklist));
    node->value = value;
    node->next = NULL;
    return node;
}

lklist *remove_head(lklist *head) {
    lklist *tmp;
    tmp = head->next;
    free(head);
    return tmp;
}