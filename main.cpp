#include "link.h"
#include <stdio.h>
#include <stdlib.h>
STU stu;

void menu()
{ 
	
	int flag;
	while (1)
	{
		printf("\t\t************ 请选择你的操作：**************\n");
		printf("\t\t1.插入学生信息\t\t");
		printf("2.浏览所有学生信息\n");
		printf("\t\t3.通过学号查询信息\t");
		printf("4.通过姓名查询信息\n");
		printf("\t\t5.通过联系方式查询信息\t");
		printf("6.更新学生信息\n");
		printf("\t\t7.通过学号删除\t\t");
		printf("8.通过姓名删除\n");
		printf("\t\t9.通过班级查询\t\t");
		printf("10.录入学生成绩\n");
		printf("\t\t11.修改学生成绩\t\t");
		printf("12.查看学生成绩(单个)\n");
		printf("\t\t13.查看学生所有成绩\t");
		printf("14.输出总成绩最高的学生的成绩\n");
		printf("\t\t15.输出前三名学生的成绩\t");
		printf("16.退出\n");
		
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
		case 13:
			Search_All_Score();
			break;
		case 14:
			Output_High_Score();
			break;
		case 15:
			Output_Top_Three();
			break;
		case 16:
			Save_In_File();
			exit(0);
			break;

		}

	}
	
}



int main()
{
	
	printf("\t\t\t*************************\n");
	printf("\t\t\t欢迎来到学生信息管理系统!\n");
	printf("\t\t\t*************************\n");
	Import();
	Import_Score();
	//stu.len = 0;
	menu();
	
}

