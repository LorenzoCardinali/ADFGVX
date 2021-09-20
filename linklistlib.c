//
// Created by Lorenzo Cardinali on 20/09/2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "linklistlib.h"

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

/**
 * # # # Funzioni di utilita' # # #
 */

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