#include<stdio.h>
#define NL 4
#define NC 5
			
FILE *fp;
void zera(int m[NL][NC])
{
	int i,j,k,num;
	k=0;
	
	for(j=0;j<NC;j++)
	{
		for(i=0;i<NL; i++)
		{
			if(i>j)
			{
				num=-(m[i][j]/m[j][j]);
				
				m[i][k]=num*m[j][k]+m[i][k];
			}
		}
	}	
	printf("\n\nMatriz com os elementos da primeira coluna zerados, exceto o primeiro:\n");
	for(i=0;i<NL;i++)
	{
		for(j=0;j<NC;j++)
		{ 
			printf("%d\t", m[i][j]);
		}
		printf("\n");
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
	
}
