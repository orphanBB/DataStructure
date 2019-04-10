#include <iostream>
#define maxn 100
using namespace std;

int a[maxn],b[maxn],c[maxn];

int main()
{
    int n,i,j,max,p;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=1;
        c[i]=0;
    }
    for(i=n-1;i>=1;i--)
    {
        max=0;
        p=0;
        for(j=i+1;j<=n;j++)
        {
            if(a[i]<a[j]&&b[j]>max)
            {
                max=b[j];
                p=j;
            }
        }
        if(p>0)
            {
                b[i]=b[p]+1;
                c[i]=p;
            }
    }
    max=0;
    p=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]>max)
        {
            max=b[i];
            p=i;
        }
    }
    cout<<max<<endl;
    return 0;
}
