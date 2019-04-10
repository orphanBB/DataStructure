#include <iostream>
#include "stdio.h"
#include "string.h"
#define N 100

using namespace std;
void lcs(char *x,int m,char *y,int n);

int b[N][N],c[N][N];

int main()
{
    int m,n;
    char A[100],B[100];
    cin>>A>>B;
    m=strlen(A);
    n=strlen(B);
    lcs(A,m,B,n);
    return 0;
}

void lcs(char *x,int m,char *y,int n)
{
    int i;
    int j;
    for(i=1; i<=m; i++)
        c[i][0]=0;
    for(i=1; i<=n; i++)
        c[0][i]=0;
    c[0][0]=0;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
        for(;i>=1;i--)
        {
            for(;j>=1;j--)
                printf("%c",c[i][j]);
        }
}
