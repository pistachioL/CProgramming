#include "link.h"
#include <stdio.h>
#include <stdlib.h>
STU stu;

void menu()
{ 
	Import();
	int flag;
	while (1)
	{
		
		printf("\t请选择你的操作：\n");
		printf("\t\t\t1.插入学生信息  ");
		printf("2.浏览所有学生信息\n");
		printf("\t\t\t3.通过学号查询信息  ");
		printf("4.通过姓名查询信息\n");
		printf("\t\t\t5.通过联系方式查询信息  ");
		printf("6.更新学生信息\n");
		printf("\t\t\t7.通过学号删除  ");
		printf("8.通过姓名删除\n");
		printf("\t\t\t9.通过班级查询");
		printf("10.录入学生成绩\n");
		printf("\t\t\t11.修改学生成绩");
		printf("12.查看学生成绩\n");
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			Insert();
			break;
		case 2:
			Search_All_Info();
			break;
		case 3:
			Search_By_Sno();
			break;
		case 4:
			Search_By_Sname();
			break;
		case 5:
			Search_By_Phone();
			break;
		case 6:
			Update();
			break;
		case 7:
			Delete_By_Sno();
			break;
		case 8:
			Delete_By_Name();
			break;
		case 9:
			Search_By_Class();
			break;
		case 10:
			Input_Score();
			break;
		case 11:
			Update_Score();
			break;
		case 12:
			Check_Score();
			break;


		}

	}
	
}



int main()
{
	printf("\t\t\t*************************\n");
	printf("\t\t\t欢迎来到学生信息管理系统!\n");
	printf("\t\t\t*************************\n");

	//stu.len = 0;
	menu();
	
}

