#include "link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>  //����atoll����
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

long long int ConvertToLongInt(char* a)
{
	long long int b;
	b = atoll(a);
	return b;
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
		printf("ѧ��������Ϣ����ɹ���\n");
	
		
		printf("\n");
	}
	fclose(fp);
}


void Search_All_Info()
{
	printf("\n");
	printf("��ѡ��鿴��ʽ��\n");
	printf("1.��ѧ������  2.����������  3.���༶����\n");
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
	
	printf("���    ѧ��       ����     �Ա�    ���    ��������    ��ϵ��ʽ    ��ͥ��ַ\n");
	for (int i = 1;i <= stu.len;i++)
	{
		printf("%-5d %-2lld %-10s %-5s %-5d %-9s %-8s %-5s\n", stu.student[i].Sno, stu.student[i].SID, stu.student[i].Sname, stu.student[i].Gender,
			stu.student[i].Class,stu.student[i].Birthday,stu.student[i].Phone, stu.student[i].Address);
		printf("\n");
 	}
	
}

void Search_By_Sno()  //ͨ��ѧ�Ų�ѯ
{
	int i;
	printf("��������Ҫ��ѯ��ѧ�ţ�\n");
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
		printf("ѧ��:%lld\n�Ա�:%s\n���ڰ༶:%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��:%s\n", stu.student[i].SID, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
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
		printf("ѧ�ţ�%lld\n����:%s\n�Ա�:%s\n���ڰ༶:%d\n�������ڣ�%s\n��ͥ��ַ��:%s\n", stu.student[i].SID, stu.student[i].Sname, stu.student[i].Gender, stu.student[i].Class, stu.student[i].Birthday,  stu.student[i].Address);
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
			printf("ѧ��:%lld\n����:%s\n�Ա�:%s\n���ڰ༶:%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��:%s\n", stu.student[i].SID,stu.student[i].Sname, stu.student[i].Gender,
				stu.student[i].Class, stu.student[i].Birthday, stu.student[i].Phone, stu.student[i].Address);
		}
	}
	if(i>stu.len)
		printf("û�и�ѧ����\n");
	
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
		printf("������Ҫ��Ҫ�����ѧ����ѧ��(12λ)��\n");

		scanf("%lld", &id);
		for (i = 1;i <= stu.len;i++)
		{
			if (stu.student[i].SID == id)
			{
				printf("��ѧ���Ѿ����ڣ����������룡\n");
				break;
			}
		}
		if (i > stu.len)
		{
			n++;
			stu.len = n;
			stu.student[stu.len].Sno = stu.len;
			fprintf(fp, "%d", n);

			/*	printf("������ѧ����ѧ�ţ�(12λ)\n");
				long long int id;
				scanf("%lld", &id);*/
			stu.student[stu.len].SID = id;

			printf("������ѧ�����֣�\n");
			char name[30];
			scanf("%s", name);
			strcpy(stu.student[stu.len].Sname, name);


			printf("������ѧ���Ա�\n");
			char sex[30];
			scanf("%s", sex);
			strcpy(stu.student[stu.len].Gender, sex);


			printf("������ѧ���༶������1��\n");
			int c;
			scanf("%d", &c);
			stu.student[stu.len].Class = c;


			printf("������ѧ���������ڣ�(1998/10/09)\n");
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
			
			printf("ѧ����%d��\n", stu.len);
			fprintf(fp, "\n");
		


			printf("�Ƿ������ӣ���Y/N��\n");

			//scanf("%c", &ch);
			//getchar();   //���ջس���
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
	printf("������Ҫ�޸�ѧ����ѧ�ţ�\n");
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
		printf("û�и�ѧ����\n");
	else
	{
		
	
		for (j = i + 1;j <= stu.len;j++)
		{
			stu.student[i] = stu.student[j];
		}
		printf("ɾ���ɹ���\n");
		stu.len--;   //���滻 ��ɾ��
		//cout << stu.len << endl;
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