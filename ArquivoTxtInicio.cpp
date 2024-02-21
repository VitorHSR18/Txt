#include <stdio.h>
#include <string.h>
#include <conio2.h>

void GravarTxtString(char NomeArq[50]){

	FILE * PtrTxt = fopen (NomeArq,"a");	
	char linha[100];
	printf("\n Digite o texto desejado:\n");
	fflush(stdin);
	gets(linha);
	while(stricmp(linha,"\0")!= 0)
	{
		fputs(linha,PtrTxt);
		fputc('\n',PtrTxt);
		fflush(stdin);
		gets(linha);
	}
	
	fclose(PtrTxt);
}
 void ExibeTxtString(char NomeArq[60]){
	
	char linha[100];
	FILE * PtrTxt = fopen (NomeArq,"r");
	if(PtrTxt == NULL)
		printf("Erro de abertura");
	else
	{
		fgets(linha,100,PtrTxt); // string , tamanho , ponteiro
		while (!feof(PtrTxt))
		{
			printf("%s",linha);
			fgets(linha,100,PtrTxt); // string , tamanho , ponteiro
		}
	}
	getch();
	fclose(PtrTxt);
}

void GravaTxtChar(char NomeArq[60])
{
	char lido;
	FILE * PtrTxt = fopen (NomeArq,"a");
	printf("\n Digite o texto desejado:\n");
	lido = getche();
	while (lido != 27)//ESC
	{
		if(lido == 13)//ENTER
		{
			printf("\n");
			fputc('\n',PtrTxt);
		}
		else
			fputc(lido,PtrTxt);

		printf("\n Digite o texto desejado:\n");
		lido = getche();
	}
	fclose(PtrTxt);
}

// fgetc apenas le
void ExibeTxtChar(char NomeArq[60]){
	char lido;
	FILE * PtrTxt = fopen ("Texto.txt","r");  
	lido = fgetc(PtrTxt);
	while(!feof(PtrTxt))
	{
	 	printf("");
		lido = fgetc(PtrTxt);	
	}	
}


int main(void)
{
  char ArquivoString[60],Arquivo[60];
  printf("Digite o nome do arquivo:");
  gets(ArquivoString); // Nome do arquivo
  GravarTxtString(ArquivoString); // vai passar o nome do arquivo
  ExibeTxtString(ArquivoString);
  // GRAVAR E EXIBIR EM CHAR
  //gets(Arquivo);
  //GravaTxtChar(Arquivo);
  //ExibeTxtChar(Arquivo);
  return 0;
}
