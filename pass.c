#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int len,lc,st;
	char lbl[20],opc[20],opr[20],co[20],mn[20];
	FILE *f1,*f2,*f3,*f4;
	f1=fopen("donkey.txt","r");
	f2=fopen("monkey.txt","r");
	f3=fopen("cat.txt","w");
	f4=fopen("dog.txt","w");
	fscanf(f1,"%s\t%s\t%s\t\n",lbl,opc,opr);
	if(strcmp(opc,"START")==0)
	{
		st=atoi(opr);
		lc=st;
		fprintf(f4,"\t%s\t%s\t%s\t\n",lbl,opc,opr);
		fscanf(f1,"%s\t%s\t%s\t",lbl,opc,opr);
	}
	else
	{
		lc=0;
	}
	while(strcmp(opc,"END")!=0)
	{
		fprintf(f4,"%d\t",lc);
		if(strcmp(lbl,"**")!=0)
		{
			fprintf(f3,"%s\t%d\t\n",lbl,lc);
		}
		fscanf(f2,"%s\t%s\t\n",co,mn);
		while(strcmp(co,"END")!=0)
		{
			if(strcmp(opc,co)==0)
			{
				lc+=3;
				break;
			}
			fscanf(f2,"%s\t%s\t\n",co,mn);
		}
		if(strcmp(opc,"WORD")==0)
		{
			lc+=3;
		}
		else if(strcmp(opc,"RESW")==0)
		{
			lc+=(3*(atoi(opr)));
		}
		else if(strcmp(opc,"RESB")==0)
		{
			lc+=atoi(opr);
		}
		else if(strcmp(opc,"BYTE")==0)
		{
			lc+=strlen(opr);
		}
		fprintf(f4,"%s\t%s\t%s\t\n",lbl,opc,opr);
		fscanf(f1,"%s\t%s\t%s\t",lbl,opc,opr);
	}
	fprintf(f4,"%s\t%s\t%s\t",lbl,opc,opr);
	len=lc-st;
	printf("length=%d\n",len);
}
