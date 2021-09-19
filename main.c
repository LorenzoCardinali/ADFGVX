#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "adfgvx.h"

int main(int argc, char *argv[]) {

    genkey("fdsfs",argv[3],argv[4],argv[5],argv[6],argv[7],argv[8]);

    /*lklist *L1 = NULL;

    for (byte i = 0; i <= 15; ++i) {
        printf("%d \n", i);
        L1 = add_node(L1,i);
    }

    print_list(L1);*/

    return 0;
}


/*
    FILE *key, *in, *out;
    int c, x;

    if (argc != 4) {
        fprintf(stderr, "Usage: bvernan keyfile inputfile outputfile\n");
        return 2;
    }
    if ((key = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "bvernan: cannot open key file %s: %s\n", argv[1], strerror(errno));
        return 1;
    }
    if ((x = getc(key)) == EOF) {
        fprintf(stderr, "key file is empty\n");
        return 1;
    }
    if ((in = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "bvernan: cannot open input file %s: %s\n", argv[2], strerror(errno));
        return 1;
    }
    if ((out = fopen(argv[3], "rb")) == NULL) {
        fprintf(stderr, "bvernan: cannot open output file %s: %s\n", argv[3], strerror(errno));
        return 1;
    }
*/