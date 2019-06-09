/*
题目描述：
给定一个n个顶点，m条边的有向图（其中某些边权可能为负，但保证没有负环）。
请你计算从1号点到其他点的最短路（顶点从1到n编号）。

输入
第一行两个整数n, m。
接下来的m行，每行有三个整数u, v, l，表示u到v有一条长度为l的边。

输出
共n-1行，第 i 行表示1号点到 i+1 号点的最短路。

输入样式：            输出样式：
3 3                   -1
1 2 -1                -2
2 3 -1
3 1 2
*/

#include "iostream"

using namespace std;

int main()
{

    return 0;
}



















/*
#include <iostream>
#include "stdlib.h"
#define MAX 100

using namespace std;

//边节点
typedef struct Node{
    int u;     //边的前一个顶点
    int v;     //边的后一个顶点
    int l;     //边权
    int flag;
}Path;

int n,m;  //顶点数和边数
Path path[MAX];

void find_min_path(int a)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(a==path[i].u&&path[i].flag!=0)
        {

        }
    }
}

int main()
{
    int i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        path[i].flag=0;
        cin >> path[i].u >> path[i].v >> path[i].l;
    }

//    //数据输入测试
//    for(i=0;i<m;i++)
//    {
//        cout<<"第"<<i+1<<"个:"<<endl;
//        cout<<path[i].u<<" ";
//        cout<<path[i].v<<" ";
//        cout<<path[i].l<<" "<<endl;
//    }
    system("pause");
    return 0;
}
*/
