# LAB 05

## Esercizio 1 (15/01/2019)
### Albero di Natale incorniciato
Scrivere un programma che legga da `cin` un valore intero `h` che rappresenta l'altezza di un albero di natale. Per valori di `h < 4`, il programma deve stampare `Altezza non valida` e, altrimenti, stamperà un albero incorniciato secondo gli esempi forniti di seguito.


**Esempio 1**
```
(h = 4):
xxx*xxx
x *** x
x*****x
xxx*xxx 
```
**Esempio 2**
```
(h = 6):
xxxxx*xxxxx
x   ***   x
x  *****  x
x ******* x
x*********x
xxxxx*xxxxx 
```
Si osservi che la punta dell’albero è nella prima riga e il tronco nell’ultima riga. 

## Esercizio 2 (15/01/2019)
### Esercizio 2
Si chiede di leggere interi da `cin` e calcolare la loro somma finché non si incontra la sentinella costituita da due `-1` consecutivi. La sentinella non viene contata nel calcolo della somma. La `PRE` e la `POST` del programma richiesto sono le seguenti: 
* `PRE` = (`cin` contiene `-1``-1` consecutivi)
* `POST` = (il programma calcola la somma dei valori che precedono la sentinella `-1``-1`)


## Esercizio 3 (15/01/2019)
### Esercizio 3
Si tratta di leggere interi da `cin` e sommarli finché non si legge la sentinella `-1` (che non entra nella somma) oppure finché non si leggono 10 valori. Il programma da fare deve soddisfare le seguenti `PRE` e `POST`: 
`PRE` = (`cin` contiene almeno 10 valori o altrimenti contiene `-1`) 
`POST` = (se i primi 10 valori letti non contengono `-1`, restituisce la loro somma, se invece entro le prime 10 letture c’è la sentinella `-1`, restituisce la somma dei valori che precedono la sentinella.

Possibili contenuti di `cin` che soddisfano la `PRE` sono i seguenti e per ciascun input si specifica il relativo output.
**Esempio 1**
```
-1       -> somma= 0 
```
**Esempio 2**
```
0  3 -2 -10 -1    -> somma= -9  
```
**Esempio 3**
```
1 1 1 1 1 1 1 1 1 1      -> somma= 10 
```