#define MAXPILHA 10

struct TpPilha1
{
	int TOPO;
	char PILHA[MAXPILHA];
};

/* Inicialização da estrutura
	Insere na pilha; (PUSH)
	Retira da pilha; (POP)
	Retornar elemento do TOPO;
	Verifica se PILHA cheia;
	Verifica se Pilha Vazia;
	Exibe a pilha;
*/

void Inicializar(TpPilha P)
{
	P.TOPO = -1; // Sempre precisamos inicializar uma pilha	
}

void Push(TpPilha &P,char Elemento)
{
	P.PILHA[++P.TOPO] = Elemento; // incrementa o topo devido a inicialização -1
}

char Pop(TpPilha &P)
{
	return P.PILHA[P.TOPO--];
}

char ElementoTopo(TpPilha &P)
{
	return P.PILHA[P.TOPO];
}

void Exibir(TpPilha P)
{
		while (!Vazia(P.TOPO))
			printf("\n%c",Pop(P));
}

int Vazia (int topo)
{
	if(topo == -1)
		return 1;
	else
		return 0;
}

int Cheia(int topo)
{
	if(topo == MAXPILHA-1)
		return 1;
	else
		return -1;
}
