#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
typedef struct Student_Info
{
	int Sno;  //序号
	long long int SID;  //学号
	char Sname[30];
	char Gender[30];
	int  Class;
	char Birthday[30]; //1999/12/31
	char Phone[30];
	char Address[30];
	double Score[6]; //6门课程的成绩
	double Average;
	double Sum;
};

typedef struct
{
	Student_Info student[20000];//student[i]表示第i个学生
	int len;  //学生总数
}STU;
extern STU stu;

void menu();
//学生信息管理
void Import();

void Search_All_Info();
void Search_By_Sno();
void Search_By_Sname();
void Search_By_Phone();
void Search_By_Class();
void Insert();
void Delete_By_Sno();
void Delete_By_Name();
void Update();

void SortByClass();
void SortBySno();
void SortByName();

int ConvertToInt(char *a);
void ClearNextLine(char *s);
//成绩管理
void Import_Score();
void Input_Score();
void Update_Score();
void Check_Score();
void Sort_By_Score();
void Search_All_Score();
void Output_High_Score();
void Output_Top_Three();

void Save_In_File();
#endif
