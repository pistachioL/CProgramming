#include "link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
using namespace std;

void ClearNextLine(char *s) //������з�
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
//	if ((sign = n) < 0)//��¼����
//		n = -n;//ʹn��Ϊ����
//	i = 0;
//	do {
//		s[i++] = n % 10 + '0';//ȡ��һ������
//	} while ((n /= 10) > 0);//ɾ��������
//	if (sign < 0)
//		s[i++] = '-';
//	s[i] = '\0';
//	
//	for (j = i;j >= 0;j--)//���ɵ�����������ģ�����Ҫ�������
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
		printf("û��¼����Ϣ��������ļ������ڣ�");
	}
	else
	{
		while (!feof(fp))
		{
			char temp[300];
			fgets(temp, sizeof(temp) - 1, fp);  //���ļ������ݶ���temp
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
				//strcpy(stu.student[stu.len].Sno, sno);
				stu.student[stu.len].Sno = ConvertToInt(sno);
				//cout << stu.student[stu.len].Sno << endl;
				strcpy(stu.student[stu.len].Sname, name);

				strcpy(stu.student[stu.len].Gender, gender);
				
			//	strcpy(stu.student[stu.len].Class, classes);
				stu.student[stu.len].Class = ConvertToInt(classes);

				strcpy(stu.student[stu.len].Birthday, birthday);

				strcpy(stu.student[stu.len].Phone, phone);
				
				strcpy(stu.student[stu.len].Address, address);

			}
			

		}
		printf("ѧ��������Ϣ����ɹ���\n");
	
		
		printf("\n");
	}
	fclose(fp);
}

void Search_All_Info()
{
	printf("\n");
	printf("��ѡ��鿴��ʽ��\n");
	printf("1.��ѧ������  2.����������  3.���༶����");
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

void Search_By_Sno()  //ͨ��ѧ�Ų�ѯ
{
	int i;
	printf("��������Ҫ��ѯ��ѧ�ţ�\n");
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
		printf("û�и�ѧ����\n");
	
	}
		
	else
	{
		printf("����:%s\n�Ա�:%s\n���ڰ༶:%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��:%s\n", stu.student[i].Sname, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
	}

}

void Search_By_Sname()  //ͨ��������ѯ
{
	int i;
	printf("��������Ҫ��ѯ��������\n");
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
		printf("û�и�ѧ����\n");

	}

	else
	{
		printf("ѧ��:%d\n�Ա�:%s\n���ڰ༶:%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��:%s\n", stu.student[i].Sno, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
	}

}

void Search_By_Phone()  //ͨ����ϵ��ʽ��ѯ
{
	int i;
	printf("��������Ҫ��ѯ���ֻ����룺\n");
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
		printf("û�и�ѧ����\n");

	}

	else
	{
		printf("ѧ�ţ�%d\n����:%s\n�Ա�:%s\n���ڰ༶:%d\n�������ڣ�%s\n��ͥ��ַ��:%s\n", stu.student[i].Sno, stu.student[i].Sname, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday,  stu.student[i].Address);
	}

}

void Search_By_Class()  //ͨ���༶��ѯ
{
	int i,j=0;
	printf("�������ѧ���İ༶��\n");
	int classno;
	scanf("%d", &classno);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Class == classno)
		{
			printf("����:%s\n�Ա�:%s\n���ڰ༶:%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��:%s\n", stu.student[i].Sname, stu.student[i].Gender,
				stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
		}
	

	}
	if(i>stu.len)
		printf("û�и�ѧ����\n");
	
}

