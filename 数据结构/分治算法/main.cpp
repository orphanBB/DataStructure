/*
��Ŀ������
��x��ai���ݣ�Ҫ���㷨���Ӷ�O��lgn����

������ʽ��
��һ������������x��n
�ڶ���n������a1,a2,...,ai,..an
2 2
1 2

�����ʽ��
���n�У�ÿ��Ϊx��ai�η�
2
4
*/

#include <iostream>

using namespace std;

long mi(int x,int n)
{
    if(n==0)
        return 1;
    else if(n>0)
        return x*mi(x,n-1);
    else
        return 1/(x*mi(x,n+1));
}
/*
int main()
{
    int x,n;
    int i=0;
    cin>>x>>n;
    int a[n]={0};
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<mi(x,a[i])<<endl;
    }
    return 0;
}
*/

int main()
{
    int x,n;
    int i=0;
    cin>>x>>n;
    int a[n]={0};
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<(long)pow(x,a[i])<<endl;
    }
    return 0;
}
