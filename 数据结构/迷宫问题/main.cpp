/*
����һ��N*N(2<=N<10)������Թ�����ںͳ��ڷֱ������ϽǺ����Ͻǡ�
�Թ������зֱ��0��1��0��ʾ��ͨ��1��ʾ���ܣ���ںͳ��ڴ��϶���0��
�Թ��ߵĹ���������ʾ������ĳ�㿪ʼ���а˸�������ߣ�ǰ��������
����Ϊ0ʱ��ʾ��ͨ����Ϊ1ʱ��ʾ����ͨ����Ҫ����·�����ҳ����д�
��ڣ����Ͻǣ������ڣ����Ͻǣ���·��(�����ظ�)�����·��������
����޷���������0��
*/
#include <iostream>
#include "cstdio"
#include "cmath"
#define MAX 10
using namespace std;

int N;               //�Թ��Ľ���
int map[MAX][MAX];   //��ά���鱣���Թ���ͼ��0Ϊ���ߣ�1Ϊ������
int entrance[2];     //������� entrance[0]Ϊ�����꣬entrance[1]Ϊ������
int exit[2];         //�������� exit[0]exit[1]Ϊ������

void input()
{
    int i,j,k=0;
    int temp[100];
    FILE *fp;
    if((fp=fopen("maze_map.txt","rb"))==NULL)
    {
        printf("�������Թ��Ľ�����");
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
    }
    else
    {
        for(i=0;!feof(fp);i++)
        {
            fscanf(fp,"%d",&temp[i]);
        }
        N=sqrt(i);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                map[i][j]=temp[k];
                k++;
            }
        }
    }
    //��������ڵ�ͼ�����е�λ�ã��±꣩
    entrance[0]=1,entrance[1]=0;  //��ʼ���������Ϊ�ڶ��е�һ��
    exit[0]=N-2,exit[1]=N-1;      //��ʼ����������Ϊ�����ڶ������һ��
}

int main()
{
    int i,j;
    input();
//    for(i=0;i<N;i++)
//    {
//        for(j=0;j<N;j++)             //�������
//        {
//            printf("%d ",map[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}
