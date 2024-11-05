#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char opcode[10],operand[10],label[10],code[10],mnemonic[10];
	int locctr;
	int start;
	int length;
	FILE *fp1,*fp2,*fp3,*fp4;
	fp1=fopen("input.txt","r");
	fp2=fopen("optab.txt","r");
	fp3=fopen("symtab.txt","w");
	fp4=fopen("out.txt","w");
	fscanf(fp1,"%s\t%s\t%s\t",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start=atoi(operand);
		locctr=start;
		fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);
		fscanf(fp1,"%s\t%s\t%s\t",label,opcode,operand);
	}
	else
	{
		locctr=0;
		while(strcmp(opcode,"END")!=0)
		{
			fprintf(fp4,"%d\t",locctr);
			if(strcmp(label,"**")!=0)
				  fprintf(fp3,"%s\t%d\n",label,locctr);
				fscanf(fp2,"%s\t%s",code,mnemonic);
				
				while(strcmp(code,"END")!=0)
				{
					if(strcmp(opcode,code)==0)
					{
						locctr+=3;
						break;
					}
				}
				if(strcmp(opcode,"WORD")==0)
				locctr+=3;
				else if(strcmp(opcode,"RESW")==0)
				locctr+=(3*(atoi(operand)));
				else if(strcmp(opcode,"RESB")==0)
				locctr+=atoi(operand);
				else if(strcmp(opcode,"BYTE")==0)
				++locctr;
				fprintf(fp4,"%s\t%s\t%s\t\n",label,opcode,operand);
				fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
			}
			fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
			length=locctr-start;
			printf("the length of the code: %d\n",length);
			fclose(fp1);
			fclose(fp3);
			fclose(fp4);
			fclose(fp2);
		}
	}