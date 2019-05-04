#include "link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
using namespace std;

void ClearNextLine(char *s) //清除换行符
{
	char *find = strchr(s, '\n');
	if (find)
	{
		*find = '\0';
	}
}
int ConvertToInt(char* a)
{
	int x;
	x = atoi(a);
	return x;
}
//char* itoa(int n, char s[])
//{
//	int i, j, sign;
//	if ((sign = n) < 0)//记录符号
//		n = -n;//使n成为正数
//	i = 0;
//	do {
//		s[i++] = n % 10 + '0';//取下一个数字
//	} while ((n /= 10) > 0);//删除该数字
//	if (sign < 0)
//		s[i++] = '-';
//	s[i] = '\0';
//	
//	for (j = i;j >= 0;j--)//生成的数字是逆序的，所以要逆序输出
//		/*printf("%c", s[j]);*/
//		return s;
//}





int CountLines()
{
	char arr[300];
	int n = 0;
	FILE *fp;
	fp = fopen("./Student_Info.txt","r");
	if(fp)
	{
		while ((fgets(arr, 200, fp)) != NULL)
		{
			if (arr[strlen(arr) - 1] == '\n')
				++n;
		}
	}
	return n+1;
}

void Import()
{
	FILE *fp;
	char filename[10000] = "./Student_Info.txt";
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("没有录入信息，或可能文件不存在！");
	}
	else
	{
		while (!feof(fp))
		{
			char temp[300];
			fgets(temp, sizeof(temp) - 1, fp);  //把文件的内容读入temp
			//cout << temp << endl;
			ClearNextLine(temp);
			stu.len++;
			char* sno = strtok(temp, " ");
			char* name = strtok(NULL, " ");
			char* gender = strtok(NULL, " ");
			char* classes = strtok(NULL, " ");
			char* birthday = strtok(NULL, " ");
			char* phone = strtok(NULL, " ");
			char* address = strtok(NULL, " ");
			if (sno != NULL && name != NULL && gender != NULL && classes != NULL && birthday != NULL && phone != NULL && address != NULL)
			{
				stu.student[stu.len].Sno = ConvertToInt(sno);

				strcpy(stu.student[stu.len].Sname, name);

				strcpy(stu.student[stu.len].Gender, gender);
				
				stu.student[stu.len].Class = ConvertToInt(classes);

				strcpy(stu.student[stu.len].Birthday, birthday);

				strcpy(stu.student[stu.len].Phone, phone);
				
				strcpy(stu.student[stu.len].Address, address);

			}
			

		}
		printf("学生基本信息导入成功！\n");
	
		
		printf("\n");
	}
	fclose(fp);
}


void Search_All_Info()
{
	printf("\n");
	printf("请选择查看方式：\n");
	printf("1.按学号排序  2.按名字排序  3.按班级排序\n");
	int flag;
	scanf("%d", &flag);
	switch (flag)
	{
	case 1:
		SortBySno();
		break;
	case 2:
		SortByName();
		break;
	case 3:
		SortByClass();
		break;

	}
	//SortByClass();

	for (int i = 1;i <= stu.len;i++)
	{
		printf("%-5d %-5s %-5s %-10d %-10s %-10s %-10s\n",stu.student[i].Sno,stu.student[i].Sname,stu.student[i].Gender,
			stu.student[i].Class,stu.student[i].Birthday,stu.student[i].Phone, stu.student[i].Address);
 	}
	
}