void Insert()
{
	int i;
	char ch;
	char a[300];
	int n = CountLines();
	FILE *fp;
	fp = fopen("./Student_Info.txt", "a");
	
	if (fp == NULL)
		printf("�ı�û�����ݣ�");
	else
	{
		do
		{

			fprintf(fp, "\n");
			n++;
			stu.len = n;
			stu.student[stu.len].Sno = stu.len;
			fprintf(fp, "%d", n);
			//	fprintf(fp, "%d", stu.student[stu.len].Sno);


			cout << stu.student[stu.len].Sno << endl;
			printf("������ѧ�����֣�\n");
			char name[30];
			scanf("%s", name);
			strcpy(stu.student[stu.len].Sname, name);
			//	fprintf(fp, "%s", stu.student[stu.len].Sname);

			printf("������ѧ���Ա�\n");
			char sex[30];
			scanf("%s", sex);
			strcpy(stu.student[stu.len].Gender, sex);
			//	fprintf(fp, "%s", stu.student[stu.len].Gender);

			printf("������ѧ���༶��\n");
			int c;
			scanf("%d", &c);
			stu.student[stu.len].Class == c;
			//	fprintf(fp, "%s", stu.student[stu.len].Class);

			printf("������ѧ���������ڣ�\n");
			char b[30];
			scanf("%s", b);
			strcpy(stu.student[stu.len].Birthday, b);
			//	fprintf(fp, "%s", stu.student[stu.len].Birthday);

			printf("������ѧ����ϵ��ʽ��\n");
			char p[30];
			scanf("%s", p);
			strcpy(stu.student[stu.len].Phone, p);
			//	fprintf(fp, "%s", stu.student[stu.len].Phone);

			printf("������ѧ����ͥ��ַ��\n");
			char addr[30];
			scanf("%s", addr);
			strcpy(stu.student[stu.len].Address, addr);
			//	fprintf(fp, "%s\n", stu.student[stu.len].Address);



			printf("��ӳɹ���\n");
			printf("ѧ����%d��\n", n);
			for (i = n;i <= stu.len;i++)
			{
				fprintf(fp, "%d %s %s %d %s %s %s\n", stu.student[i].Sno, stu.student[i].Sname, stu.student[i].Gender,
					stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
			}
			printf("�Ƿ������ӣ���Y/N��\n");

			//scanf("%c", &ch);
			//getchar();   //���ջس���
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
	printf("������Ҫ�޸�ѧ����ѧ�ţ�\n");
	int id;
	scanf("%d", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
			break;
	}
	if (i > stu.len)
		printf("û�и�ѧ����\n");
	else
	{
		printf("������Ҫ�޸�ѧ������Ϣ��\n");
		printf("1.�޸�����  2.�޸���ϵ��ʽ  3.�޸ļ�ͥסַ��\n");
		int flag;
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			printf("�������޸ĺ��������\n");
			char name[30];
			scanf("%s", name);
			strcpy(stu.student[i].Sname, name);
			break;
		case 2:
			printf("�������޸ĺ����ϵ��ʽ��\n");
			char call[30];
			scanf("%s", call);
			strcpy(stu.student[i].Phone, call);
			break;
		case 3:
			printf("�������޸ĺ�ļ�ͥסַ��\n");
			char home[30];
			scanf("%s", home);
			strcpy(stu.student[i].Address, home);
			break;

		}
		printf("���³ɹ���\n");
	}
}


void Delete_By_Sno()
{
	int i,j;
	printf("������Ҫɾ��ѧ����ѧ�ţ�\n");
	int id;
	scanf("%d", &id);
	for (i = 1;i <= stu.len;i++)
	{
		if (stu.student[i].Sno == id)
			break;
	}
	if (i > stu.len)
		printf("û�и�ѧ����\n");
	else
	{
		for (j = i + 1;j <= stu.len;j++)
		{
			stu.student[i] = stu.student[j];
		}
		printf("ɾ���ɹ���\n");
	}
}


void Delete_By_Name()
{
	int i, j;
	printf("������Ҫɾ��ѧ����������\n");
	char name[30];
	scanf("%s", &name);
	for (i = 1;i <= stu.len;i++)
	{
		if (strcmp(stu.student[i].Sname,name)==0)
			break;
	}
	if (i > stu.len)
		printf("û�и�ѧ����\n");
	else
	{
		for (j = i + 1;j <= stu.len;j++)
		{
			stu.student[i] = stu.student[j];
		}
		printf("ɾ���ɹ���\n");
	}
}