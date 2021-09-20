//
// Created by Lorenzo Cardinali on 20/09/2021.
//

#ifndef LORENZOCARDINALI105789_FILELIB_H
#define LORENZOCARDINALI105789_FILELIB_H

#include <stdio.h>

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
 * Ritorna la dimensione di un file.
 *
 * @param file File da analizzare.
 * @return dimensione di un file.
 */
size_t file_size(FILE *file);

#endif //LORENZOCARDINALI105789_FILELIB_H
