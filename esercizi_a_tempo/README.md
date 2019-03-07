# ESERCIZI A TEMPO

## Esercizio 1 (07/03/2019)
### Esercizio 1
Si tratta di dichiarare due array `int A1[10][5]` e `int A2[10][5]` e di leggere 50 interi in modo da inserire i valori in `A1` per riga e in `A2` per colonna. Per riga si intende che i primi 5 valori dei 50 da leggere devono riempire la prima riga di `A1`, i 5 valori seguenti riempiono la seconda riga e così via per tutte le 10 righe di `A1`. Per colonna invece significa che i primi 10 valori riempiono la prima colonna di `A2`, i seguenti 10 riempiono la seconda colonna e così via per tutte le 5 colonne di `A2`. A questo punto il programma deve stampare prima `A1` e poi `A2`, entrambi per righe.
Successivamente si chiede di dichiarare un array `bool B[10][10]` e di assegnare valori `true`/`false` ad ogni elemento di `B` in modo tale che per ogni elemento `B[i][j]` la seguente condizione sia verificata: 
`B[i][j]=true` sse la riga `i` di `A2` non ha alcun elemento in comune con la riga `j` di `A2`. 
Si osservi che ovviamente, per ogni `i` e `j`, `B[i][j]==B[j][i]`, cioè la matrice è simmetrica rispetto alla diagonale principale. Inoltre la diagonale principale di `B` conterrà tutti valori `false`. 
Per ultimo si chiede di stampare l'array `B` per righe. Si tenga conto che stampare true produce `1` e stampare `false` produce `0`. 
**Correttezza**: Scrivere invarianti per tutti i cicli del programma. Gli invarianti vanno inseriti come commenti prima o dopo il programma. Ricordare che un invariante utile descrive quello che il ciclo ha fatto dopo un qualsiasi numero di iterazioni. 
**Attenzione**: sono predisposti solo 2 test automatici.