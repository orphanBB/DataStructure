/**
��Ŀ������
��֪A��B�ֱ��ʾ�����ǿռ��ϣ���Ԫ���������С���һ��������A��B��Ԫ�ظ�������2000�Ϸʹ�ҵ��ѧ�����⣨8�֣���
�������ˣ�����

������ʽ��
5 2 3 4 5 6
4 1 2 5 8

˵����
��һ�е�һ������A�ĸ���������ΪA������Ԫ�أ�
�ڶ��е�һ������B�ĸ���������ΪB������Ԫ�ء�

�����ʽ��
7

˵����
A��B�Ĳ�����Ԫ�ظ���**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lenA=10,lenB=10;
    int A[lenA],B[lenB];
    int i,j,k=0,len;
    scanf("%d",&lenA);
    for(i=0;i<lenA;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&lenB);
    for(i=0;i<lenB;i++)
    {
        scanf("%d",&B[i]);
    }
    for(i=0;i<lenA;i++)
    {
        for(j=0;j<lenB;j++)
        {
            if(A[i]==B[j])
                k++;
        }
    }
    len=lenA+lenB-k;
    printf("%d",len);
    return 0;
}

