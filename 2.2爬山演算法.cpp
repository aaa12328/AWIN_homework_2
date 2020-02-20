#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int val[]={135,139,149,150,156,163,173,184,192,201,210,214,221,229,240};//���~���� 
	int wt[]= { 70, 73, 77, 80 ,82, 87, 90, 94, 98,106,110,113,115,118,120};//���~���q 
	int maxw=750;//�I�]�̤j���q 
	int guess_times=500;//�q������ 
	int n[15]={0};//�x�s���ܫe���}�C 
	int random[15]={0};//�x�s���ܫ᪺�}�C 
	int best[15]={0};//�x�s���u�Ѱ}�C 
	int w=0,p=0,times=1,bestval=0,bestw=0,besttimes=0;
	srand( time(NULL) );
	printf("�� 1���H�����������~���G");
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
	printf("\b  ��   1�����������ȻP���q�� : %4d,%4d\n",p,w);
	while(times<=guess_times-1)
	{
		if(w>maxw)
		{
			int r= rand() % (15 - 0 + 1) + 0;
			p=0;w=0;
			if(random[r]==1)
			{ 
				printf("\n��󮳨��� %3d �˪��~�G",r);
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
			printf("\b  �� %3d �����������ȡB���q�P�ثe�̨λ��Ȭ� : %4d,%4d",times+1,p,w);
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
				printf("\n��ܮ����� %3d �˪��~�G",r);
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
			printf("\b  �� %3d �����������ȡB���q�P�ثe�̨λ��Ȭ� : %4d,%4d",times+1,p,w);	
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
	printf("\n\n�̨ά���%d�����G%d ,%d ,�������~���G",besttimes,bestval,bestw);
	for(int k=0;k<15;k++)
	{
		printf("%d ",best[k]);
	}
	return 0;
}
