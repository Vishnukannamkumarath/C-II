#include<stdio.h>
int main()
{
	int m[10],rs[25],i,j,k,n,f,pf=0,ph=0,count=0;
	printf("enter length of rs\n");
	scanf("%d",&n);
	printf("enter rs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter size of frame\n");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		m[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				ph++;
				break;
			}
		}
		if(j==f)
		{
			m[count]=rs[i];
			count++;
			pf++;
		}
		if(j!=f)
		{
			ph++;
		}
		printf("frames\n");
		for(k=0;k<f;k++)
		{
			printf("%d\t",m[i]);
		}
		if(j==f)
		{
			printf("PF=%d",pf);
		}
		if(j!=f)
		{
			printf("PH=%d",ph);
		}
		if(count==f)
		{
			count=0;
		}
	}
	printf("page fault=%d\n",pf);
	printf("PH=%d\n",n-pf);
}
			
