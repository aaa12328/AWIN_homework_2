#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define T0 1000 //﹍放 
#define TF 0.01 //挡放 
#define T 0.95  //放跑て瞯 
#define N 500
#define M  15 

int weight[M]= {  70, 73, 77, 80, 82, 87, 90, 94, 98,106,110,113,115,118,120},
 	profit[M]= { 135,139,149,150,156,163,173,184,192,201,210,214,221,229,240},
 	contain = 750;

 

int  premaxp = 0, bestmaxp = 0;

int a[M] = {0}, preseq[M] = {0}, bestseq[M]={0},besttime=0;

int calprofit(int a[M])//璸衡基 
{
	int i = 0;
	int p = 0;
	
	for (i = 0; i < M; i++)
	p = p + (a[i] * profit[i]);
	
	return p;
}

int calweight(int a[M])//璸衡秖 
{
	int i = 0;
	int w = 0;
	
	for (i = 0; i < M; i++)
	{
		w = w + (weight[i] * a[i]);
	}
	
	return w;
}

void initialize(void)//﹍て 
{
	int i = 0;
	
	for (i = 0; i < M; i++)
	{
		a[i] = 0;
		preseq[i] = 0;
		bestseq[i] = 0;
	}
	premaxp = calprofit(a);
	bestmaxp = premaxp;
}

void getrand(int *i, int *j)//玻ネ繦诀跑计 
{
	*i = 0;
	*j = 0;
	
	while (*i == *j)
	{
		*i = rand()%M;
		*j = rand()%M;
	}
}

void change(void)//繦诀珇浪琩琌禬筁秖 璝禬玥ぃ 
{
	int r1 = 0, r2 = 0;
	getrand(&r1, &r2);
	
	a[r1] = 1;
	a[r2] = 1;
	
	if (calweight(a) > contain)
	{
		a[r2] = 0;
	}
	if (calweight(a) > contain)
	{
		a[r1] = 0;
	}
}

void SA(void) //秨﹍秈︽家览癶 
{
	double t = T0;
	int i = 0, j = 0;
	int dif1 = 0, dif2 = 0;
	int times=1; 
	double p = 0.0; //﹚诀瞯耕纔秆 
	
	while(t > TF||times>500)
	{
		times++;
	 	for (i = 0; i < N; i++)
	 	{
	 		change();
	 
			dif1 = calprofit(a) - bestmaxp;
			if (dif1 > 0)
		    {
	   			for (j = 0 ; j < M; j++)
	   			{
				    preseq[j] = a[j];
				    bestseq[j] = a[j];
				}
			   premaxp = calprofit(a);
			   bestmaxp = premaxp;
			   besttime=times;
	  		}	
	  		else
			{
				dif2 = calprofit(a) - premaxp;
			    if (dif2 > 0)
			    {
				    for (j = 0; j < M; j++)
				    {
					    preseq[j] = a[j];
				    }
				    premaxp = calprofit(a);
				}
			   else
			   {
				    p = rand()%20001/20000.0;
				    if (exp((dif2)/ t) > p)
				    {
				     	for (j = 0; j < M; j++)
				     	{
				      		preseq[j] = a[j];
				    	}
				    premaxp = calprofit(a);
					}
				    else
				    {
				    	for (j = 0; j < M; j++)
				     	{
				      		a[j] = preseq[j];
				     	}
			    	}
			   }
			}
		}			
		t = t * T; //放 
		printf("ヘ玡程ㄎ基%4d  ヘ玡放%lf\n",bestmaxp,t);
	}

 	printf("\n瞦代%d Ω ,材 %d Ω瞦代程ㄎ秆\n",times,besttime);
}

int main(void)
{
	int i;

	srand((unsigned)time(NULL));
	initialize();
	printf("START...\n");
	SA();
	printf("程ㄎ舱"); 
	for (i = 0; i < 15; i++)
	{
  		if (0 == (i % 5) && i!=0)
		{
   			printf("  ");
		}
  	printf("%d", bestseq[i]);
 	}

	printf("\n程ㄎ基%d\n", bestmaxp);

	return 1;
}
