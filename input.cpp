#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"

void input(SqList L);

void input(SqList L){
	int i,j,k;
	int Spart,Epart;
	int count=1;
	for(i=0;i<11;i++){//��ʼ���ڽӾ��� 
		for(j=0;j<11;j++){
			for(k=0;k<5;k++){
				L.G[0].trans[i][j].elem[k].price=32767;
			}	
		}
	}
	strcpy(L.G[0].vex[0],"����");
	strcpy(L.G[0].vex[1],"�Ϻ�");
	strcpy(L.G[0].vex[2],"���");
	strcpy(L.G[0].vex[3],"����");
	strcpy(L.G[0].vex[4],"����");
	strcpy(L.G[0].vex[5],"�Ͼ�");
	strcpy(L.G[0].vex[6],"����");
	strcpy(L.G[0].vex[7],"�ɶ�");
	strcpy(L.G[0].vex[8],"�人");
	strcpy(L.G[0].vex[9],"������");
	strcpy(L.G[0].vex[10],"����");
	FILE*fp;
	fp=fopen("input.txt","r");
	for(i=0;;i++){
		fscanf(fp,"%d %d",&Spart,&Epart);
		if((Spart==0)&&(Epart==0)) break;
		while(L.G[0].trans[Spart][Epart].elem[count].price!=32767){
			count++;
		} 
		fscanf(fp,"%d",&L.G[0].trans[Spart][Epart].elem[count].price);
		count=1;
	}
	fclose(fp);			
} 




