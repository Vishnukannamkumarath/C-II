#include<stdio.h>
void main()
{
	int i,j,min,m[10],count[10],rs[25],flag[25],n,f,pf=0,next=0;
	printf("enter length of rs\n");
	scanf("%d",&n);
	printf("enter rs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
		flag[i]=0;
	}
	printf("enter no of frames\n");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		m[i]=-1;
		count[i]=0;
	}
	printf("page replacement processs---\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				flag[i]=1;
				count[i]=next;
				next++;
			}
		}
		if(flag[i]==0)
		{
			if(i<f)
			{
				m[i]=rs[i];
				count[i]=next;
				next++;
			}
			else
			{
				min=0;
				for(j=0;j<f;j++)
				{
					if(count[min]>count[j])
					{
						min=j;
					}
					m[min]=rs[i];
					count[min]=next;
					next++;
				}
				pf++;
			}}
			for(j=0;j<f;j++)
			{
				printf("%d\t",m[j]);
			}
			if(flag[i]==0)
			{
				printf("PF=%d\n",pf);
			}
			printf("\n");
		}
		printf("PF=%d\n",pf);
		printf("Ph=%d\n",n-pf);
	}
		
