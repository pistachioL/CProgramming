#include "link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
using namespace std;
void Import_Socre()
{
	int i;
	FILE *fp;
	char filename[10000] = "./Student_Score.txt";
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
			char* cprogamm = strtok(NULL, " ");
			char* algorithm = strtok(NULL, " ");
			char* datastructure = strtok(NULL, " ");
			char* android = strtok(NULL, " ");
			char* cs = strtok(NULL, " ");
			char* computer = strtok(NULL, " ");
			if (sno != NULL && cprogamm != NULL && algorithm != NULL && datastructure != NULL && android != NULL && cs != NULL && computer != NULL)
			{
				for (i = 1;i <= stu.len;i++)
				{
					
						stu.student[i].Sno = ConvertToInt(sno);
						stu.student[i].Score[0] = ConvertToInt(cprogamm);
						stu.student[i].Score[1] = ConvertToInt(algorithm);
						stu.student[i].Score[2] = ConvertToInt(datastructure);
						stu.student[i].Score[3] = ConvertToInt(android);
						stu.student[i].Score[4] = ConvertToInt(cs);
						stu.student[i].Score[5] = ConvertToInt(computer);
					
					
				}

			}


		}
		printf("�ɼ�����ɹ���\n");
		printf("\n");
	}
	fclose(fp);
}
void Input_Score()
{
	FILE *fp;
	fp = fopen("./Student_Score.txt", "a");
	fprintf(fp, "\n");
	printf("������Ҫ¼��ɼ���ѧ��ѧ�ţ�\n");
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
		printf("û�и�ѧ��!\n");
	else
	{
		stu.student[i].Sum = 0.0;
		printf("��ֱ����롶C������ơ������㷨���������ݽṹ��������׿������JAVA��������������ԭ���ĳɼ�\n");
		for (j = 0;j < 6;j++)
		{
			scanf("%lf", &stu.student[i].Score[j]);  //����6�Ƴɼ�
			stu.student[i].Sum += stu.student[i].Score[j];   //�����ܳɼ�
	
		}
		//cout << "�ܳɼ���" << stu.student[i].Sum << endl;
	}
}

void Check_Score()
{
	int i;
	double ave;
	printf("������Ҫͳ�Ƴɼ���ѧ��ѧ�ţ�\n");
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
		printf("û�и�ѧ��!\n");
	else
	{
		while (1)
		{
			printf("1.�鿴�ܷ�  2.�鿴ƽ����  3.�˺�\n");
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
	char ch;
	int i;
	double ave;
	printf("������Ҫͳ�Ƴɼ���ѧ��ѧ�ţ�\n");
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
		printf("û�и�ѧ��!\n");
	else
	{
		do
		{
			printf("������Ҫ�޸�ѧ�Ƶı��1 2 3 4 5 6\n");
			int  num;
			scanf("%d", &num);
			printf("�������޸ĺ�ķ�����\n");
			double score;
			scanf("%lf", &score);
			stu.student[i].Score[num] = score;

			printf("�޸ĳɹ���\n");
			cout << stu.student[i].Score[num] << endl;
			printf("�Ƿ�����޸ģ���Y/N��");
		
			cin >> ch;
			if (ch == 'N')
			{
				menu();
				break;
			}

		} while (ch == 'Y');
	
	}
}

void Output_High_Score()
{
	Sort_By_Score();
	for (int i = 1;i <= stu.len;i++)
	{
		printf("%lf", stu.student[])
	}
}