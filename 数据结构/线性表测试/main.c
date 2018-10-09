/*******
给定一个N个数的数组，M次操作，求最后的数组。每次操作为下列操作之一：
操作1：在第X个数之后插入一个数Y。
操作2：删除第X个数。
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
*/

#include <stdio.h>
int arr[100];
int N;
void ins(int x,int y);
void del(int x);
void display();
int main()
{
    int M;
    int i;
    int option,x,y;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<M;i++)
    {
        scanf("%d",&option);
        if(option==1)
        {
            scanf("%d %d",&x,&y);
            ins(x,y);
        }
        else if(option==2)
        {
            scanf("%d",&x);
            del(x);
        }
    }
    display();
    return 0;
}
void ins(int x,int y)
{
    int i=N;
    while(i!=x)
    {
        arr[i]=arr[i-1];
        i--;
    }
    arr[x]=y;
    N++;
}
void del(int x)
{
    int i;
    for(i=x;i<N;i++)
        arr[i-1]=arr[i];
    N--;
}
void display()
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
}
