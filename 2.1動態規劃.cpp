#include <stdio.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}

int knapSack(int W,int wt[],int val[],int n)
{
	int i ,w;
	int K[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0||w==0)  
				K[i][w]=0; //當袋子容量為0時 
			else if(wt[i-1]<=w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); //普遍情況 
			else
				K[i][w]=K[i-1][w]; //過重時拿出最後一樣物品 
		}
	}

	return K[n][W];
}

int main ()
{
	int val[]={135,139,149,150,156,163,173,184,192,201,210,214,221,229,240};//價值 
	int wt[]= { 70, 73, 77, 80 ,82, 87, 90, 94, 98,106,110,113,115,118,120};//重量 
	int W=750;//背包限重 
	int n= sizeof(val)/sizeof(val[0]);
	printf("%d",knapSack(W,wt,val,n));
	return 0;
}
