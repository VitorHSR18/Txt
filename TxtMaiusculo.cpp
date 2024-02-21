#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
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
void ArquivoTxtMaiusculoString(char NomeArq[50])
{
	FILE * PtrTxt = fopen(NomeArq,"r");
	FILE * PtrMaisc = fopen("Maisc.txt","a");
	char linha[100];
	fgets(linha,100,PtrTxt);
	while(!feof(PtrTxt))
	{
		strupr(linha);
		fputs(linha,PtrMaisc);
		fgets(linha,100,PtrMaisc);
	}
	fclose(PtrTxt);
	fclose(PtrMaisc);
}
void ArquivoTxtMaiusculo(char NomeArquivo[60] , char NomeArquivoC[60])
{
	char copia;
	FILE * PtrTxt = fopen (NomeArquivo,"r");
	FILE * Ptr = fopen (NomeArquivoC,"a");
	
	if(PtrTxt == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		strcpy(NomeArquivoC,NomeArquivo);
		char lido;
		fgetc(lido);
		while(!feof(PtrTxt))
		{
			toupper(lido);
			fputc(lido,PtrTxt);
			
			strcpy(NomeArquivoC,NomeArquivo);
			fgetc(lido);
		}
		
	}
	fclose(PtrTxt);
	fclose(Ptr);
}

int main (void)
{
	char ArquivoTxt[60];
	char ArquivoCopia[60];
	printf("Digite o nome do arquivo: ");
	gets(ArquivoTxt);
	GravarTxtString(ArquivoTxt);
	
	printf("Digite o nome do arquivo copia: ");
	gets(ArquivoCopia);
	ArquivoTxtMaiusculo(ArquivoTxt,ArquivoCopia);
}
