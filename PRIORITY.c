#include<stdio.h>
#include<stdlib.h>
struct test
{		flag=1;
			}
		}
	}
	if(flag==1)
	{
		printf("block not found for the process=%d",np);
	}
	printf("process number\t | process size\t | block number\t\n");
	for(i=1;i<=np;i++)
	{
		printf("%d\n",i+1);
		if(i+1>=np)
		{
		  printf("\t");
	    }
		printf("%d\n",process_size[i+1]);
		if(process_size[i+1]>=np)
		{
			printf("\t");
		}
		printf("%d\n",alloc_process[i+1]);
	}
	float burst_time;
	float priority;
	float waiting_time;
}p[10];
int main()
{
	int n,i,j,temp;
	float avg=0;
	float a[10];
	float avg_waiting_time;
	printf("enter number of processes\n");
	scanf("%d",&n);
	printf("enter burst time and priority of each processes\n");
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&p[i].burst_time,&p[i].priority);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].priority>p[j+1].priority)
			{
				temp=p[j].burst_time;
				p[j].burst_time=p[j+1].burst_time;
				p[j+1].burst_time=temp;
			}
		}
	}
	while(p
