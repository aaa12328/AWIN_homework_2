#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int val[]={135,139,149,150,156,163,173,184,192,201,210,214,221,229,240};//物品價值 
	int wt[]= { 70, 73, 77, 80 ,82, 87, 90, 94, 98,106,110,113,115,118,120};//物品重量 
	int maxw=750;//背包最大重量 
	int guess_times=500;//猜測次數 
	int n[15]={0};//儲存改變前的陣列 
	int random[15]={0};//儲存改變後的陣列 
	int best[15]={0};//儲存最優解陣列 
	int w=0,p=0,times=1,bestval=0,bestw=0,besttimes=0;
	srand( time(NULL) );
	printf("第 1次隨機拿取的物品有：");
	for(int i=0;i<15;i++)
	{
		random[i]=rand() % (1 - 0 + 1) + 0;
	}
	for(int j=0;j<15;j++)
	{
		printf("%d,",random[j]);
		if(random[j]==1)
		{
			p+=val[j];
			w+=wt[j];
		}
	}
	printf("\b  第   1次拿取的價值與重量為 : %4d,%4d\n",p,w);
	while(times<=guess_times-1)
	{
		if(w>maxw)
		{
			int r= rand() % (15 - 0 + 1) + 0;
			p=0;w=0;
			if(random[r]==1)
			{ 
				printf("\n放棄拿取第 %3d 樣物品：",r);
				random[r]=0;
			} 
			else
				continue;
			for(int j=0;j<15;j++)
			{
				printf("%d,",random[j]);
				if(random[j]==1)
				{
					p+=val[j];
					w+=wt[j];
				}
			}
			printf("\b  第 %3d 次拿取的價值、重量與目前最佳價值為 : %4d,%4d",times+1,p,w);
		}
		else if(w<=maxw)
		{
			int r= rand() % (15 - 0 + 1) + 0;
			p=0;w=0;
			for(int k=0;k<15;k++)
			{
				n[k]=random[k];
			}
			if(random[r]==0)
			{ 
				printf("\n選擇拿取第 %3d 樣物品：",r);
				random[r]=1;
			} 
			else
				continue;
			for(int j=0;j<15;j++)
			{
				printf("%d,",random[j]);
				if(random[j]==1)
				{
					p+=val[j];
					w+=wt[j];
				}
			}
			printf("\b  第 %3d 次拿取的價值、重量與目前最佳價值為 : %4d,%4d",times+1,p,w);	
			if(p>bestval && w<=maxw)
			{ 
				for(int k=0;k<15;k++)
				{
					best[k]=n[k];
				}
				besttimes=times;
				bestval=p;	
				bestw=w;
			} 
		}
		printf(",%4d\n",bestval);
		times++;
	}
	printf("\n\n最佳為第%d次的：%d ,%d ,拿取物品為：",besttimes,bestval,bestw);
	for(int k=0;k<15;k++)
	{
		printf("%d ",best[k]);
	}
	return 0;
}
