/*
��Ŀ������
����һ��n*n�����̣���������һЩλ�ò��ܷŻʺ�����Ҫ��������
����n���ڻʺ��n���׻ʺ�ʹ����������ڻʺ󶼲���ͬһ�С�ͬһ
�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ
���Խ����ϡ����ܹ��ж����ַŷ���(n<=20)

�����ʽ
����ĵ�һ��Ϊһ������n����ʾ���̵Ĵ�С��
������n�У�ÿ��n��0��1�����������һ������Ϊ1����ʾ��Ӧ��λ��
���ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�

�����ʽ
���һ����������ʾ�ܹ��ж����ַŷ���

������ʽ��
4
1  1  1  1
1  1  1  1
1  1  1  1
1  1  1  1

�����ʽ��
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
