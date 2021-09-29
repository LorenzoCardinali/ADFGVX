Sistemi Operativi: Laboratorio Specifica Progetto Settembre 2021

L’obiettivo del progetto è sviluppare una semplice applicazione che consenta di cifrare file utilizzando una variante
del Cifrario ADFGVX. Nel cifrario proposto, la chiave è costituita da tre elementi:

* una permutazione dei valori tra 0 e 255 organizzati in una matrice 16x16 (che chiameremo “matrice di conversione” K);
* una permutazione di valori da 0 a 15 (detta vettore colonne, C)
* una permutazione di valori da 0 a 15 (detta vettore righe, R)

Dato un generico byte b indichiamo con Pos(K,b) la posizione (i,j) del byte b nella matrice K:

Pos(K,b) = (i,j) se e soltanto se K[i][j] = b

Analogamente dato un valore v tra 0 e 15, indichiamo con Pos(C, v) l’indice i tale che C[i]=v. Analogamente, Pos(R, v)
indicherà l’indice j tale che R[j]=v.

La codifica di un file F costituito dai file b0...bN si ottiene rimpiazzando il byte bk , tale che Pos(K,bk)=(i,j) con
il valore

C[(i+k)%16]*16+R[(j+k)%16]

In pratica, determinata la posizione del byte bk nella matrice K, il byte risultante si ottiene concatenando (in formato
binario) i valori in C[(i+k)%16] e R[(j+k)%16].

L’operazione di decodifica è complementare. Per decodificare il byte b’k nella posizione k occorre procedere nel
seguente modo:

1. individuare i valori v1 e v2 tale che b’k=v1*16+v2
2. Individuare i e j tali che Pos(C,v1)=i e Pos(R,v2)=j
3. Calcolare il byte decodificato nella posizione K[(i-k)%16][(j-k)%16]

Formato file della chiave La chiave usata per la codifica e decodifica viene memorizzata in un file la cui struttura è
la seguente:

1. Una sequenza di 8 byte che rappresenta il vettore C (ogni byte rappresenta una coppia di interi ognuno dei quali è
   memorizzati nei primi 4 bit e nei secondi 4 bit);
2. Una sequenza di 8 byte che rappresenta il vettore R (la codifica è analoga a quella del vettore C descritto
   precedentemente);
3. Una sequenza di 256 byte (tutti distinti).

Generazione del file chiave Data una sequenza di N valori, una permutazione può essere generata utilizzando due interi s
e k entrambi minori di N. Lo pseudocodice per la generazione è la seguente:

1. L=[v1,...,vN] una lista di valori;
2. L’=[ ] una lista vuota;
3. c = s;
4. Fino a quando L non è vuota:
    1. v = L[c] //Elemento nella posizione c della lista L
    2. Rimuovi l’elemento nella posizione c della Lista L
    3. L’ = L’::[v] //Aggiungi v alla fine della lista L’
    4. c = (c+k)%N
5. Restituisci L’

Una chiave, quindi, può essere generata usando tre coppie di valori che permettono di calcolare, rispettivamente, le
permutazioni del vettore colonna, del vettore riga e degli elementi della matrice di codifica.

Il Progetto

Sviluppare l’applicazione adfgvx che può essere invocato in uno dei seguenti modi.

Codifica:
adfgvx encode keyfile inputfile outputfile

Codifica il file inputfile usando la chiave keyfile e salvando i risultati nel file outputfile.

Decodifica:
adfgvx decode keyfile inputfile outputfile

Codifica il file inputfile usando la chiave keyfile e salvando i risultati nel file outputfile.

Generazione Chiave:
adfgvx genkey keyfile s1 k1 s2 k2 s3 k3

Viene generata una chiave che sarà salvata nel file keyfile dove:

* (s1, k1) sono usati per generare la permutazione del vettore C
* (s2, k2) sono usati per generare la permutazione del vettore R
* (s3,k3) sono usati per generare la permutazione della matrice K

Modalità di Consegna e Griglia di Valutazione

Il progetto verrà valutato secondo i seguenti parametri:

1. Uso di make o di CMake;
2. Organizzazione del codice e strutture dati utilizzate;
3. Coerenza con le specifiche date;
4. Capacità di gestire file di dimensioni crescenti;
5. Tempi di esecuzione.

Il progetto dovrà essere consegnato in un archivio .zip, .tgz o .tar.gz, contenente la sola cartella
chiamata <Nome><Cognome><Matricola> (ad esempio MariaBianchi098765).

L’uso di formati diversi da quelli consentiti comporterà la NON VALUTAZIONE del progetto.