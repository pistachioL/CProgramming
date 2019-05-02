#include "link.h"
#include <stdio.h>

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

char* toString(int iVal)
{
	char str[1024] = { '\0' ,};
	char *pos = NULL;
	int sign = 0;
	int abs = iVal;
	pos = str + 1023;
	*pos-- = '\0';

	if (iVal < 0)
	{
		sign = 1;
		abs = -abs;
	}
	int dit = 0;
	while (abs > 0)
	{
		dit = abs % 10;
		abs = abs / 10;
		*pos-- = (char)('0' + dit);
	}
	if (sign)
		*pos-- = '-';
	char *ret = (char*)malloc(1024 - (pos - str));
	if (iVal == 0)
		strcpy(ret, "0");
	else
		strcpy(ret, pos + 1);
	return(ret);

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
				strcpy(stu.student[stu.len].Sno, sno);
		
		
				strcpy(stu.student[stu.len].Sname, name);

				strcpy(stu.student[stu.len].Gender, gender);
				
				
				strcpy(stu.student[stu.len].Class, classes);

				strcpy(stu.student[stu.len].Birthday, birthday);

				
				strcpy(stu.student[stu.len].Phone, phone);
				
				strcpy(stu.student[stu.len].Sno, sno);

	

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
	for (int i = 1;i <= stu.len+1;i++)
	{
		printf("%-5s %-5s %-5s %-10s %-10s %-10s %-10s\n",stu.student[i].Sno,stu.student[i].Sname,stu.student[i].Gender,stu.student[i].Class,stu.student[i].Birthday,stu.student[i].Phone, stu.student[i].Address);
 	}
	
}