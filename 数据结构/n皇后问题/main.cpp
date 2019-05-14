/*
题目描述：
给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中
放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一
列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一
条对角线上。问总共有多少种放法？(n<=20)

输入格式
输入的第一行为一个整数n，表示棋盘的大小。
接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置
可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。

输出格式
输出一个整数，表示总共有多少种放法。

输入样式：
4
1  1  1  1
1  1  1  1
1  1  1  1
1  1  1  1

输出样式：
2
*/
#include <iostream>
#include "stdlib.h"
#include "math.h"
#define MAX 20

using namespace std;

int n;
int qipan[MAX][MAX];
int col[MAX];

int can_down(int x,int y)
{
    int i;
	for (i=0;i<n;i++)
	{
		if (qipan[i][0]==y||abs(i-x)==abs(col[i]-y))
			return 0;
	}
	return 1;
}

void queen(int n)
{
    int i=0,j=0;
    while(i<n)
    {
        while(j<n)
        {
            if(can_down(i,j))
            {
                col[i]=j;
                j=0;
                break;
            }
            else
                j++;
        }
        if(j==n)
        {
            if(i==0)
                break;
            else
            {
                i--;
                j=col[i]+1;
                col[i]=0;
            }
        }
    }
}

int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>qipan[i][j];
    }
    queen(n);
    for(i=0;i<n;i++)
        cout<<col[i]<<" ";
    return 0;
}
