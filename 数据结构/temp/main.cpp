#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode_JCB
{
    int arrive_time;
    int serve_time;
    int finish_time;
    int turnover_time;
    struct LNode_JCB *next;
}LNode_JCB , *LinkList;

int main()
{
    //声明
    void  CreateList_L(LinkList &L , int n);
    void  ListSort(LinkList &L);
    void simulate_cpu_dispatch(LinkList &L);
    void ListSort2(LinkList  &L);
    void FCFS(LinkList &L , int n);
    void SJF(LinkList &L , int n);
    LinkList L;  int n=5;

    //先来先服务
    FCFS(L , n);
    //短作业优先
    SJF(L,n);
    return 0;
}

void   CreateList_L(LinkList &L , int n)
{
    L = (LinkList)malloc(sizeof(LNode_JCB));
    L->next = NULL;
    for(int i=n ; i>0 ; --i)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode_JCB));
        cout<<"***************************输入第"<<n-i+1<<"的作业到达时间"<<endl;
        cout<<"                            ";
        cin>>p->arrive_time;
        cout<<"***************************输入第"<<n-i+1<<"个作业的服务时间"<<endl;
        cout<<"                            ";
        cin>>p->serve_time;
        p->next = L->next;
        L->next = p;
    }
}

void ListSort(LinkList  &L)  //单链表排序    基于先来先服务算法排序
{
    LinkList p, q;
    int t;
    p = L->next;
    while (p)
    {
        q = p->next;
        while (q)
        {
            if (p->arrive_time > q->arrive_time)
            {
                t = p->arrive_time;
                p->arrive_time = q->arrive_time;
                q->arrive_time = t;

                t = p->serve_time;  //在排序时对服务时间也要交换
                p->serve_time = q->serve_time;
                q->serve_time = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}


void ListSort2(LinkList  &L)  //单链表排序   基于短作业优先算法排序
{
    LinkList p, q;
    int t;
    p = L->next;
    while (p)
    {
        q = p->next;
        while (q)
        {
            if (p->serve_time > q->serve_time)
            {
                t = p->serve_time;
                p->serve_time = q->serve_time;
                q->serve_time = t;

                t = p->arrive_time;  //到达时间也要交换
                p->arrive_time = q->arrive_time;
                q->arrive_time = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void simulate_cpu_dispatch(LinkList &L)
{
    LinkList p = L->next;
    p->finish_time = p->arrive_time +  p->serve_time;
    p->turnover_time = p->finish_time - p->arrive_time;
    while(p->next)
    {
        if(p->next->arrive_time >= p->finish_time)
        {
            p->next->finish_time = p->next->arrive_time +  p->next->serve_time;
            p->next->turnover_time = p->next->finish_time - p->next->arrive_time;
            p = p->next;
        }
        else
        {
            p->next->finish_time = p->finish_time + p->next->serve_time;
            p->next->turnover_time = p->next->finish_time - p->next->arrive_time;
            p = p->next;
        }
    }
}

void  FCFS(LinkList &L , int n)
{
    cout<<"                           ";
    cout<<"实现作业调度算法//基于先来先服务,模拟cpu运行环境"<<endl;
    CreateList_L(L , n);//构造单链表
    ListSort(L);//单链表排序
    simulate_cpu_dispatch(L);
    L = L->next;
    int i=5;
    while(L)
    {
        cout<<endl<<endl<<endl;
        cout<<"///////////////////////////第"<<i-5+1<<"个进入cpu的作业://////////////////////////////"<<endl;
        cout<<"                           到达时间"<<L->arrive_time<<endl<<endl;
        cout<<"                           服务时间"<<L->serve_time<<endl<<endl;
        cout<<"                           完成时间"<<L->finish_time<<endl<<endl;
        cout<<"                           周转时间"<<L->turnover_time<<endl<<endl;
        i++;
        L= L->next;
    }
}

void  SJF(LinkList &L , int n)
{
    cout<<"                           ";
    cout<<"实现作业调度算法//基于短作业优先算法,模拟cpu运行环境"<<endl;
    CreateList_L(L , n);//构造单链表
    ListSort2(L);//单链表排序
    simulate_cpu_dispatch(L);
    L = L->next;
    int i=5;
    while(L)
    {
        cout<<"///////////////////////////第"<<i-5+1<<"个进入cpu的作业://////////////////////////////"<<endl;
        cout<<"                           到达时间"<<L->arrive_time<<endl<<endl;
        cout<<"                           服务时间"<<L->serve_time<<endl<<endl;
        cout<<"                           完成时间"<<L->finish_time<<endl<<endl;
        cout<<"                           周转时间"<<L->turnover_time<<endl<<endl;
        i++;
        L= L->next;
    }
}
