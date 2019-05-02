#include "link.h"
#include <stdio.h>
#include <stdlib.h>
STU stu;
void menu()
{
	printf("\t\t\t*************************\n");
	printf("\t\t\t欢迎来到学生信息管理系统!\n");
	printf("\t\t\t*************************\n");
	printf("请选择你的操作：\n");
	printf("\t\t\t1.插入学生信息  ");
	printf("2.查询学生信息\n");
	printf("\t\t\t3.修改学生信息  ");
	printf("4.浏览学生信息\n");
	//printf("\t\t\t5.删除学生信息  ");
	

	int flag;
	scanf("%d", &flag);


	switch (flag)
	{
	
	case 2:
		Import();
		Search_All_Info();
		break;
	}
	
}

int main()
{
	stu.len = 0;
	menu();
}

