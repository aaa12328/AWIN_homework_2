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
				K[i][w]=0; //��U�l�e�q��0�� 
			else if(wt[i-1]<=w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); //���M���p 
			else
				K[i][w]=K[i-1][w]; //�L���ɮ��X�̫�@�˪��~ 
		}
	}

	return K[n][W];
}

int main ()
{
	int val[]={135,139,149,150,156,163,173,184,192,201,210,214,221,229,240};//���� 
	int wt[]= { 70, 73, 77, 80 ,82, 87, 90, 94, 98,106,110,113,115,118,120};//���q 
	int W=750;//�I�]���� 
	int n= sizeof(val)/sizeof(val[0]);
	printf("%d",knapSack(W,wt,val,n));
	return 0;
}
