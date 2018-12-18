# LAB 02

## Esercizio 1 (18/12/2018)
### La morra cinese su più mosse
Scrivere un programma che legge un valore intero n > 0 e una sequenza di n coppie di caratteri che rappresentano mosse *legittime* della morra cinese, secondo la codiﬁca vista in precedenza, ossia ogni mossa è identiﬁcata da un `char` e può assumere esclusivamente uno dei seguenti 3 valori:
* `f` codifica la mossa *forbice*
* `c` codifica la mossa *carta*
* `s` codifica la mossa *sasso*

Il programma deve dichiarare quale giocatore ha vinto alla ﬁne della sequenza di n giocate, scrivendo sullo schermo `Vince il Giocatore 1`, oppure `Vince il Giocatore 2`, oppure `Pareggio`.



## Esercizio 2 (11/12/2018)
### Gioco della morra cinese
Scrivere un programma che consenta di giocare alla morra cinese. Il programma deve ricevere in ingresso (`stdin`) le mosse dei due giocatori, ciascuna codiﬁcata con un `char`:
* se il carattere è `f` la mossa del giocatore è forbice
* se il carattere è `c` la mossa del giocatore è carta
* se il carattere è `s` la mossa del giocatore è sasso

Se viene inserita una mossa non valida il programma deve scrivere sullo schermo (`stdout`) `mossa non valida` e terminare l’esecuzione. Se entrambe le mosse sono valide, il programma deve dichiarare il vincitore scrivendo sullo schermo `vince il giocatore 1` oppure `vince il giocatore 2`, oppure `pareggio`.
Si ricordi che:
* forbice vince su carta
* carta vince su sasso
* sasso vince su forbice

**Esempio 1**
```
start
f
c
vince il giocatore 1
end
```
**Esempio 2** 
```
start
s
c
vince il giocatore 2
end
```
**Esempio 3**
```
start
f
f
pareggio
end
```
**Esempio 4** 
```
start
x
c
mossa non valida
end
```


## Esercizio 3 (11/12/2018)
### Triangolo
Scrivere un programma che stabilisca se, data la lunghezza di 3 segmenti, questi possono essere disposti per formare un triangolo.
Il programma deve ricevere in ingresso (`stdin`) 3 lunghezze, ciascuna codiﬁcata con un `int` e controllare che tutte siano strettamente positive, altrimenti stampare il messaggio `Input sbagliato`. Nel caso in cui la condizione di positività sia invece veriﬁcata, il programma stamperà il messaggio `Si` se i segmenti possono essere distribuiti per formare un triangolo, `No` altrimenti.

**Esempio 1**
```
start
0
4
5
Input sbagliato
end
```
**Esempio 2**
```
start
-1
-2
0
Input sbagliato
end
```
**Esempio 3**
```
start
4
3
5
Si
end
```
**Esempio 4**
```
start
1
3
2
No
end
```