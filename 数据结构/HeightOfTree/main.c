/*
题目描述：
给定二叉树，输出它的高度。用数组描述二叉树的结构（静态链表），对于第i行的两个数，代表编号为i的节点所连接的两个左右孩子的编号。
    │ 0 │  1 │ 2 │
    │ 1 │  3 │ 4 │
    │ 2 │ -1 │-1 │
    │ 3 │ -1 │-1 │
    │ 4 │ -1 │-1 │
如上表，下标0节点的两个数为1和2，表示它的左右孩子分别是下标1节点和下标2节点。若没有某孩子，则用-1表示。
（出题人：潘理）

输入样式：
5
1 2
3 4
-1 -1
-1 -1
-1 -1
说明：
第一行为二叉树的节点个数（0 < n < 100 ）；
下面每一行的两个数字，表示该节点的左右孩子节点编号。

输出样式：
3
说明：

该二叉树的高度
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tree[100][2];
void judge(int tree[100][2],int n);

int main()
{
    int n;  //最大树高
    double height=0;  //最后的结果
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)     //输入
    {
        scanf("%d %d",&tree[i][0],&tree[i][1]);
    }
    judge(tree,n);  //用于判断会不会出现空孩子的后面接了孩子，如果出现了，则把后面的赋-1
    for(i=0;i<n;i++)  //得到最高节点数
    {
        for(j=0;j<2;j++)
        {
            if(tree[i][j]>height)
                height=tree[i][j];
        }
    }
    if(height==0)  //没有孩子时输出1，即只有0一个节点的时候
        printf("1");
    else
    {
        height=log(height+1)/log(2)+1;   //计算
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
//用作测试
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
