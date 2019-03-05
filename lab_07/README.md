# LAB 07

## Esercizio 1 (05/03/2019)
### Esercizio 1
Scrivere un programma che legga un intero `N` (`0<N<=100`) e dopo legga `N` interi in un array dichiarato  
`int A [100]; `
Successivamente il programma deve controllare se `A[0..N-1]` è un palindromo.

**Esempio**
Supponiamo che `N = 5` e che `A=[1, 0, 1, 0, 1]`. In questo caso il programma deve stampare `A è un palindromo`, mentre se `N=6` e `A=[0, 1, 0, 1, 1, 0]` il programma deve stampare `A non è palindromo e la prima contraddizione riguarda gli elementi di indice 2 e 3`.

## Esercizio 2 (05/03/2019)
### Esercizio 2
Si tratta di leggere `N` (`0<N<=100`) e poi `N` valori interi in `A`, dichiarato `int A[100]`. Gli `N` valori letti sono tra `0` e `9`. Si chiede di calcolare il numero di occorrenze di ciascun valore `n` in `[0..9]` in `A` e che in funzione di questi valori venga prodotto un istogramma come mostrato nel seguente esempio.

**Esempio**
Sia `N = 10` e `A=[1, 1, 0, 3, 8, 9, 1, 8, 0, 3]`. In `A` sono presenti tre `1`, due `0`, due `3`, due `8`  e un `9`. Quindi sono assenti i `2`, `4`, `5`, `6` e `7`. L'output richiesto sarebbe:  
```
 *
** *    *
** *    **
0123456789
``` 
In cui la prima colonna corrisponde a `0` ed ha quindi due stelle, poi la seconda colonna corrisponde a `1` ed ha tre stelle, poi c'è il `2` che ha zero stelle, il `3` che ne ha 2, poi `4`, `5`, `6` e `7` che ne hanno zero e infine `8` con 2 stelle e `9` con una stella.  

## Esercizio 3 (05/03/2019)
### Esercizio 3
Come negli esercizi precedenti, si legge `N` (`0<N<=100`) e si leggono `N` interi in `A`, `int A[100]`. Si deve assumere che i valori letti siano o `0` o `1`. Potrebbero essere anche tutti `0` o tutti `1`, ma non ci sono altri valori. Si vuole trasformare `A` in modo che tutti i valori `0` vengano spostati nella parte iniziale  di `A` e tutti gli `1` nella parte finale di `A`. È proibito di contare gli `0` e `1` presenti e poi sovrascrivere `A` con il numero giusto di `0` seguito dal numero giusto di `1`. Il risultato deve essere ottenuto scambiando elementi di `A` tra loro.
Consiglio: si cerchi di estendere la soluzione dell'esercizio 2 della settimana scorsa in modo da risolvere questo esercizio che è un'estensione dell'esercizio 2 della settimana scorsa. Si consiglia di riflettere sull'invariante presentato in classe per l'esercizio 2 della scorsa settimana, e si cerchi di estenderlo al nuovo esercizio. Solo dopo aver scritto un invariante chiaro, si proceda alla scrittura di un ciclo che mantenga quell'invariante. 