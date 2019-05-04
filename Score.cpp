#include "link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
using namespace std;
double ConverToDouble(char *a)
{
	double b;
	b = atof(a);
	return b;
}
void Import_Score()
{
	int i;
	FILE *fp;
	char filename[300] = "./Student_Score.txt";
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("没有录入信息，或可能文件不存在！");
	}
	else
	{
		stu.len = 0;
		while (!feof(fp))
		{
			stu.len++;
			char temp[300];
			fgets(temp, sizeof(temp) - 1, fp);  //把文件的内容读入temp
			//cout << temp << endl;
			ClearNextLine(temp);
			/*stu.len++;*/
			char* sno = strtok(temp, " ");
			char* cprogamm = strtok(NULL, " ");
			char* algorithm = strtok(NULL, " ");
			char* datastructure = strtok(NULL, " ");
			char* android = strtok(NULL, " ");
			char* cs = strtok(NULL, " ");
			char* computer = strtok(NULL, " ");
			if (sno != NULL && cprogamm != NULL && algorithm != NULL && datastructure != NULL && android != NULL && cs != NULL && computer != NULL)
			{
				
					
						stu.student[stu.len].Sno = ConvertToInt(sno);
						int index = stu.student[stu.len].Sno;
						stu.student[index].Score[0] = ConverToDouble(cprogamm);
						stu.student[index].Score[1] = ConverToDouble(algorithm);
						stu.student[index].Score[2] = ConverToDouble(datastructure);
						stu.student[index].Score[3] = ConverToDouble(android);
						stu.student[index].Score[4] = ConverToDouble(cs);
						stu.student[index].Score[5] = ConverToDouble(computer);
						for (int j = 1;j <= stu.len;j++)
						{
							stu.student[j].Sum = stu.student[j].Score[0] + stu.student[j].Score[1] + stu.student[j].Score[2] + stu.student[j].Score[3] +
													stu.student[j].Score[4] + stu.student[j].Score[5];
														stu.student[j].Average = (stu.student[j].Sum) / 6.0;
						}
				        

			}


		}
		printf("成绩导入成功！\n");
	/*	cout << stu.student[1].Sum << endl;
		cout << stu.student[1].Average << endl;
*/

		printf("\n");
	}
	fclose(fp);
}
void Input_Score()
{
	FILE *fp;
	fp = fopen("./Student_Score.txt", "a");
	fprintf(fp, "\n");
	printf("请输入要录入成绩的学生学号：\n");
	int id;
	scanf("%d", &id);
	int i, j;
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
		{
			break;
		}
	}
	if (i > stu.len)
		printf("没有该学生!\n");
	else
	{
		stu.student[i].Sum = 0.0;
		printf("请分别输入《C程序设计》、《算法》、《数据结构》、《安卓》、《JAVA》、《计算机组成原理》的成绩\n");
		for (j = 0;j < 6;j++)
		{
			scanf("%lf", &stu.student[i].Score[j]);  //输入6科成绩
			stu.student[i].Sum += stu.student[i].Score[j];   //计算总成绩
	
		}
		//cout << "总成绩：" << stu.student[i].Sum << endl;
	}
}

void Check_Score()
{
	int i;
	double ave;
	printf("请输入要统计成绩的学生学号：\n");
	int id;
	scanf("%d", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
		{
			break;
		}
	}
	if (i > stu.len)
		printf("没有该学生!\n");
	else
	{
		while (1)
		{
			printf("1.查看总分  2.查看平均分  3.退后\n");
			int flag;
			scanf("%d", &flag);
			switch (flag)
			{
			case 1:
				printf("%lf\n", stu.student[i].Sum);
				break;
			case 2:
				ave = (stu.student[i].Sum) / 6.0;
				printf("%lf\n", ave);
				break;
			case 3:
				menu();
				break;
			}
		}
		

	}
}

