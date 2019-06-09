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
    //����
    void  CreateList_L(LinkList &L , int n);
    void  ListSort(LinkList &L);
    void simulate_cpu_dispatch(LinkList &L);
    void ListSort2(LinkList  &L);
    void FCFS(LinkList &L , int n);
    void SJF(LinkList &L , int n);
    LinkList L;  int n=5;

    //�����ȷ���
    FCFS(L , n);
    //����ҵ����
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
        cout<<"***************************�����"<<n-i+1<<"����ҵ����ʱ��"<<endl;
        cout<<"                            ";
        cin>>p->arrive_time;
        cout<<"***************************�����"<<n-i+1<<"����ҵ�ķ���ʱ��"<<endl;
        cout<<"                            ";
        cin>>p->serve_time;
        p->next = L->next;
        L->next = p;
    }
}

void ListSort(LinkList  &L)  //����������    ���������ȷ����㷨����
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

                t = p->serve_time;  //������ʱ�Է���ʱ��ҲҪ����
                p->serve_time = q->serve_time;
                q->serve_time = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}


void ListSort2(LinkList  &L)  //����������   ���ڶ���ҵ�����㷨����
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

                t = p->arrive_time;  //����ʱ��ҲҪ����
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
    cout<<"ʵ����ҵ�����㷨//���������ȷ���,ģ��cpu���л���"<<endl;
    CreateList_L(L , n);//���쵥����
    ListSort(L);//����������
    simulate_cpu_dispatch(L);
    L = L->next;
    int i=5;
    while(L)
    {
        cout<<endl<<endl<<endl;
        cout<<"///////////////////////////��"<<i-5+1<<"������cpu����ҵ://////////////////////////////"<<endl;
        cout<<"                           ����ʱ��"<<L->arrive_time<<endl<<endl;
        cout<<"                           ����ʱ��"<<L->serve_time<<endl<<endl;
        cout<<"                           ���ʱ��"<<L->finish_time<<endl<<endl;
        cout<<"                           ��תʱ��"<<L->turnover_time<<endl<<endl;
        i++;
        L= L->next;
    }
}

void  SJF(LinkList &L , int n)
{
    cout<<"                           ";
    cout<<"ʵ����ҵ�����㷨//���ڶ���ҵ�����㷨,ģ��cpu���л���"<<endl;
    CreateList_L(L , n);//���쵥����
    ListSort2(L);//����������
    simulate_cpu_dispatch(L);
    L = L->next;
    int i=5;
    while(L)
    {
        cout<<"///////////////////////////��"<<i-5+1<<"������cpu����ҵ://////////////////////////////"<<endl;
        cout<<"                           ����ʱ��"<<L->arrive_time<<endl<<endl;
        cout<<"                           ����ʱ��"<<L->serve_time<<endl<<endl;
        cout<<"                           ���ʱ��"<<L->finish_time<<endl<<endl;
        cout<<"                           ��תʱ��"<<L->turnover_time<<endl<<endl;
        i++;
        L= L->next;
    }
}
