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
		printf("û��¼����Ϣ��������ļ������ڣ�");
	}
	else
	{
		stu.len = 0;
		while (!feof(fp))
		{
			stu.len++;
			char temp[300];
			fgets(temp, sizeof(temp) - 1, fp);  //���ļ������ݶ���temp
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
		printf("�ɼ�����ɹ���\n");
	/*	cout << stu.student[1].Sum << endl;
		cout << stu.student[1].Average << endl;
*/

		printf("\n");
	}
	fclose(fp);
}
void Input_Score()
{
	int i,j;
	FILE *fp;
	fp = fopen("./Student_Score.txt", "a");
	fprintf(fp, "\n");
	printf("������Ҫ¼��ɼ���ѧ��ѧ�ţ�\n");
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
		printf("û�и�ѧ��!\n");
	else
	{
		stu.student[i].Sum = 0.0;
		printf("��ֱ����롶C������ơ������㷨���������ݽṹ��������׿������JAVA��������������ԭ���ĳɼ�\n");
		for (j = 0;j < 6;j++)
		{
			scanf("%lf", &stu.student[i].Score[j]);  //����6�Ƴɼ�
			//stu.student[i].Sum += stu.student[i].Score[j];   //�����ܳɼ�
	
		}
		//cout << "�ܳɼ���" << stu.student[i].Sum << endl;
	}
}

void Check_Score()
{
	int i;
	double ave;
	printf("������Ҫͳ�Ƴɼ���ѧ��ѧ�ţ�\n");
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
	double temp;
	double score;
	char ch;
	int i;
	double ave;
	printf("������Ҫͳ�Ƴɼ���ѧ��ѧ�ţ�\n");
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
		printf("û�и�ѧ��!\n");
	else
	{
		do
		{
			printf("��Ӧÿ��ѧ�Ƶı��Ϊ��\n");
			printf("0.��C������ơ� 1.���㷨�� 2.�����ݽṹ�� 3.����׿�� 4.��JAVA�� 5.����������ԭ��\n");
			printf("������Ҫ�޸�ѧ�Ƶı��:\n");
			int  num;
			scanf("%d", &num);
			printf("�������޸ĺ�ķ�����\n");
			
			scanf("%lf", &score);
			temp = score - stu.student[i].Score[num];
			stu.student[i].Score[num] = score;

			printf("�޸ĳɹ���\n");
			stu.student[i].Sum += temp;

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

//void Calculate_Sum()  //����ÿ��ѧ�����ܳɼ�
//{
//	
//	int i;
//	double ave;
//	printf("������Ҫͳ�Ƴɼ���ѧ��ѧ�ţ�\n");
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
//		printf("û�и�ѧ��!\n");
//	else
//	{
//		stu.student[i].Sum = stu.student[i].Score[0] + stu.student[i].Score[1] + stu.student[i].Score[2] + stu.student[i].Score[3] + stu.student[i].Score[4] + stu.student[i].Score[5];
//		//printf("%.2lf\n", stu.student[i].Sum);
//		stu.student[i].Average = (stu.student[i].Sum) / 6.0;
//	}
//}

void Output_High_Score()
{
	for (int j = 1;j <= stu.len;j++)
	{
		stu.student[j].Sum = stu.student[j].Score[0] + stu.student[j].Score[1] + stu.student[j].Score[2] + stu.student[j].Score[3] +
			stu.student[j].Score[4] + stu.student[j].Score[5];
		stu.student[j].Average = (stu.student[j].Sum) / 6.0;
	}
	Sort_By_Score();
	printf("�ܷ���ߵ�ѧ�������ǣ�%s\n�ܳɼ���%.2lf\nѧ��:%lld\n�Ա�%s\n�༶��%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��%s\n", stu.student[1].Sname, stu.student[1].Sum, stu.student[1].SID, stu.student[1].Gender, stu.student[1].Class, stu.student[1].Birthday, stu.student[1].Phone, stu.student[1].Address);
}

void Output_Top_Three()
{
	for (int j = 1;j <= stu.len;j++)
	{
		stu.student[j].Sum = stu.student[j].Score[0] + stu.student[j].Score[1] + stu.student[j].Score[2] + stu.student[j].Score[3] +
			stu.student[j].Score[4] + stu.student[j].Score[5];
		stu.student[j].Average = (stu.student[j].Sum) / 6.0;
	}
	Sort_By_Score();


	printf("��һ����ѧ�������ǣ�%s\n�ܳɼ���%.2lf\nѧ��:%lld\n�Ա�%s\n�༶��%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��%s\n", stu.student[1].Sname, stu.student[1].Sum, stu.student[1].SID, stu.student[1].Gender, stu.student[1].Class, stu.student[1].Birthday, stu.student[1].Phone, stu.student[1].Address);

	printf("�ڶ�����ѧ�������ǣ�%s\n�ܳɼ���%.2lf\nѧ��:%lld\n�Ա�%s\n�༶��%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��%s\n", stu.student[2].Sname, stu.student[2].Sum, stu.student[2].SID, stu.student[2].Gender, stu.student[2].Class, stu.student[2].Birthday, stu.student[2].Phone, stu.student[2].Address);

	printf("��������ѧ�������ǣ�%s\n�ܳɼ���%.2lf\nѧ��:%lld\n�Ա�%s\n�༶��%d\n�������ڣ�%s\n��ϵ��ʽ��%s\n��ͥ��ַ��%s\n", stu.student[3].Sname, stu.student[3].Sum, stu.student[3].SID, stu.student[3].Gender, stu.student[3].Class, stu.student[3].Birthday, stu.student[3].Phone, stu.student[3].Address);
}
