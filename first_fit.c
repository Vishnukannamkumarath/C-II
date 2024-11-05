#include<stdio.h>
void best_fit(int block[],int n,int m,int process[])
{
	int allocation[10],i,j;
	for(i=0;i<n;i++)
	{
		allocation[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		int best=-1;
		for(j=0;j<m;j++)
		{
			if(block[j]>=process[i])
			{
				if(best==-1||block[j]<process[i])
				{
					best=j;
				}
			}
			if(best!=-1)
			{
				allocation[i]=best;
				block[best]=process[i];
			}
		}
		printf("P.no\t\tP.size\t\tB.no\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t\t%d\t\t",i+1,process[i]);
			if(allocation[i]!=-1)
			{
				printf("%d\n",allocation[i]+1);
			}
			else
			{
				printf("not allocatted\n");
			}
		}
	}
}
int main()
{
	int i,n,m,block[10],process[10];
	printf("enter no of blocks\n");
	scanf("%d",&m);
	printf("enter size of block\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&block[i]);
	}
	printf("enter no of process\n");
	scanf("%d",&n);
	printf("enter process size\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&process[i]);
	}
	best_fit(block,n,m,process);
}
	
