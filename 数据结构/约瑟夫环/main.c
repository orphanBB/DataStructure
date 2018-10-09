/**
题目描述：
有一个游戏叫约瑟夫环，大家一起玩啊~
游戏规则如下：
1、n个人围在一起坐成环状；
2、从编号为1的人开始报数；
3、报到m的时候，此人出列，下一个人重新从1开始报数；
4、一直循环，直到所有人出列，游戏结束。
输入总人数n和数m，产生编号1-n，开始报数，输出最后一个出列的人的编号。
（出题人：潘理）

输入样式：
3 2

说明：
第一个数3是总人数，分别编号1，2，3
第二个数2表示，报数到第2个人，出列

输出样式：
3

说明：
输出结果是：最后出列的人的编号
**/
#include <stdio.h>
#include <stdlib.h>
int ysfdg(int sum,int value,int n);

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",ysfdg(n,m,n)+1);
    return 0;
}

int ysfdg(int sum,int value,int n)
{
    if(n==1)
        return (sum+value-1)%sum;
    else
        return (ysfdg(sum-1,value,n-1)+value)%sum;
}

