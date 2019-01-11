# LAB 03

## Esercizio 1 (08/01/2019)
### Albero di Natale
Scrivere un programma che legga da `cin` un valore intero `n` che rappresenta l'altezza di un albero di Natale. Per valori di `n < 3`, il programma deve stampare `Altezza non valida`, altrimenti stamperà un albero secondo gli esempi forniti di seguito.


**Esempio 1**
```
(n = 3):
 *
***
 *
```
**Esempio 2**
```
(n = 4):
  *
 ***
*****
  *
```
**Esempio 3**
```
(n = 5):
   *
  ***
 *****
*******
   *
```

## Esercizio 2 (08/01/2019)
### Albero di Natale rovesciato
Scrivere un programma che legga da `cin` un valore intero `n` che rappresenta l'altezza di un albero di Natale. Per valori di `n < 3`, il programma deve stampare `Altezza non valida`, altrimenti stamperà un albero secondo gli esempi forniti di seguito.

**Esempio 1**
```
(n = 3):
 *
***
 *
```
**Esempio 2** 
```
(n = 4):
  *
*****
 ***
  *
```
**Esempio 3**
```
   *
*******
 *****
  ***
   *
```


## Esercizio 3 (08/01/2019)
### Diagonale di un Quadrato
Scrivere un programma che legga da cin 4 interi `x1`, `y1`, `x2`, `y2` che rappresentano le coordinate sul piano cartesiano `Oxy` di due punti: `P(x1,y1)` e `Q(x2,y2)`. I due punti `P` e `Q` devono rappresentare gli estremi di una diagonale di un quadrato; in altre parole, deve valere la seguente proprietà: `|x2−x1| = |y2−y1|`. Qualora questa proprietà non venisse soddisfatta, il programma deve stampare a video `Le coordinate immesse non formano la diagonale di un quadrato`. Altrimenti, stamperà il segmento che unisce i punti `P` e `Q` (ossia la diagonale del quadrato), utilizzando il carattere `*` come mostrato negli esempi di seguito

**Esempio 1**
```
P=(x1 = 1, y1 = 2) Q=(x2 = 6, y2 = 7):
    *
   *
  *
 *
*
```
**Esempio 2**
```
P=(x1 = 1, y1 = 2) Q=(x2 = 6, y2 = -3):
*
 *
  *
   *
    *
```
**Esempio 3**
```
P=(x1 = 1, y1 = 2) Q=(x2 = 0, y2 = 4):
Le coordinate immesse non formano la diagonale di un quadrato
```