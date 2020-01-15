#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 3 //配置组数
typedef struct config
{
    char con_name[10];  //配置名词
    float con_power;    //配置功率
    float con_band[3];  //配置带宽
    float matrix[3][3]; //配置矩阵值
    bool con_FN;        //是否跳频
} Tyconfig;
Tyconfig con[N] = {{"First", 256, {33, 22, 11}, 11, 12, 13, 12, 13, 14, 13, 14, 15},
                   {"second", 316, {51, 32, 21}, 14, 18, 19, 8, 19, 24, 23, 21, 25},
                   {"third", 256, {33, 22, 11}, 11, 12, 13, 12, 13, 14, 13, 14, 15}};
void output(Tyconfig config[]) //1.输出三组配置的默认值(遍历)
{
    int i, j, k, k1;
    for (i = 0; i < N; i++)
    {
        printf("1>  config name:%s\n", config[i].con_name);
        printf("config power%-6.2f\n", config[i].con_power);
        printf("The bandwidth value:\n");
        for (j = 0; j < 3; j++)
        {
            printf("%-6.2f", config[i].con_band[j]);
        }
        printf("\n");
        // 输出矩阵值
        printf("Matrix values:\n");
        for (k = 0; k < 3; k++)
        {
            for (k1 = 0; k1 < 3; k1++)
            {
                printf("%-6.2f", config[i].matrix[k][k1]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void swop(Tyconfig *con, int n, int m)//2.第一组和第二组配置进行交换，然后输出第一组的值
{
    //对第一组配置和第二组配置进行交换
    Tyconfig *temp = malloc(sizeof(*con)); //?
    *temp = *(con + n);
    *(con + n) = *(con + m);
    *(con + m) = *temp;
    //输出交换后的第一组配置
    printf("2>  config name:%s\n", con->con_name);
    printf("config power%-6.2f\n", con->con_power);
    printf("The bandwidth value:\n");
    int i, j;
    for (j = 0; j < 3; j++)
    {
        printf("%-6.2f", con->con_band[j]);
    }
    // 输出交换后的矩阵值
    printf("Matrix values:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%-6.2f", con->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void power_max(Tyconfig con[])//3.输出功率最大的一组配置
{
    float max = 0;
    int i, count;
    for (i = 0; i < N; i++)
    {
        if (con[i].con_power > max)
        {
            max = con[i].con_power;
            count = i;
        }
    }
    printf("3>  max power is:%d\n", count);
    //输出功率最大的一组配置
    printf("config name:%s\n", con[count].con_name);
    printf("config power%-6.2f\n", con[count].con_power);
    printf("The bandwidth value:\n");
    int j;
    for (j = 0; j < 3; j++)
    {
        printf("%-6.2f", con[count].con_band[j]);
    }
    // 输出功率最大的一组矩阵值
    printf("Matrix values:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%-6.2f", con[count].matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void NO_3_matrix(Tyconfig con[], int n)//4.输出第三组的矩阵值
{
    float(*p)[3];
    p = con[n].matrix;
    //第三组的矩阵值
    printf("4>  Matrix values:\n");
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%-6.2f", *(*(p + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}
//5.输出10倍功率；嵌套函数输出。
void a(Tyconfig con[], int n)
{
    printf("5>  Third group power *10:%-6.2f\n", (con[n].con_power) * 10);
}
void b(Tyconfig con[], int n)
{
    printf("    Third group power -10:%-6.2f\n", (con[n].con_power) - 10);
}
void A(Tyconfig *con, int n)
{
    a(con, n);
    b(con, n);
}
int main()
{
    Tyconfig *p;
    p = con;
    output(p);
    swop(p, 0, 1);
    power_max(p);
    NO_3_matrix(p, 2);
    A(p,2);
    system("pause");
    return 0;
}
