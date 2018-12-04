/*
题目描述：
给定n个节点的二叉树，节点编号为0, ..., n-1。该二叉树结构用静态链表表示，求二叉树的后序遍历序列。
0    1    2
1    3    4
2    5   -1
3   -1   -1
4   -1   -1
5   -1   -1
第一列为节点编号，第二列为该节点的左孩子编号，第三列为右孩子编号。-1表示没有孩子。
（出题人：潘理）

输入样式：
6
1   2
3   4
5  -1
-1 -1
-1 -1
-1 -1

说明：
第一行表示二叉树的节点数n（n<100），后续每一行的节点编号为0, ..., n-1。
第二行开始，每一行两个数字，分别表示该节点的左右两个孩子的节点编号。
例如：第二行的数字1和2，表示节点0的左孩子为节点1，右孩子为节点2。

输出样式：
3 4 1 5 2 0
说明：
表示后序遍历的节点序列。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newnode(int data, Node* l, Node* r)
{
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->left=l;
    p->right=r;
    return p;
}

void dispnodes(Node *t)
{
    if(t!=NULL)
    {
        printf("%d ",t->data);  //显示结点
        dispnodes(t->left); //左
        dispnodes(t->right); //右
    }
}

int main()
{
    int n;
    int i;
    int left,right;
    Node *tree;
    tree=newnode(0,NULL,NULL);
    scanf("%d",&n);
    scanf("%d %d",tree->left,tree->right);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&left,&right);
        tree=newnode(i,left,right);
    }
    return 0;
}

//void postorder(Node *t)   //后序遍历
//{
//    if(t!=NULL)
//    {
//        postorder(t->left);
//        postorder(t->right);
//        printf("%c ",t->data);
//    }
//}
