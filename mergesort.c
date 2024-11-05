#include<stdio.h>
#include<stdlib.h>
int low,mid,high,x,y,i=0,n,k,a[20],b[20];
int merge(int low,int mid,int high)
{
	x=low;
	y=mid+1;
	while((x<=mid) &&(y<=high))
	{
		if(a[x]<=a[y])
		{
			b[i]=a[x];
			x++;
		}
		else
		{
			b[i]=a[y];
			y++;
		}
		i++;
	}
	if(x<=mid)
	{
		for (k=x;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	if(y<=high)
	{
		for(k=y;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	for(k=0;k<high;k++)
	{
		a[k]=b[k];
		printf("%d",a[k]);
	}
	return 0;
}
int mergesort(int low,int high)
{
	mid=(low+high)/2;
	mergesort(low,mid);
	mergesort(mid+1,high);
	merge(low,mid,high);
	return 0;
}
int main()
{
	printf("enter size\n");
	scanf("%d",&n);
	printf("enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	low=0;high=n-1;
	
	mergesort(low,high);
}
	
	
