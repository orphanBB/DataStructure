#include "iostream"
using namespace std;

int digui(int s)
{
    if(s==1)
        return 1;
    else
        return digui(s/2)+1;
}

int main()
{
    int n,i = 0 ;
    cin>>n;
    int a[n];
    for(i = 0;i<n;i++)
    {
        cin>>a[i];
        cout<<digui(a[i])<<endl;
    }
}
