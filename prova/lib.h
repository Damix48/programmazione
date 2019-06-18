struct nodo{int info; nodo* next;nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct coda{nodo* primo,*ultimo;coda(nodo*a=0){primo=a; ultimo=a;}};
struct nodoE{coda* C; int N, V; nodoE* next; nodoE(coda* a=0, int b=0, int c=0, nodoE*d=0){C=a; N=b; V=c; next=d;}};

void push_end(coda *x, nodo* p);
nodoE* trova(nodoE* R,int y);
void aggiungi(nodoE* E, nodo* n);
nodoE*addLast(nodoE* R, nodoE* X);
nodoE* faitutto(nodo*L,nodoE*ris);