/*
题目描述：
在一个字符串王国里生活着许许多多的字符串，如:abcde、adfsddf、dss等等。
有一天王国的国王召集了许多对双胞胎举行一场神圣的仪式（如果两串字符串
相同，它们就被认为是双胞胎）。但不幸的是意外出现了，有一个不法分子（当
然也是字符串）乘机混在了双胞胎里想要制造爆炸事件，场面非常混乱。所幸
的是不法分子只有一个，你能帮助国王赶在不法分子安好炸弹前找出他并阻止他
的计划么？

Input：
第一行输入一个奇数n，表示有n个字符串(n<100)。
接下来n行每行输入一个字符串。
输入保证只有一个独一无二的字符串，其他都是成双出现的(字符串长度不超过100)。

Output：输出那个独一无二的字符串

输入样式：
5
saf
dfdsf
saf
dff
dfdsf

输出样式：
dff
*/


#include <iostream>
#include "string.h"
#define MAX 100
using namespace std;

int main()
{
    char str[MAX][MAX];
    int flag[MAX];
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>str[i];
        flag[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((!strcmp(str[i],str[j]))&&flag[i]!=1&&flag[j]!=1)
            {
                flag[i]=1;
                flag[j]=1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(flag[i]!=1)
            cout<<str[i];
    }
    return 0;
}
