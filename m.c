#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
//SINGLE THREADED GAME OF LIFE
double sum=0;
int all[4][8];
int temp[4][8];
//THIS IS OUR STRUCT PARAMETER
struct args
{
	int app[4][8],i,j,g;
};
//THIS IS OUR THREAD
void* threadMulti(void* input)
{
	int i,j,next[4][8],arr[4][8],gen;
	i=((struct args*)input)->i;
	j=((struct args*)input)->j;
	gen=((struct args*)input)->g;
	//THE FOR LOOPS MOVE THE ARRAY DATA FROM MAIN INTO OUR THREAD ARRAY WITH THE HELP OF OUR STRUCT PARAMETER 
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			next[i][j]=((struct args*)input)->app[i][j];
		}
		
	}
	
	
	//ALL THE LOOPS AND IF ELSE CONDITIONS BELOW MANAGE THE GENERATIONS AND EVENTUALLY WRITE THE FINAL STATE INTO OUTOUT FILE
	for(int z=0;z<gen;z++)
	{
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
				all[k][p]=0;
				temp[k][p]=0;
			}
			else if(next[k][p]==1 && Nalive >3)
			{
				all[k][p]=0;
				temp[k][p]=0;
			}
			else if(next[k][p]==0 && Nalive==3)
			{
				all[k][p] = 1;
				temp[k][p]=1;
			}
			else
			{
				all[k][p]=next[k][p];
				temp[k][p]=next[k][p];
			}
		}
	}

    }
}
int main(char *file,int gen,int numth,int res[4][8])
{
	FILE *amod;
	file="input.txt";
	gen=10;
	numth=3;
	amod = fopen(file,"r");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			fscanf(amod,"%d,",&temp[i][j]);
		}
	}
	fclose(amod);
	pthread_t tid1,tid2,tid3;
	struct args *Amod = (struct args *)malloc(sizeof(struct args));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			Amod->app[i][j]=temp[i][j];
		}
		
	}
	Amod->i=4;
	Amod->j=8;
	Amod->g=gen;
	clock_t start = clock();
	pthread_create(&tid1,NULL,&threadMulti,(void *)Amod);
	pthread_create(&tid2,NULL,&threadMulti,(void *)Amod);
	pthread_create(&tid3,NULL,&threadMulti,(void *)Amod);
	pthread_join(tid1,NULL);
	clock_t end = clock();
	double time= (double)(end-start)/CLOCKS_PER_SEC;
	FILE *amo = fopen("outm.txt","w");
	fprintf(amo,"Average Time Taken for each generation: %f\n",time/3);
	fprintf(amo,"Total Time Taken: %f",time);
		for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(all[i][j]==0)
			{
				fprintf(amo,".");
			}
			else
			{
				fprintf(amo,"*");
			}
		}
		fprintf(amo,"\n");	
	}
	fclose(amo);
	return 0;
}
