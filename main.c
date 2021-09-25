#include <stdio.h>
#include <string.h>
#include "adfgvx.h"

int main(int argc, char *argv[]) {

    if (strcmp(argv[1], "help") == 0) {

        printf("Usage: \t"
               "adfgvx encode keyfile inputfile outputfile\n\t"
               "adfgvx decode keyfile inputfile outputfile\n\t"
               "adfgvx genkey keyfile s1 k1 s2 k2 s3 k3\n");

    } else if (argc == 5 && strcmp(argv[1], "encode") == 0) {

        encode(argv[2], argv[3], argv[4]);
        printf("File '%s' criptato con successo usando la chiave '%s'!\n", argv[3], argv[2]);

    } else if (argc == 5 && strcmp(argv[1], "decode") == 0) {

        decode(argv[2], argv[3], argv[4]);
        printf("File '%s' decriptato con successo usando la chiave '%s'!\n", argv[3], argv[2]);

    } else if (argc == 9 && strcmp(argv[1], "genkey") == 0) {

        genkey(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
        printf("Chiave '%s' creata con successo!\n", argv[2]);

    } else {
        perror("Errore inserimento argomenti\n"
               "Utilizzare il comando 'adfgvx help' per aiuto\n");
        return 1;
    }
    return 0;
}