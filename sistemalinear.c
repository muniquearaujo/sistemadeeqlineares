#include<stdio.h>
#include<stdlib.h>
			
FILE *fp;

//Função Imprime
void imprime(double **M, int dim)
{
	int i,j;
	for(i=0;i<dim;i++)
	{
		for(j=0;j<(dim+1);j++)
		{
			printf("%lf\t", M[i][j]);
		}
		printf("\n");
	}
}
//Função Pivoteamento
int pivot(double **M, int dim)
{
	int i,j,k,aux,t=0;
	
	for(j=0;j<(dim+1);j++)				
	{
		for(i=j;i<dim;i++)
		{
			if(M[i][i]<M[i][j])
			{
				for(k=0;k<(dim+1);k++)
				{
					aux=M[i][k];
					M[i][k]=M[j][k];
					M[j][k]=aux;
				}
				t++;
				i++;
			}
		}
	}			
			
	printf("\n\nMatriz com Pivoteamento:\n");
	imprime(M,dim);
	return(t);
}

//Função de Triangularização
void zera(double **M, int dim)
{
	int i,j,k;
	double num;
	
	for(j=0;j<(dim+1);j++)
	{
		for(i=0;i<dim; i++)
		{
			if(i>j)
			{
				num=-(M[i][j]/M[j][j]);
				for(k=0;k<(dim+1);k++)
				{
					M[i][k]=num*M[j][k]+M[i][k];
				}
			}
		}
	}	
	printf("\n\nMatriz Triangular Superior:\n");
	imprime(M,dim);	
	
}

//Função para fazer a substituição reversa

void solucao(double **M, int dim)
{
	double x[dim], soma=0.0;
	int i,j;

	x[dim-1]=M[dim-1][(dim+1)-1]/M[dim-1][(dim+1)-2];
	
	for(i=dim-2;i>=0;i--)
	{
		soma=0;
		for(j=i+1;j<dim;j++)
		{
			soma=soma+M[i][j]*x[j];
		}
		x[i]=(M[i][dim]-soma)/M[i][i];
	}
	
	//Impressão dos valores na tela
	printf("\nA solução do sistema será:\n");
	for(i=0;i<dim;i++)
	{
		printf("x%d",i+1);
		printf(":%lf\n", x[i]);
	}
	
}

//Função para o cálculo do Determinante
void determinante(double **M, int dim, int n)
{
	double v,prod=1.0, soma=0.0;
	int i,j;
	for(i=0;i<dim;i++)
	{
		for(j=0;j<(dim+1);j++)
		{
			if(i==j)
			{
				//se número de troca positivo
				if(n%2==0)
				{
					v=M[i][j];
					prod=prod*v;
				}
				//se número de troca negativo
				else
				{
					v=-M[i][j];
					prod=prod*v;
				}
			}
		}
	}
	printf("\nO Valor de Determinante é:%lf\n", prod);
}
				
main()
{
	int i, j,k, num, t, dim;
	double **M,a;
	
	//Abrindo arquivo para escrita
	fp=fopen("matriz.dat", "r"); 
	
	i=fscanf(fp, "%d", &dim);
	
	M=malloc(dim*sizeof(double*));
	
	for(i=0;i<dim;i++)
	{
		M[i]=malloc((dim+1)*sizeof(double));
	}	
	i=j=0;
	while(fscanf(fp,"%lf", &a)!=EOF)
	{
		M[i][j]=a;
		j++;
		if(j==dim+1)
		{
			j=0;
			i++;
		}
	}
	fclose(fp);
	
	printf("\nImpressão da Matriz:\n");
	//chamando a função
	imprime(M,dim);
	
	//chamando a função
	t=pivot(M,dim);
	printf("\nNúmero de trocas:%d\n\n", t);
	
	//chamando a função
	zera(M,dim);
	
	//chamando a função
	solucao(M, dim);
	
	//chamando a função
	determinante(M, dim, t);
}
