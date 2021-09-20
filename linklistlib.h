//
// Created by Lorenzo Cardinali on 20/09/2021.
//

#ifndef LORENZOCARDINALI105789_LINKLISTLIB_H
#define LORENZOCARDINALI105789_LINKLISTLIB_H

#include "bytelib.h"

/**
 * Definizione truttura dati nodo della linked list.
 */
typedef struct node {
    byte value;
    struct node *next;
} lklist;

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

#endif //LORENZOCARDINALI105789_LINKLISTLIB_H
