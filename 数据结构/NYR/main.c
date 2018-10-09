/**
题目描述：
给定一个N个数的数组，M次操作，求最后的数组。每次操作为下列操作之一：
操作1：在第X个数之后插入一个数Y。
操作2：删除第X个数。
（出题人：潘理）

输入样式：
5 3
1 2 3 4 5
1 1 6
2 1
2 2

说明：每行数字之间用空格分隔
第一行两个整数N，M（N，M≤100000）含义见题目描述。
第二行N个整数，表示原来的数组。
接下来M行，每行第一个数，表示操作类型。
对于操作1，接下来两个数X，Y，含义见题面描述，保证0≤X≤当前数组的个数，若X=0，表示在数组开头插入。
对于操作2，接下来一个数X，含义见题面描述，保证1≤X≤当前数组的个数。

输出样式：
6 3 4 5

说明：输出结果为最终的数组，数组中每个数字之间用空格分隔。
**/

#include <stdio.h>

int main()
{
    int N=20,M;          //题中的N，M
    int a[N];         //数组  长度为N
    int i,j;            //循环变量
    int operate;      //操作数变量
    int x,y;          //对应题中的x，y
    scanf("%d %d",&N,&M);    //接收输入的N,M值
    //以下for循环用于输入数据到数组中
    for(i=0;i<N;i++)   //从下标为0开始，到下标为N-1结束
    {
        scanf("%d",&a[i]);
    }
    //for循环进行对应M操作次数的操作
    for(i=0;i<M;i++)
    {
        scanf("%d",&operate);   //获取操作数，以判断进行相应的操作  1为插入  2为删除
        //以下为插入
        if(operate==1)   //判断输入的操作数为1  对应的插入操作
        {
            scanf("%d %d",&x,&y);   //获取x,y的值
            N++;    //先把数组长度增加
            for(j=N;j!=x;j--)    //然后从下标为N的移到N+1  N-1的移到N  以此类推直到下标为x(即序号为x)
            {
                a[j]=a[j-1];
            }
            a[x]=y;       //下标为X-1的序号才是x  所以把y值赋给下标为x的就是在序号为x的数后面插入y
        }
        //以下为删除
        if(operate==2)
        {
            scanf("%d",&x);          //输入需要删除的元素的序号
            for(j=x;j<N;j++)        //删除  直接覆盖  序号为x即下标为x-1  用下标为x的覆盖x-1的  就删除了
            {
                a[j-1]=a[j];
            }
            N--;         //数组长度减1
        }
    }
    for(i=0;i<N;i++)        //输出对应数组长度的最后结果
        printf("%d ",a[i]);
}







/*
#include <stdio.h>

int main()
{
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    char input[8];
    int year,month,day;
    int result=0;
    int i;
    gets(input);
    year=input[0]*1000+input[1]*100+input[2]*10+input[3]-53328;
    month=input[4]*10+input[5]-528;
    day=input[6]*10+input[7]-528;
    if((year%4==0&&year%100!=0)||year%400==0)
        a[2]=29;
    for(i=0;i<month;i++)
    {
        result=result+a[i];
    }
    result+=day;
    printf("%d",result);
    return 0;
}
*/
