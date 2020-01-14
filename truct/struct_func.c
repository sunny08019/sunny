#include <stdio.h>
#include <stdlib.h>
#define N 3 //学生数量
#define S 5 //课程数量
typedef struct hobby
{
    char hobby_name[30];
} Tyhobby;
typedef struct student
{
    char name[10];
    Tyhobby student_hobby[3];
    float score[5];
} Tystudent;
void Student_average(Tystudent student_score[]) //每个学生的平均成绩
{
    int i, j;
    float sum = 0, aver[N];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < S; j++)
        {
            sum += student_score[i].score[j];
        }
        aver[i] = sum / 5.0;
        sum = 0;
    }
    for (i = 0; i < N; i++)
    {
        printf("%s is grade point average:%-5.2f\n",student_score[i].name , aver[i]);
    }
    printf("\n");
}
void Subject_average(Tystudent student_score[]) //每门学科的平均成绩
{
    int i, j;
    float sum = 0, aver[S];
    for (i = 0; i < S; i++)
    {
        for (j= 0; j < N; j++)
        {
            sum += student_score[j].score[i];
        }
        aver[i] = sum / 3.0;
        sum = 0;
    }
    for (i = 0; i < S;i++)
    {
        printf("Grade point average in the %d subject:%-5.2f\n", i, aver[i]);
    }
    printf("\n");
}
Tystudent *intput()
{
}
void print(Tystudent student_[])//输出个人的爱好
{

    int i;
    for (i = 0; i < N; i++)
    {   
        printf("%s hobby:",student_[i].name);
        for(int j = 0;j<3;j++)
        {
            printf(",%s",student_[i].student_hobby[j].hobby_name) ;
        }
        printf("\n");
      //  printf(" ,%s",student_[i].student_hobby[i].hobby_name) ;
      //  printf(" ,%s\n",student_[i].student_hobby[i].hobby_name);
    }
    // Student_average(student_);
    // Subject_average(student_);
}
int main()
{
// char a[3]={'c'};
// ***************
//  char ab[3];  *
//   ab[2]='c';  *
// ***********   *
// char b[3];    *
// b[2]={'c'};     *
// int ab[3]={1,2,3}; *
//****************
// Tystudent stu[N];
// Tystudent stu[3];
// stu[1]={"XiaoMi", {"sing", "dance", "piano"}, {1, 2, 3, 4, 5}};
Tystudent  stu[N] = {
                {"XiaoMi", {"sing", "dance", "piano"}, {89, 87, 83, 74, 65}},
                {"XiaoLi", {"sing", "dance", "piano"}, {95,54,63,72,91}}, 
                {"XiaoAi", {"sing", "dance", "piano"}, {87,78,59,81,91}}
            };
Tystudent  *p = stu;
    Student_average(p);
    Subject_average(p);
    //  intput(p);
     print(p);
    system("pause");
    return 0;
}
