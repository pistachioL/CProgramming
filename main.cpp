#include "link.h"
#include <stdio.h>
#include <stdlib.h>
STU stu;
void menu()
{
	printf("\t\t\t*************************\n");
	printf("\t\t\t��ӭ����ѧ����Ϣ����ϵͳ!\n");
	printf("\t\t\t*************************\n");
	printf("��ѡ����Ĳ�����\n");
	printf("\t\t\t1.����ѧ����Ϣ  ");
	printf("2.��ѯѧ����Ϣ\n");
	printf("\t\t\t3.�޸�ѧ����Ϣ  ");
	printf("4.���ѧ����Ϣ\n");
	//printf("\t\t\t5.ɾ��ѧ����Ϣ  ");
	

	int flag;
	scanf("%d", &flag);


	switch (flag)
	{
	
	case 2:
		Import();
		Search_All_Info();
		break;
	}
	
}

int main()
{
	stu.len = 0;
	menu();
}

