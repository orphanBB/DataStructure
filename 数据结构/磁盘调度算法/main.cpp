#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAX 9

using namespace std;

int request_list[MAX]={};//{98,25,63,97,56,51,55,55,6};   //请求访问的磁道序列号
int service_list[MAX];   //磁道服务序列号
int summary_distance;    //磁头移动总距离
int average_distance;    //平均寻道距离
int present=67;          //当前磁头所在的磁道号  默认初始为0
int MIN=101;

void Produce_Request_list()
{
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<MAX;i++)
    {
        request_list[i]=1+rand()%100;
    }
    cout<<"请求访问磁道序列号："<<endl;
    for(i=0;i<MAX;i++)
    {
        cout<<request_list[i]<<" ";
    }
}

void SSTF()   //最短寻道时间优先
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
    cout<<"\n服务序列为："<<endl;
    for(i=0;i<MAX;i++)
    {
        cout<<service_list[i]<<" ";
    }
    cout<<"\n寻道总距离："<<summary_distance<<endl;
    cout<<"平均寻道距离："<<(double)summary_distance/MAX<<endl;
}

int main()
{
    Produce_Request_list();
    SSTF();
    return 0;
}
