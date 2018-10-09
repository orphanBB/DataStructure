/**
题目描述：
已知A和B分别表示两个非空集合，其元素升序排列。编一函数，求A∪B的元素个数。【2000合肥工业大学考研题（8分）】
（出题人：潘理）

输入样式：
5 2 3 4 5 6
4 1 2 5 8

说明：
第一行第一个数是A的个数，后面为A的所有元素；
第二行第一个数是B的个数，后面为B的所有元素。

输出样式：
7

说明：
A与B的并集的元素个数**/
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

