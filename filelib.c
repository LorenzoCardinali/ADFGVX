//
// Created by Lorenzo Cardinali on 20/09/2021.
//

#include <stdlib.h>
#include "filelib.h"

FILE *open_input_file(char *name) {
    FILE *file = fopen(name, "rb");
    if (file == NULL) {
        perror("Errore apertura file input\n");
        exit(1);
    }

    return file;
}

FILE *open_output_file(char *name) {
    FILE *file = fopen(name, "wb");
    if (file == NULL) {
        perror("Errore apertura file output\n");
        exit(1);
    }

    return file;
}

void close_file(FILE *file) {
    if (file != NULL)
        fclose(file);
}

size_t file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    size_t file_length = ftell(file);
    rewind(file);
    return file_length;
}