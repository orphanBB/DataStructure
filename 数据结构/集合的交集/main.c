/**
��Ŀ������
��֪A��B�ֱ��ʾ�����ǿռ��ϣ���Ԫ�ص������С���һ��������A��B�Ľ�����Ԫ�ظ���.
�������ˣ�����

������ʽ��
5 1 2 3 4 5
4 1 3 6 8

˵����
��һ�е�һ������A�ĸ���������ΪA������Ԫ�أ�
�ڶ��е�һ������B�ĸ���������ΪB������Ԫ��

�����ʽ��
2

˵����
A��B�Ľ�����Ԫ�ظ���
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lenA=10,lenB=10;
    int A[lenA],B[lenB];
    int i,j,k;
    scanf("%d",&lenA);
    for(i=0;i<lenA;i++)
        scanf("%d",&A[i]);
    scanf("%d",&lenB);
    for(i=0;i<lenB;i++)
        scanf("%d",&B[i]);
    i=0,j=0,k=0;
    while(i!=lenA&&j!=lenB)
    {
        if(A[i]==B[j])
        {
            i++;
            j++;
            k++;
        }
        else if(A[i]>B[j])
            j++;
        else if(A[i]<B[j])
            i++;
    }
    printf("%d",k);
    return 0;
}
