/*
��Ŀ������
����n���ڵ�Ķ��������ڵ���Ϊ0, ..., n-1���ö������ṹ�þ�̬�����ʾ����������ĺ���������С�
0    1    2
1    3    4
2    5   -1
3   -1   -1
4   -1   -1
5   -1   -1
��һ��Ϊ�ڵ��ţ��ڶ���Ϊ�ýڵ�����ӱ�ţ�������Ϊ�Һ��ӱ�š�-1��ʾû�к��ӡ�
�������ˣ�����

������ʽ��
6
1   2
3   4
5  -1
-1 -1
-1 -1
-1 -1

˵����
��һ�б�ʾ�������Ľڵ���n��n<100��������ÿһ�еĽڵ���Ϊ0, ..., n-1��
�ڶ��п�ʼ��ÿһ���������֣��ֱ��ʾ�ýڵ�������������ӵĽڵ��š�
���磺�ڶ��е�����1��2����ʾ�ڵ�0������Ϊ�ڵ�1���Һ���Ϊ�ڵ�2��

�����ʽ��
3 4 1 5 2 0
˵����
��ʾ��������Ľڵ����С�
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
        printf("%d ",t->data);  //��ʾ���
        dispnodes(t->left); //��
        dispnodes(t->right); //��
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

//void postorder(Node *t)   //�������
//{
//    if(t!=NULL)
//    {
//        postorder(t->left);
//        postorder(t->right);
//        printf("%c ",t->data);
//    }
//}