void Search_By_Sno()  //通过学号查询
{
	int i;
	printf("请输入你要查询的学号：\n");
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
	{
		printf("没有该学生！\n");
	
	}
		
	else
	{
		printf("姓名:%s\n性别:%s\n所在班级:%d\n出生日期：%s\n联系方式：%s\n家庭地址是:%s\n", stu.student[i].Sname, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
	}

}

void Search_By_Sname()  //通过姓名查询
{
	int i;
	printf("请输入你要查询的姓名：\n");
	char name[30];
	scanf("%s", name);
	for (i = 1;i <= stu.len;i++)
	{
		if (strcmp(stu.student[i].Sname, name) == 0)
		{
			break;
		}

	}
	if (i > stu.len)
	{
		printf("没有该学生！\n");

	}

	else
	{
		printf("学号:%d\n性别:%s\n所在班级:%d\n出生日期：%s\n联系方式：%s\n家庭地址是:%s\n", stu.student[i].Sno, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
	}

}

void Search_By_Phone()  //通过联系方式查询
{
	int i;
	printf("请输入你要查询的手机号码：\n");
	char phone[30];
	scanf("%s", phone);
	for (i = 1;i <= stu.len;i++)
	{
		if (strcmp(stu.student[i].Phone, phone) == 0)
		{
			break;
		}

	}
	if (i > stu.len)
	{
		printf("没有该学生！\n");

	}

	else
	{
		printf("学号：%d\n姓名:%s\n性别:%s\n所在班级:%d\n出生日期：%s\n家庭地址是:%s\n", stu.student[i].Sno, stu.student[i].Sname, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday,  stu.student[i].Address);
	}

}

void Search_By_Class()  //通过班级查询
{
	int i,j=0;
	printf("请输入该学生的班级：\n");
	int classno;
	scanf("%d", &classno);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Class == classno)
		{
			printf("姓名:%s\n性别:%s\n所在班级:%d\n出生日期：%s\n联系方式：%s\n家庭地址是:%s\n", stu.student[i].Sname, stu.student[i].Gender,
				stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
		}
	

	}
	if(i>stu.len)
		printf("没有该学生！\n");
	
}

void Insert()
{
	int i;
	char ch;
	char a[300];
	int n = CountLines();
	FILE *fp;
	fp = fopen("./Student_Info.txt", "a");
	printf("请输入要需要插入的学生的学号：\n");
	int id;
	scanf("%d", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
		{
			printf("该学生已经存在，请重新输入！\n");
			Insert();
		}
	}
	if(i>stu.len)
	{
		do
		{
			n++;
			stu.len = n;
			stu.student[stu.len].Sno = stu.len;
			fprintf(fp, "%d", n);
			//	fprintf(fp, "%d", stu.student[stu.len].Sno);
			//cout << stu.student[stu.len].Sno << endl;
			printf("请输入学生名字：\n");
			char name[30];
			scanf("%s", name);
			strcpy(stu.student[stu.len].Sname, name);
			//	fprintf(fp, "%s", stu.student[stu.len].Sname);

			printf("请输入学生性别：\n");
			char sex[30];
			scanf("%s", sex);
			strcpy(stu.student[stu.len].Gender, sex);
			//	fprintf(fp, "%s", stu.student[stu.len].Gender);

			printf("请输入学生班级：\n");
			int c;
			scanf("%d", &c);
			stu.student[stu.len].Class = c;
			//	fprintf(fp, "%s", stu.student[stu.len].Class);

			printf("请输入学生出生日期：\n");
			char b[30];
			scanf("%s", b);
			strcpy(stu.student[stu.len].Birthday, b);
			//	fprintf(fp, "%s", stu.student[stu.len].Birthday);

			printf("请输入学生联系方式：\n");
			char p[30];
			scanf("%s", p);
			strcpy(stu.student[stu.len].Phone, p);
			//	fprintf(fp, "%s", stu.student[stu.len].Phone);

			printf("请输入学生家庭地址：\n");
			char addr[30];
			scanf("%s", addr);
			strcpy(stu.student[stu.len].Address, addr);
			//	fprintf(fp, "%s\n", stu.student[stu.len].Address);



			printf("添加成功！\n");
			printf("学生有%d人\n", n);
			fprintf(fp, "\n");
		/*	fprintf(fp, "%d \t %s \t %s \t %d \t %s \t %s \t %s\n", stu.student[id].Sno, stu.student[id].Sname, stu.student[id].Gender,
					stu.student[id].Class, stu.student[id].Birthday, stu.student[id].Phone, stu.student[id].Address);*/

			
			printf("是否继续添加？（Y/N）\n");

			//scanf("%c", &ch);
			//getchar();   //吸收回车符
			cin >> ch;
			if (ch == 'N')
			{
				menu();
				break;
			}

		} while (ch == 'Y');
		    
		
	}
}


void Update()
{
	int i;
	printf("请输入要修改学生的学号：\n");
	int id;
	scanf("%d", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
			break;
	}
	if (i > stu.len)
		printf("没有该学生！\n");
	else
	{
		printf("请输入要修改学生的信息：\n");
		printf("1.修改姓名  2.修改联系方式  3.修改家庭住址：\n");
		int flag;
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			printf("请输入修改后的姓名：\n");
			char name[30];
			scanf("%s", name);
			strcpy(stu.student[i].Sname, name);
			break;
		case 2:
			printf("请输入修改后的联系方式：\n");
			char call[30];
			scanf("%s", call);
			strcpy(stu.student[i].Phone, call);	
			break;
		case 3:
			printf("请输入修改后的家庭住址：\n");
			char home[30];
			scanf("%s", home);
			strcpy(stu.student[i].Address, home);
			break;

		}
		printf("更新成功！\n");
	}
}


void Delete_By_Sno()
{
	int i,j;
	printf("请输入要删除学生的学号：\n");
	int id;
	scanf("%d", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
			break;
	}
	if (i > stu.len)
		printf("没有该学生！\n");
	else
	{
		for (j = i + 1;j <= stu.len;j++)
		{
			stu.student[i] = stu.student[j];
		}
		printf("删除成功！\n");
	}
}


void Delete_By_Name()
{
	int i, j;
	printf("请输入要删除学生的姓名：\n");
	char name[30];
	scanf("%s", &name);
	for (i = 1;i <= stu.len;i++)
	{
		if (strcmp(stu.student[i].Sname,name)==0)
			break;
	}
	if (i > stu.len)
		printf("没有该学生！\n");
	else
	{
		for (j = i + 1;j <= stu.len;j++)
		{
			stu.student[i] = stu.student[j];
		}
		printf("删除成功！\n");
	}
}


void Save_In_File()
{
	FILE *fp;
	fp = fopen("./Student_Info.txt", "w");
	char blank[30] = " ";
	for (int i = 1;i <= stu.len;i++)
	{
		fprintf(fp, "%d %s %-10s %s %-10s %s %-10d %s %-10s %s %-10s %s %-10s\n", stu.student[i].Sno, blank, stu.student[i].Sname, blank,stu.student[i].Gender, blank,
				stu.student[i].Class, blank, stu.student[i].Birthday, blank,stu.student[i].Phone, blank, stu.student[i].Address);
	}
}