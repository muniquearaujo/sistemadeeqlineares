#include<stdio.h>
#define NL 4
#define NC 5
			
FILE *fp;
main()
{
	int m[NL][NC], i, j,k, num, t;
	
	//Abrindo arquivo para escrita
	fp=fopen("matriz.dat", "r"); 
	
	for(i=0;i<NL;i++)
	{
		for(j=0;j<NC;j++)
		{
			fscanf(fp, "%d", &m[i][j]); //lendo "scanf" cada um do arquivo e passado para novas variaveis 
		}
		printf("\n");
	}
}	
