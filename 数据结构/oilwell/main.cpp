/*
题目描述：
某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有  n 口油井的油田。
从每口油井都要有一条输油管道沿最短路经(或南或北)与主管道相连。如果给定 n 口油
井的位置,即它们的 x 坐标（东西向）和 y 坐标（南北向）,应如何确定主管道的最优位置,
即使各油井到主管道之间的输油管道长度总和最小的位置?证明可在线性时间内确定主管道
的最优位置。

编程任务：
给定 n 口油井的位置,编程计算各油井到主管道之间的输油管道最小长度总和。

输入
第 1 行是油井数 n，1£n£10000。接下来 n 行是
油井的位置，每行 2 个整数 x 和 y，-10000<=x，y<=10000。

输出
第 1 行中的数是油井到
主管道之间的输油管道最小长度总和。

输入样式：
5
1 2
2 2
1 3
3 -2
3 3

输出样式：
6
*/

/*
分析：找出y最大和最小，把之间的y值作为主管道算出当前y下的长度，取最小的
*/
#include "iostream"
#include "cmath"
using namespace std;

int n;
int oilwelly[10000];
int lengthmin=10000;

int length(int a[],int b)
{
    int i,res=0;
    for(i=0;i<n;i++)
    {
        res+=abs(a[i]-b);
    }
    return res;
}

int main()
{
    int x,y,i,temp;
    int max=0,min=10000;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        oilwelly[i]=y;
        if(y>max)
            max=y;
        if(y<min)
            min=y;
    }
    for(i=min;i<=max;i++)
    {
        temp=length(oilwelly,i);
        if(temp<lengthmin)
            lengthmin=temp;
    }
    cout<<lengthmin;
    return 0;
}


/*
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int a[10000];

void kp(int l,int r)
{
    int mid,i,j,p;
    mid=a[(l+r)/2];
    i=l; j=r;
    do
    {
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
            p=a[i];
            a[i]=a[j];
            a[j]=p;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(l<j) kp(l,j);
    if(i<r) kp(i,r);
}

int main()
{
    int x,y,n,sum=0,mid;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        a[i]=y;
    }
    kp(1,n);
    if(n%2==1)
        mid=a[(1+n)/2];
    else
        mid=(a[(1+n)/2]+a[(1+n)/2+1])/2;
    for(int i=1;i<=n;i++)
    sum+=abs(mid-a[i]);
    cout<<sum;
}

*/
