/*
��Ŀ����:
һ�죬С�������а�ҵ�����������A��B����ҵ�񴰿ڣ��Ҵ���ҵ����ٶȲ�һ����
����A���ڴ����ٶ���B���ڵ�2����������A����ÿ������2���˿�ʱ��B���ڴ�����1���˿͡�
�����������еĹ˿����У��밴ҵ����ɵ�˳������˿����С�

������ʽ:
5 2 1 4 3 5

˵��
����Ϊһ�������������е�1������N(<=1000)Ϊ�˿��������������Nλ�˿͵ı�š�
���Ϊ�����Ĺ˿���Ҫ��A���ڰ���ҵ��Ϊż���Ĺ˿���ȥB���ڡ�
���ּ��Կո�ָ���

�����ʽ��
1 3 2 5 4

˵����
��ҵ������ɵ�˳������˿͵ı�š����ּ��Կո�ָ������һ����ź����ж���Ŀո񣩡�
����ͬ����ͬʱ������2���˿�ʱ��A���ڹ˿����������
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
