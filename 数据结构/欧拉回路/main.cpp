/*
题目描述：
欧拉回路是指不令笔离开纸面，可画过图中每条边仅一次，且可以回到起点的一条回路。
现给定一个图，问是否存在欧拉回路？

输入
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是节点数N ( 1 < N <= 1000 )和边数M；
随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号（节点从1到N编号）。当N为0时输入结束。

输出
每个测试用例的输出占一行，若欧拉回路存在则输出1，否则输出0。

输入样式：
3 3
2 3
1 2
1 3
3 2
1 2
2 3
0

输出样式：
1
0
*/

#include <iostream>
#include <stdio.h>
#define N 1001
using namespace std;

int map[N][N];
bool visited[N];
int cheak[N];
int n,i;

void DFS(int k)
{
	visited[k]=1;
	for(i=1;i<=n;i++)
		if(!visited[i]&&map[k][i])
	    	DFS(i);

		return;
}
int  cheakk()
{
	for(i=1;i<=n;i++)
		if(cheak[i]%2)
			return 0;

		return 1;
}
int main()
{
	int m,i,a,b,k=0;
	int res[N];
	while(cin>>n&&n)
	{
		cin>>m;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=map[b][a]=1;

			cheak[a]++;
			cheak[b]++;

		}

		DFS(1);

		for(i=1;i<=n;i++)
			if(!visited[i])
				break;
		if(i>n&&cheakk())
        {
            res[k]=1;
            k++;
        }
		else
        {
            res[k]=0;
            k++;
        }
	}
	for(i=0;i<k;i++)
        cout<<res[i]<<endl;
	return 0;
}
