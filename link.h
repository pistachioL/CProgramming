#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
typedef struct Student_Info
{
	char Sno[30];
	char Sname[30];
	char Gender[30];
	char Class[30];
	char Birthday[30];   //1999/11/13
	char Phone[30];
	char Address[30];
	double Score[6];   //6�ſγ̵ĳɼ�
	double Average;
	double Sum;
};

typedef struct
{
	Student_Info student[20000];   //student[i]��ʾ��i��ѧ��
	int len;  //ѧ������
}STU;
extern STU stu;



void Import();
void Search_All_Info();
void Search();
void Create();
void Delete();
void Update();


int ConvertToInt(char *a);
#endif
