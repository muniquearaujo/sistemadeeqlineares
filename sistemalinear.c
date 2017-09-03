#include<stdio.h>
#define NL 4
#define NC 5
			
FILE *fp;
void zera(int m[NL][NC])
{
	int i,j,k,num;
	
	for(j=0;j<NC;j++)
	{
		for(i=0;i<NL; i++)
		{
			if(i>j)
			{
				num=-(m[i][j]/m[j][j]);
				for(k=0;k<NC;k++)
				{
					m[i][k]=num*m[j][k]+m[i][k];
				}
			}
		}
	}	
	printf("\n\nMatriz Triangular Superior:\n");
	for(i=0;i<NL;i++)
	{
		for(j=0;j<NC;j++)
		{ 
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}	
	
}

//Função para fazer a substituição reversa

void solucao(int m[NL][NC])
{
	int x[NL], i,j,soma=0;

	x[NL-1]=m[NL-1][NC-1]/m[NL-1][NC-2];
	
	for(i=NL-2;i>=0;i--)
	{
		soma=0;
		for(j=i+1;j<NL;j++)
		{
			soma=soma+m[i][j]*x[j];
		}
		x[i]=(m[i][NL]-soma)/m[i][i];
	}
	
	//Impressão dos valores na tela
	printf("\nA solução do sistema será:\n");
	for(i=0;i<4;i++)
	{
		printf("x%d",i+1);
		printf(":%d\n", x[i]);
	}
	
}	
main()
{
	int m[NL][NC], i, j,k, num, t;
	
	//Abrindo arquivo para escrita
	fp=fopen("matriz.dat", "r"); 
	
	printf("\nMatriz:\n");
	
	for(i=0;i<NL;i++)
	{
		for(j=0;j<NC;j++)
		{
			fscanf(fp, "%d", &m[i][j]); //lendo "scanf" cada um do arquivo e passado para novas variaveis 
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	//chamando a função
	zera(m);
	
	//chamando a função
	solucao(m);
}
