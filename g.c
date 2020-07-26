#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//SINGLE THREADED GAME OF LIFE



struct args
{
	int app[4][8],i,j;
};
void* threadSingle(void* input)
{
	int i,j,next[4][8],arr[4][8];
	i=((struct args*)input)->i;
	j=((struct args*)input)->j;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			next[i][j]=((struct args*)input)->app[i][j];
		}
		
	}
	for(int k=1;k<i-1;k++)
	{
		for(int p=1;p<j-1;p++)
		{
			int Nalive = 0;
			for(int n=-1;n<=1;n++)
			{
				for(int m=-1;m<=1;m++)
				{
					Nalive += next[k+n][p+m];
				}
			}
			Nalive -= next[k][p];
			if(next[k][p] == 1 && Nalive <2)
			{
				arr[k][p]=0;
			}
			else if(next[k][p]==1 && Nalive >3)
			{
				arr[k][p]=0;
			}
			else if(next[k][p]==0 && Nalive==3)
			{
				arr[k][p] = 1;
			}
			else
			{
				arr[k][p]=next[k][p];
			}
		}
	}
	printf("Next Gen\n");
	FILE *amod = fopen("output.txt","w");
		for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(arr[i][j]==0)
			{
				printf(".");
				fprintf(amod,".");
			}
			else
			{
				printf("*");
				fprintf(amod,"*");
			}
		}
		printf("\n");
		fprintf(amod,"\n");	
	}
	fclose(amod);
}
int main(char *file,int gen,int res[4][8])
{
	FILE *amod;
	file="input.txt";
	gen=1;
	amod = fopen(file,"r");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			fscanf(amod,"%d,",&res[i][j]);
		}
		
	}
	fclose(amod);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(res[i][j]==0)
			{
				printf(".");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");	
	}
	pthread_t tid1;
	struct args *Amod = (struct args *)malloc(sizeof(struct args));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			Amod->app[i][j]=res[i][j];
		}
		
	}
	Amod->i=4;
	Amod->j=8;
	pthread_create(&tid1,NULL,&threadSingle,(void *)Amod);
	pthread_join(tid1,NULL);
	return 0;
}
