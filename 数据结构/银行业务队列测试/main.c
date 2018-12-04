/*
题目描述:
一天，小明来银行办业务。这个银行有A、B两个业务窗口，且处理业务的速度不一样，
其中A窗口处理速度是B窗口的2倍——即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。
给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。

输入样式:
5 2 1 4 3 5

说明
输入为一行正整数，其中第1个数字N(<=1000)为顾客总数，后面跟着N位顾客的编号。
编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。
数字间以空格分隔。

输出样式：
1 3 2 5 4

说明：
按业务处理完成的顺序输出顾客的编号。数字间以空格分隔（最后一个编号后不能有多余的空格）。
当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。
*/

#include <stdio.h>
#include <stdlib.h>

struct queue{
    int No;
    struct queue* pre;
    struct queue* next;
};
typedef struct queue Queue;

void add_queue(Queue* Q,int x);
int del_queue(Queue* Q);
Queue* createQueue();
void show_queue(Queue* Q);
int is_empty(Queue* Q);

int main()
{
    int N,i,temp;
    Queue *A,*B;
    A=createQueue();
    B=createQueue();
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&temp);
        if(temp%2==1)
            add_queue(A,temp);
        else if(temp%2==0)
            add_queue(B,temp);
    }
    while(is_empty(A)!=1&&is_empty(B)!=1)
    {
        if(is_empty(A)!=1)
        {
            printf("%d",del_queue(A));
        }
        if(is_empty(A)!=1&&is_empty(B)!=1)
        {
            printf(" ");
        }
        if(is_empty(A)!=1)
        {
            printf("%d",del_queue(A));
        }
        if(is_empty(A)!=1&&is_empty(B)!=1)
        {
            printf(" ");
        }
        if(is_empty(A)==1&&is_empty(B)!=1)
        {
            printf(" ");
        }
        if(is_empty(B)!=1)
        {
            printf("%d",del_queue(B));
        }
        if(is_empty(A)!=1&&is_empty(B)!=1)
        {
            printf(" ");
        }
    }
    return 0;
}

void add_queue(Queue* Q,int x)
{
    Queue* t;
    t=(Queue*)malloc(sizeof(Queue));
    t->No=x;
    t->next=Q;
    t->pre=Q->pre;
    Q->pre->next=t;
    Q->pre=t;
}

int del_queue(Queue* Q)
{
    Queue* t=Q->next;
    int x=t->No;
    t->next->pre=Q;
    Q->next=t->next;
    free(t);
    return x;
}

Queue* createQueue()
{
    Queue* Q=(Queue*)malloc(sizeof(Queue));
    Q->next=Q;
    Q->pre=Q;
    return Q;
}

int is_empty(Queue* Q)
{
    if(Q->next==Q)
        return 1;
    return 0;
}

void show_queue(Queue* Q)
{
    Queue* t=Q->next;
    while(t!=Q)
    {
        printf("%d ",t->No);
        t=t->next;
    }
}
