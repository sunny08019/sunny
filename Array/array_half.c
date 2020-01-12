#include <stdio.h>
#include <stdlib.h>
//二分法查找
int half(int *p, int num, int n) //定义函数，p接收数组首地址，num为要查找的数字，n是数组长度
{
    int min, max, mid; //定义最大值，最小值和中间值
    min = 0;
    max = n - 1;
    while (min <= max) //査找范围不为0时执行循环体语句
    {
        mid = (min + max) / 2;//求中间位置
        if (num == *(p + mid)) //判断num是否和中间值相等
            return mid;        //是则返回mid
        if (num < *(p + mid))  //num小于中间值时
            max = mid - 1;     //确定数字在[min,mid-1]区间；
        else
            min = mid + 1; //确定数字在[mid+1,max]区间；
    }
    return 1; //若不在数组内，则返回1；
}
int JudgeNumber(int number)
{
    if (number % 2 == 0)
        printf("%d: is even\n", number);
    else
        printf("%d: is odd\n", number);
}
int main()
{
    int a[150], i, number, id;
    for (i = 0; i < 150; i++) //对数组a进行赋值
    {
        a[i] = i;
    }
    printf("Please enter the number for the query:");
    scanf("%d", &number);
    id = half(a, number, 150); //输入查询数字，并调用half函数
    if (id == 1)               //若返回值为1则不在数组内，判断数字奇偶性；
        JudgeNumber(number);
    else
        printf("This number is the:%d element in the array\n", id);
    system("pause");
    return 0;
}