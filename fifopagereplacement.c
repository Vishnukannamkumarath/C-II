#include<stdio.h>
int main()
{
	int i,n,rs[10],nf,ph=0,pf=0,m[10],j;
	printf("enter size of reference string\n");
	scanf("%d",&n);
	printf("enter reference string\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter no of frames\n");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	{
		m[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<nf;j++)
		{
			if(m[j]==-1&&m[j]!=rs[i])
			{
				m[j]=rs[i];
				pf++;
			}
			else if(m[j]!=rs[i])
			{
				pf++;
			}
			else
			{
				ph++;
			}
		}
	}
	printf("no of page fault=%d\n",pf);
	printf("no of page hits=%d\n",ph);
}
			
			
