//
// Created by Lorenzo Cardinali on 16/09/2021.
//

#ifndef LORENZOCARDINALI105789_ADFGVX_H
#define LORENZOCARDINALI105789_ADFGVX_H

#include "bytelib.h"

/**
 * Definizione truttura dati della chiave di criptazione.
 */
typedef struct struct_key {
    /**
     * Array che definisce una permutazione da 16 elementi (colonne).
     */
    byte C[16];

    /**
     * Array che definisce una permutazione da 16 elementi (righe).
     */
    byte R[16];

    /**
     * Array che definisce una permutazione da 256 elementi (matrice).
     */
    byte K[16][16];
} t_key;

/**
 * Definizione struttura dati che descrive la posizione di un byte.
 */
typedef struct struct_pos {
    /**
     * Byte della posizione.
     */
    byte b;

    /**
     * Numero byte.
     */
    int k;

    /**
     * Posizione byte.
     */
    int i;
    int j;
} t_pos;

/**
 * Codifica un file in input utilizzando una chiave.
 * La codifica viene salvata in un secondo file di output.
 *
 * @param key_file      chiave codifica
 * @param input_file    file di input
 * @param output_file   file di output
 */
void encode(char* key_file, char* input_file, char* output_file);

/**
 * De-Codifica un file in input utilizzando una chiave.
 * La de-codifica viene salvata in un secondo file di output.
 *
 * @param key_file      chiave codifica
 * @param input_file    file di input
 * @param output_file   file di output
 */
void decode(char* key_file, char* input_file, char* output_file);

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
void genkey(char* key_file, char* s1, char* k1, char* s2, char* k2, char* s3, char* k3);

#endif //LORENZOCARDINALI105789_ADFGVX_H