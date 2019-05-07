#include "link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>  //声明atoll（）
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

long long int ConvertToLongInt(char* a)
{
	long long int b;
	b = atoll(a);
	return b;
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
			char* sid = strtok(NULL, " ");
			char* name = strtok(NULL, " ");
			char* gender = strtok(NULL, " ");
			char* classes = strtok(NULL, " ");
			char* birthday = strtok(NULL, " ");
			char* phone = strtok(NULL, " ");
			char* address = strtok(NULL, " ");
			if (sno != NULL && sid != NULL && name != NULL && gender != NULL && classes != NULL && birthday != NULL && phone != NULL && address != NULL)
			{
				stu.student[stu.len].Sno = ConvertToInt(sno);

				stu.student[stu.len].SID = ConvertToLongInt(sid);

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
	printf("\n");
	
	printf("序号    学号       姓名     性别    班别    出生日期    联系方式    家庭地址\n");
	for (int i = 1;i <= stu.len;i++)
	{
		printf("%-5d %-2lld %-10s %-5s %-5d %-9s %-8s %-5s\n", stu.student[i].Sno, stu.student[i].SID, stu.student[i].Sname, stu.student[i].Gender,
			stu.student[i].Class,stu.student[i].Birthday,stu.student[i].Phone, stu.student[i].Address);
		printf("\n");
 	}
	
}

void Search_By_Sno()  //通过学号查询
{
	int i;
	printf("请输入你要查询的学号：\n");
	long long int id;
	scanf("%lld", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].SID == id)
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
		printf("学号:%lld\n性别:%s\n所在班级:%d\n出生日期：%s\n联系方式：%s\n家庭地址是:%s\n", stu.student[i].SID, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
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
		printf("学号：%lld\n姓名:%s\n性别:%s\n所在班级:%d\n出生日期：%s\n家庭地址是:%s\n", stu.student[i].SID, stu.student[i].Sname, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday,  stu.student[i].Address);
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
			printf("学号:%lld\n姓名:%s\n性别:%s\n所在班级:%d\n出生日期：%s\n联系方式：%s\n家庭地址是:%s\n", stu.student[i].SID,stu.student[i].Sname, stu.student[i].Gender,
				stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
		}
	}
	if(i>stu.len)
		printf("没有该学生！\n");
	
}

void Insert()
{
	long long int id;
	int i;
	char ch = 'Y';
	char a[300];
	int n = CountLines();
	FILE *fp;
	fp = fopen("./Student_Info.txt", "a");
	do {
		printf("请输入要需要插入的学生的学号(12位)：\n");

		scanf("%lld", &id);
		for (i = 1;i <= stu.len;i++)
		{
			if (stu.student[i].SID == id)
			{
				printf("该学生已经存在，请重新输入！\n");
				break;
			}
		}
		if (i > stu.len)
		{
			n++;
			stu.len = n;
			stu.student[stu.len].Sno = stu.len;
			fprintf(fp, "%d", n);

			/*	printf("请输入学生的学号：(12位)\n");
				long long int id;
				scanf("%lld", &id);*/
			stu.student[stu.len].SID = id;

			printf("请输入学生名字：\n");
			char name[30];
			scanf("%s", name);
			strcpy(stu.student[stu.len].Sname, name);


			printf("请输入学生性别：\n");
			char sex[30];
			scanf("%s", sex);
			strcpy(stu.student[stu.len].Gender, sex);


			printf("请输入学生班级：（如1）\n");
			int c;
			scanf("%d", &c);
			stu.student[stu.len].Class = c;


			printf("请输入学生出生日期：(1998/10/09)\n");
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
			
			printf("学生有%d人\n", stu.len);
			fprintf(fp, "\n");
		


			printf("是否继续添加？（Y/N）\n");

			//scanf("%c", &ch);
			//getchar();   //吸收回车符
			cin >> ch;
			if (ch == 'N')
			{
				menu();
				break;
			}

		}

	} while (ch == 'Y' || ch == 'y');
}



void Update()
{
	int i;
	printf("请输入要修改学生的学号：\n");
	long long int id;
	scanf("%lld", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].SID == id)
		{
			break;
		}

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
	long long int id;
	scanf("%lld", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].SID == id)
		{
			break;
		}

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
		stu.len--;   //先替换 再删除
		//cout << stu.len << endl;
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
		stu.len--;
	}
}


void Save_In_File()
{
	FILE *fp;
	fp = fopen("./Student_Info.txt", "w");

	for (int i = 1;i <= stu.len;i++)
	{
		fprintf(fp, "%d    %-10lld      %-10s    %-10s     %-10d    %-10s    %-10s   %-10s", stu.student[i].Sno, stu.student[i].SID, stu.student[i].Sname, stu.student[i].Gender,
			stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
	}

	/*int n = 123;
	fprintf(fp, "%d", n);*/
	fclose(fp);
}