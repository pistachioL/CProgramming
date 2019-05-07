#include "link.h"
Student_Info temp;
void SortBySno()
{
	for (int i = 1;i <= stu.len;i++)
	{
		for (int j = i + 1;j <= stu.len;j++)
		{
			if (stu.student[i].SID > stu.student[j].SID)   //Ñ§ºÅÉıĞòÊä³ö
			{
				temp = stu.student[i];
				stu.student[i] = stu.student[j];
				stu.student[j] = temp;
			}
		}
	}
}

void SortByClass()
{
	for (int i = 1;i <= stu.len;i++)
	{
		for (int j = i + 1;j <= stu.len;j++)
		{
			if (stu.student[i].Class > stu.student[j].Class)   //°à¼¶½µĞòÊä³ö
			{
				temp = stu.student[i];
				stu.student[i] = stu.student[j];
				stu.student[j] = temp;
			}
		}
	}
}

void SortByName()
{
	for (int i = 1;i <= stu.len;i++)
	{
		for (int j = i + 1;j <= stu.len;j++)
		{
			if (((int)stu.student[i].Sname[0] > (int)stu.student[j].Sname[0]))
			{
				temp = stu.student[i];
				stu.student[i] = stu.student[j];
				stu.student[j] = temp;
			}
		}
	
	}
}

void Sort_By_Score()
{
	Student_Info t;
	for (int i = 1;i <= stu.len;i++)
	{
		for (int j = i;j <= stu.len;j++)
		{
			if (stu.student[i].Sum < stu.student[j].Sum)
			{
				/*
				t = stu.student[i].Sum;
				stu.student[i].Sum = stu.student[j].Sum;
				stu.student[j].Sum = t;*/
				t = stu.student[i];
				stu.student[i] = stu.student[j];
				stu.student[j] = t;
			}
		}
	}
	
}