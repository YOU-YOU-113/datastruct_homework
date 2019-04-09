#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

void input(SqList L);
void minprice(int s,int e,SqList L);

int main(){
	int startpart;
	int endpart;
	int i,j,k;
	int midpart[9];
	int midcount=0;
	int plan; 
	SqList list;
	list.G=(Gragh*)malloc(100*sizeof(Gragh));//动态分配预定义大小数组空间
	printf("欢迎您使用旅游路线查询系统！\n\n");
	printf("以下是我们设定的11个城市对应的数字:\n");
	printf("0.北京  1.上海  2.天津  3.重庆  4.广州  5.南京  6.西安  7.成都  8.武汉  9.哈尔滨  10.沈阳\n\n");

	printf("请按照以上设定输入您的起点（数字）：");
	scanf("%d",&startpart);
	printf("请按照以上设定输入您的终点（数字）：");
	scanf("%d",&endpart);
	printf("您是否要规定途径城市？如果是，请键入1；否则键入2。\n");
	scanf("%d",&i);
	if(i==1){
		printf("请输入您的途经城市个数：\n");
		scanf("%d",&midcount);
		printf("请按顺序输入您的途经城市编号：\n");
		for(k=0;k<midcount;k++){
			scanf("%d",&midpart[k]);
		}	
	}
	printf("请选择您的旅行策略：(最少费用策略请键入1，最少时间策略请键入2，在规定时间内所需费用最少请键入3)\n");
    scanf("%d",&plan);
    input(list);
	if(plan==1){//最少费用策略 
		if(midcount==0)
			minprice(startpart,endpart,list);
//		else
	}	 
	return 0;
}
