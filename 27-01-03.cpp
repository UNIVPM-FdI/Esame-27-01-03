/*Prova Scritta 27/01/03


Scrivere un programma per gestire una “to-do list” organizzata come una lista di strutture in cui si inserisce in maniera ordinata e si estrae dalla testa. Le strutture hanno quindi due campi informazione: il primo è un vettore di caratteri ed il secondo è un intero rappresentante la priorità di quel compito da svolgere.

Il programma principale deve produrre un output del tipo indicato qui di seguito 
[root@ hostname]# ./a.out 
i: immettere, e: estrarre, x: uscire 
i (invio) 
7 preparareProvaScritta 
i (invio) 
6 relazionareConvegno 
i (invio) 
8 scrivereArticolo 
e (invio) 
devi relazionareConvegno prior 6 
e (invio) 
devi preparareProvaScritta prior 7 
e (invio) 
devi scrivereArticolo prior 8 
e (invio) 
nessun compito da svolgere 
a (invio) 
[root@hostname]# */
#include <iostream>
struct da_fare
{ 
int prior;
char compito[20];
 da_fare* succ;
};

typedef da_fare* lista;
using namespace std;

void insordinato(lista& inizio,da_fare a)
{
	lista p,q,d;
	for (q=inizio;q!=0 && q->prior < a.prior;q=q->succ) p=q;
	d=new da_fare;
	*d=a;
	d->succ=q;
	if (q==inizio) inizio=d;
	else p->succ=d;
}
bool estraitesta(lista& inizio, da_fare& a)
{
	lista p=inizio;
	if (p==0) return false;
	a=*p;
	inizio=p->succ;
	delete p;
	return true;
}
int main()
{
char c;
lista p=0;
da_fare a;
	do 
	{
	cout << "i: immettere, e: estrarre, x: uscire" << endl;
	cin >> c;	
switch (c)
{
	case 'i':{
	cin >> a.prior >> a.compito;
	insordinato(p,a);
	}break;
	case 'e':{
		estraitesta(p,a);
		cout << a.compito << " priorita' " << a.prior << endl;
	}break;
	case 'x':{}break;
	default : cout << "non consentito" << endl;
}
}
while (c!= 'x');
}
