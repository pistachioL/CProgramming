#include "link.h"
#include <stdio.h>
#include <stdlib.h>
STU stu;

void menu()
{ 
	
	int flag;
	while (1)
	{
		printf("\t\t************ ��ѡ����Ĳ�����**************\n");
		printf("\t\t1.����ѧ����Ϣ\t\t");
		printf("2.�������ѧ����Ϣ\n");
		printf("\t\t3.ͨ��ѧ�Ų�ѯ��Ϣ\t");
		printf("4.ͨ��������ѯ��Ϣ\n");
		printf("\t\t5.ͨ����ϵ��ʽ��ѯ��Ϣ\t");
		printf("6.����ѧ����Ϣ\n");
		printf("\t\t7.ͨ��ѧ��ɾ��\t\t");
		printf("8.ͨ������ɾ��\n");
		printf("\t\t9.ͨ���༶��ѯ\t\t");
		printf("10.¼��ѧ���ɼ�\n");
		printf("\t\t11.�޸�ѧ���ɼ�\t\t");
		printf("12.�鿴ѧ���ɼ�(����)\n");
		printf("\t\t13.�鿴ѧ�����гɼ�\t");
		printf("14.����ܳɼ���ߵ�ѧ���ĳɼ�\n");
		printf("\t\t15.���ǰ����ѧ���ĳɼ�\t");
		printf("16.�˳�\n");
		
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
	printf("\t\t\t��ӭ����ѧ����Ϣ����ϵͳ!\n");
	printf("\t\t\t*************************\n");
	Import();
	Import_Score();
	//stu.len = 0;
	menu();
	
}

