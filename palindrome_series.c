#include<stdio.h>
int dis(int f,int j)
{
	if(f==1)
	{
		printf("%d\t",j);
	}
	return 0;
}
int main()
{
	int n,j,i,f=0;
	printf("enter number:\t");
	scanf("%d",&n);
	printf("prime numbers:\n");
	for(i=2;i<n/2;i++)
	{
		for(j=2;j<n;j++)
		{
			if((j%i!=0)||(i==j))
			{
				if(j==3||j==5||j==7)
				{
					f=1;
					dis(f,j);
				}
				else if(j%3!=0&&j%5!=0&&j%7!=0)
				{
					f=1;
					dis(f,j);
				}
			
		  }
		}
		break;
	}
}
