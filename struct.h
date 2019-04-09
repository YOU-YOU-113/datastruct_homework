/*交通工具信息结构体*/ 
typedef struct{
	int price;
	char no[10]; 
}elem;

/*交通工具表结构体*/ 
typedef struct{
	elem elem[5];
}datatype;

/*图的结构体*/
typedef struct{
	datatype trans[11][11];//交通工具信息
	char vex[11][5];
}Gragh;


/*顺式表*/ 
typedef struct{
	Gragh *G;		//指向数据元素的指针
	int length;		//顺序表当前长度，即图的个数 
}SqList;
