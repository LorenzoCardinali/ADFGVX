Cifrario ADFGVX - Settembre 2021

## Breve descrizione

L’obiettivo del progetto è sviluppare una semplice applicazione che consenta di cifrare file utilizzando una variante
del Cifrario ADFGVX.

Nel cifrario proposto, la chiave è costituita da tre elementi:

- una permutazione dei valori tra 0 e 255 organizzati in una matrice 16x16 (che chiameremo “matrice di conversione” K)
- una permutazione di valori da 0 a 15 (detta vettore colonne, C)
- una permutazione di valori da 0 a 15 (detta vettore righe, R)

## Codifica - adfgvx encode keyfile inputfile outputfile

1. Leggo primo byte da un file (byte b alla posizione k).
2. Cerco il byte nella matrice K e salvo la posizione (i,j).
3. Modifico il byte con la formula C[(i+k)%16] *16 + R[(j+k)%16].
4. Aggiungo nel file di output il byte modificato.

## Decodifica - adfgvx decode keyfile inputfile outputfile

1. Leggo primo byte da un file (byte b alla posizione k).
2. Divido il byte in 2 nibble (4 bit) v1 e v2.
3. Cerco la posizione di v1 in C (i) e v2 in R (j).
4. Calcolo byte decodificato alla posizione K[(j-k)%16][(i-k)%16].

## Generazione chiave - adfgvx genkey keyfile s1 k1 s2 k2 s3 k3

1. Generare lista L degli elementi da permutare (0-15 per C e R / 0-255 per K).
2. Generare lista vuota L'
3. Assegnare alla variabile c il valore di input s (c = s).
4. Fino a quando L non è vuota:
   a. v = L[c]. b. Rimuovo v da L. c. Aggiungo v alla fine della lista L'. d. c = (c+k)%N dove N è il numero degli
   elementi presenti in L.
5. Salvare su un file:
   a. Sequenza di 8 byte che rappresenta il vettore C. b. Sequenza di 8 byte che rappresenta il vettore R. c. Sequenza
   di 256 byte che rappresenta la matrice K.