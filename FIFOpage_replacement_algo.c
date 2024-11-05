#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m[10],rs[25],i,k,j,n,f,pf=0,ph=0;
	printf("enter length of reference string\n");
	scanf("%d",&n);
	printf("enter reference string\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter no of frames\n");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		m[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[j]==-1)
			{
				m[j]=rs[i];
				pf++;
				break;
			}
			else if(m[j]!=-1)
			{
				for(j=0;j<f;j++)
				{
					if(m[j]==rs[i])
					{
						ph++;
					}
					
				}
			}
			else
			{
				for(j=0;j<f;j++)
				{
					if(m[j]!=rs[i])
					{
						m[j]=rs[i];
						pf++;
					}
				}
			}
		}
	}
			
	printf("no of page fault=%d\n",pf);
	printf("no of page hit=%d\n",ph);
}
	

