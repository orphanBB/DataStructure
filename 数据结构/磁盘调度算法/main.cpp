#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAX 9

using namespace std;

int request_list[MAX]={};//{98,25,63,97,56,51,55,55,6};   //������ʵĴŵ����к�
int service_list[MAX];   //�ŵ��������к�
int summary_distance;    //��ͷ�ƶ��ܾ���
int average_distance;    //ƽ��Ѱ������
int present=67;          //��ǰ��ͷ���ڵĴŵ���  Ĭ�ϳ�ʼΪ0
int MIN=101;

void Produce_Request_list()
{
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<MAX;i++)
    {
        request_list[i]=1+rand()%100;
    }
    cout<<"������ʴŵ����кţ�"<<endl;
    for(i=0;i<MAX;i++)
    {
        cout<<request_list[i]<<" ";
    }
}

void SSTF()   //���Ѱ��ʱ������
{
    int i,j,flag;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(request_list[j]!=-1&&MIN>abs(present-request_list[j]))
            {
                MIN=abs(present-request_list[j]);
                flag=j;
            }
        }
        service_list[i]=request_list[flag];
        summary_distance+=abs(present-request_list[flag]);
        present=request_list[flag];
        request_list[flag]=-1;
        MIN=101;
    }
    cout<<"\n��������Ϊ��"<<endl;
    for(i=0;i<MAX;i++)
    {
        cout<<service_list[i]<<" ";
    }
    cout<<"\nѰ���ܾ��룺"<<summary_distance<<endl;
    cout<<"ƽ��Ѱ�����룺"<<(double)summary_distance/MAX<<endl;
}

int main()
{
    Produce_Request_list();
    SSTF();
    return 0;
}
