/**
题目描述：
已知A和B分别表示两个非空集合，其元素递增排列。编一函数，求A与B的交集的元素个数.
（出题人：潘理）

输入样式：
5 1 2 3 4 5
4 1 3 6 8

说明：
第一行第一个数是A的个数，后面为A的所有元素；
第二行第一个数是B的个数，后面为B的所有元素

输出样式：
2

说明：
A与B的交集的元素个数
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
