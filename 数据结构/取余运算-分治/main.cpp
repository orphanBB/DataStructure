#include <iostream>
#include "math.h"

using namespace std;

long long mi(int x,int n)
{
    if(n==0)
        return 1;
    else if(n>0)
        return x*mi(x,n-1);
    else
        return 1/(x*mi(x,n+1));
}

int main()
{
    long long b,p,k;
    cin>>b>>p>>k;
    cout<<mi(b,p)%k<<endl;
    return 0;
}
