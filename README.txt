Cifrario ADFGVX - Settembre 2021

#Codifica

1. Leggo primo byte da un file (byte b alla posizione k).
2. Cerco il byte nella matrice K e salvo la posizione (i,j).
3. Modifico il byte con la formula C[(i+k)%16] *16 + R[(j+k)%16].
4. Aggiungo nel file di output il byte modificato.

#Decodifica

1. Leggo primo byte da un file (byte b alla posizione k).
2. Divido il byte in 2 nibble (4 bit) v1 e v2.
3. Cerco la posizione di v1 in C (i) e v2 in R (j).
4. Calcolo byte decodificato alla posizione K[(i-k)%16][(j-k)%16].

#Generazione chiave

1. Generare lista L degli elementi da permutare (0-15 per C e R / 0-255 per K).
2. Generare lista vuota L'
3. Assegnare alla variabile c il valore di input s (c = s).
4. Fino a quando L non è vuota:
	a. v = L[c].
	b. Rimuovo v da L.
	c. Aggiungo v alla fine della lista L'.
	d. c = (c+k)%N dove N è il numero degli elementi presenti in L.
5. Salvare su un file:
	a. Sequenza di 8 byte che rappresenta il vettore C.
	b. Sequenza di 8 byte che rappresenta il vettore R.
	c. Sequenza di 256 byte che rappresenta la matrice K.