void Update_Score()
{
	double temp;
	double score;
	char ch;
	int i;
	double ave;
	printf("请输入要统计成绩的学生学号：\n");
	int id;
	scanf("%d", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
		{
			break;
		}
	}
	if (i > stu.len)
		printf("没有该学生!\n");
	else
	{
		do
		{
			printf("请输入要修改学科的编号0 1 2 3 4 5 \n");
			int  num;
			scanf("%d", &num);
			printf("请输入修改后的分数：\n");
			
			scanf("%lf", &score);
			temp = score - stu.student[i].Score[num];
			stu.student[i].Score[num] = score;

			printf("修改成功！\n");
			stu.student[i].Sum += temp;

			printf("是否继续修改？（Y/N）");
		
			cin >> ch;
			if (ch == 'N')
			{
				menu();
				break;
			}

		} while (ch == 'Y');
	
	}
}


void Search_All_Score()
{ 
	//cout << stu.len << endl;
	//Sort_By_Score();
	for (int i = 1;i <= stu.len;i++)
	{
		printf("%-5d %-7.2lf %-7.2lf %-7.2lf %-7.2lf %-7.2lf %-7.2lf\n", stu.student[i].Sno, stu.student[i].Score[0], stu.student[i].Score[1],
			stu.student[i].Score[2], stu.student[i].Score[3], stu.student[i].Score[4], stu.student[i].Score[5]);
	}
		
}

//void Calculate_Sum()  //计算每个学生的总成绩
//{
//	
//	int i;
//	double ave;
//	printf("请输入要统计成绩的学生学号：\n");
//	int id;
//	scanf("%d", &id);
//	for (i = 1;i <= stu.len;i++)
//	{
//		if (stu.student[i].Sno == id)
//		{
//			stu.student[i].Sum=0.0;
//			break;
//		}
//	}
//	if (i > stu.len)
//		printf("没有该学生!\n");
//	else
//	{
//		stu.student[i].Sum = stu.student[i].Score[0] + stu.student[i].Score[1] + stu.student[i].Score[2] + stu.student[i].Score[3] + stu.student[i].Score[4] + stu.student[i].Score[5];
//		//printf("%.2lf\n", stu.student[i].Sum);
//		stu.student[i].Average = (stu.student[i].Sum) / 6.0;
//	}
//}

void Output_High_Score()
{
	
	Sort_By_Score();
	printf("总分最高的学生名字是：%s\n总成绩：%.2lf\n学号:%d\n性别：%s\n班级：%d\n出生日期：%s\n联系方式：%s\n家庭地址：%s\n", stu.student[1].Sname, stu.student[1].Sum, stu.student[1].Sno, stu.student[1].Gender, stu.student[1].Class, stu.student[1].Birthday, stu.student[1].Phone, stu.student[1].Address);
}

void Output_Top_Three()
{
	Sort_By_Score();

	printf("第一名的学生名字是：%s\n总成绩：%.2lf\n学号:%d\n性别：%s\n班级：%d\n出生日期：%s\n联系方式：%s\n家庭地址：%s\n", stu.student[1].Sname, stu.student[1].Sum, stu.student[1].Sno, stu.student[1].Gender, stu.student[1].Class, stu.student[1].Birthday, stu.student[1].Phone, stu.student[1].Address);

	printf("第二名的学生名字是：%s\n总成绩：%.2lf\n学号:%d\n性别：%s\n班级：%d\n出生日期：%s\n联系方式：%s\n家庭地址：%s\n", stu.student[2].Sname, stu.student[2].Sum, stu.student[2].Sno, stu.student[2].Gender, stu.student[2].Class, stu.student[2].Birthday, stu.student[2].Phone, stu.student[2].Address);

	printf("第三名的学生名字是：%s\n总成绩：%.2lf\n学号:%d\n性别：%s\n班级：%d\n出生日期：%s\n联系方式：%s\n家庭地址：%s\n", stu.student[3].Sname, stu.student[3].Sum, stu.student[3].Sno, stu.student[3].Gender, stu.student[3].Class, stu.student[3].Birthday, stu.student[3].Phone, stu.student[3].Address);
}
