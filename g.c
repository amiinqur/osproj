#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//SINGLE THREADED GAME OF LIFE


//THIS IS OUR STRUCT PARAMETER
struct args
{
	int app[4][8],i,j,g;
};
//THIS IS OUR THREAD
void* threadSingle(void* input)
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
    }

	FILE *amod = fopen("output.txt","w");
		for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(arr[i][j]==0)
			{
			
				fprintf(amod,".");
			}
			else
			{
			
				fprintf(amod,"*");
			}
		}
		
		fprintf(amod,"\n");	
	}
	fclose(amod);
}
int main(char *file,int gen,int res[4][8])
{
	FILE *amod;
	file="input.txt";
	gen=10;
	amod = fopen(file,"r");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			fscanf(amod,"%d,",&res[i][j]);
		}
	}
	fclose(amod);
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
	Amod->g=gen;
	pthread_create(&tid1,NULL,&threadSingle,(void *)Amod);
	pthread_join(tid1,NULL);
	return 0;
}
