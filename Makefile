# makefile per Cifrario ADFGVX - Settembre 2021 - By Lorenzo Cardinali

all: main.c adfgvx.c filelib.c linklistlib.c
	gcc main.c adfgvx.c filelib.c linklistlib.c -o adfgvx

clean:
	rm -f *.exe