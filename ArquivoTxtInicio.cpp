#include <stdio.h>
#include <string.h>

void GravaTxtChar(char NomeArq[60])
{
	char lido;
	FILE * PtrTxt = fopen ("NomeArq","a");
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
	 	printf("")
		lido = fgetc(PtrTxt);	
	}	
}


int main(void)
{
  char Arquivo[60];
  GravaTxtChar((Arquivo)"Texto.txt");
  ExibeTxtChar((Arquivo)"Texto.txt");
  return 0;
}
