#include "link.h"
#include <stdio.h>
#include <stdlib.h>
STU stu;

void menu()
{ 
	Import();
	int flag;
	while (1)
	{
		
		printf("\t��ѡ����Ĳ�����\n");
		printf("\t\t\t1.����ѧ����Ϣ  ");
		printf("2.�������ѧ����Ϣ\n");
		printf("\t\t\t3.ͨ��ѧ�Ų�ѯ��Ϣ  ");
		printf("4.ͨ��������ѯ��Ϣ\n");
		printf("\t\t\t5.ͨ����ϵ��ʽ��ѯ��Ϣ  ");
		printf("6.����ѧ����Ϣ\n");
		printf("\t\t\t7.ͨ��ѧ��ɾ��  ");
		printf("8.ͨ������ɾ��\n");
		printf("\t\t\t9.ͨ���༶��ѯ");
		printf("10.¼��ѧ���ɼ�\n");
		printf("\t\t\t11.�޸�ѧ���ɼ�");
		printf("12.�鿴ѧ���ɼ�\n");
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


		}

	}
	
}



int main()
{
	printf("\t\t\t*************************\n");
	printf("\t\t\t��ӭ����ѧ����Ϣ����ϵͳ!\n");
	printf("\t\t\t*************************\n");

	//stu.len = 0;
	menu();
	
}

