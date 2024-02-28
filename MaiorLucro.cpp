#include<stdio.h>
#include<conio2.h>
#include <string.h>
 
struct filme{
    char nome[60], classif[6];
    int ano, duracao;
    float gasto,renda,espec;
};
 void MaiorLucro(void)
 {
 	 filme reg;
 	float maior=-9999;
 	char nome[100];
 	FILE *arq = fopen("filmes.txt","r+");
 	
 	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
 	  while(!feof(arq))
    {
          if(maior<reg.renda-reg.gasto)
          {
          		maior = reg.renda - reg.gasto;
          		strcpy(nome,reg.nome);
          }
          	
     
          fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    printf("Nome: %s \n  Lucro: %.2f",nome,maior);
    fclose(arq);
 }
 
int main()
{
    filme reg;
    FILE *arq = fopen("filmes.txt","r");
    MaiorLucro();
     /*
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    while(!feof(arq))
    {
          printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
     
          fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
    fclose(arq);*/
    getch();
    
}
