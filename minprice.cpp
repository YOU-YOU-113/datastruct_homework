#include<stdio.h>
#include"struct.h"

void minprice(int c,int m[9],int s,int e,SqList L);

void minprice(int c,int m[9],int s,int e,SqList L){
	int i,j,k,count;
	int price;
	int temp3=0;
	int temp,temp1,temp2;
	int v[11];
	int D[11][11];
	int path[11][11];
	for(i=0;i<11;i++){//��˳���ĵ�һ��Ԫ�ط���Ϊ�۸����ٵ� 
		for(j=0;j<11;j++){
			for(k=1;k<5&&i!=j;k++){
				if(L.G[0].trans[i][j].elem[k].price<L.G[0].trans[i][j].elem[0].price)
					L.G[0].trans[i][j].elem[0]=L.G[0].trans[i][j].elem[k];	
			}
		}
	}
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			D[i][j]=L.G[0].trans[i][j].elem[0].price;
			if(D[i][j]<32767&&i!=j)
				path[i][j]=i;
			else
				path[i][j]=-1;	
		}
	}
	for(k=0;k<11;k++)
		for(i=0;i<11;i++)
			for(j=0;j<11;j++)
				if(D[i][k]+D[k][j]<D[i][j]){
					D[i][j]=D[i][k]+D[k][j];
					path[i][j]=path[k][j];
				}
	if(c==0){ //���û�й涨;������ 
		temp=e;
		count=0;
		do{
			v[count]=temp;
			temp=path[s][v[count]];
			count++;	
		}while(temp!=s);
		count=count-1;
		printf("\nΪ���滮��·��Ϊ��");
		printf("%s ",L.G[0].vex[s]); 
		for(i=count;i>=0;i--){
			printf("%s ",L.G[0].vex[v[i]]);
		}
		printf("\n");
		printf("��С����Ϊ:%dԪ",D[s][e]);			
	}
	else{//����涨��;������ 
		printf("\nΪ���滮��·��Ϊ��");
		printf("%s ",L.G[0].vex[s]); 
		for(j=0;j<=c;j++){
			count=0;
			temp1=m[j];
			temp2=m[j+1];	
			do{
				v[count]=temp2;
				temp2=path[temp1][v[count]];
				count++;	
			}while(temp2!=temp1);
			count=count-1;
			for(i=count;i>=0;i--){
				printf("%s ",L.G[0].vex[v[i]]);
			}
		}
		printf("\n");
		for(k=0;k<=c;k++){
			price=temp3+D[m[k]][m[k+1]];
			temp3=price;
		}
		printf("��С����Ϊ:%dԪ",price);	
	}
}




