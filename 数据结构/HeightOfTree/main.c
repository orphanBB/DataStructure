/*
��Ŀ������
������������������ĸ߶ȡ������������������Ľṹ����̬���������ڵ�i�е���������������Ϊi�Ľڵ������ӵ��������Һ��ӵı�š�
    �� 0 ��  1 �� 2 ��
    �� 1 ��  3 �� 4 ��
    �� 2 �� -1 ��-1 ��
    �� 3 �� -1 ��-1 ��
    �� 4 �� -1 ��-1 ��
���ϱ��±�0�ڵ��������Ϊ1��2����ʾ�������Һ��ӷֱ����±�1�ڵ���±�2�ڵ㡣��û��ĳ���ӣ�����-1��ʾ��
�������ˣ�����

������ʽ��
5
1 2
3 4
-1 -1
-1 -1
-1 -1
˵����
��һ��Ϊ�������Ľڵ������0 < n < 100 ����
����ÿһ�е��������֣���ʾ�ýڵ�����Һ��ӽڵ��š�

�����ʽ��
3
˵����

�ö������ĸ߶�
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tree[100][2];
void judge(int tree[100][2],int n);

int main()
{
    int n;  //�������
    double height=0;  //���Ľ��
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)     //����
    {
        scanf("%d %d",&tree[i][0],&tree[i][1]);
    }
    judge(tree,n);  //�����жϻ᲻����ֿպ��ӵĺ�����˺��ӣ���������ˣ���Ѻ���ĸ�-1
    for(i=0;i<n;i++)  //�õ���߽ڵ���
    {
        for(j=0;j<2;j++)
        {
            if(tree[i][j]>height)
                height=tree[i][j];
        }
    }
    if(height==0)  //û�к���ʱ���1����ֻ��0һ���ڵ��ʱ��
        printf("1");
    else
    {
        height=log(height+1)/log(2)+1;   //����
        printf("%d",(int)height);
    }
    return 0;
}

void judge(int tree[100][2],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            if(tree[i][j]==-1)
            {
                if(j==0)
                {
                    tree[(i+1)*2-1][0]=-1;
                    tree[(i+1)*2-1][1]=-1;
                }
                if(j==1)
                {
                    tree[(i+1)*2][0]=-1;
                    tree[(i+1)*2][1]=-1;
                }
            }
        }
    }
}
//��������
void show(int tree[100][2],int n);

void show(int tree[100][2],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",tree[i][j]);
        }
        printf("\n");
    }
}
