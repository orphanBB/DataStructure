/*
��Ŀ������
ŷ����·��ָ������뿪ֽ�棬�ɻ���ͼ��ÿ���߽�һ�Σ��ҿ��Իص�����һ����·��
�ָ���һ��ͼ�����Ƿ����ŷ����·��

����
��������������ɲ���������ÿ�����������ĵ�1�и����������������ֱ��ǽڵ���N ( 1 < N <= 1000 )�ͱ���M��
����M�ж�ӦM���ߣ�ÿ�и���һ�����������ֱ��Ǹ�����ֱ����ͨ�������ڵ�ı�ţ��ڵ��1��N��ţ�����NΪ0ʱ���������

���
ÿ���������������ռһ�У���ŷ����·���������1���������0��

������ʽ��
3 3
2 3
1 2
1 3
3 2
1 2
2 3
0

�����ʽ��
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
