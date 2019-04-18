/*
题目描述：
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，
则他们的身高满足T1<...Ti+1>…>TK(1<=i=K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入的第一行是一个整数N(2<=N<=100)，表示同学的总数。
第二行有n个整数，用空格分隔，第i个整数Ti(130<=Ti<=230)是第i位同学的身高(厘米)。
8
186 186 150 200 160 130 197 220
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
4

输入样式：
20
176 164 166 189 178 230 150 134 135 222 162 230 229 151 200 165 157 184 143 176

输出样式：
10
*/


/*
分析：以每个人作为Ti(上升和下降的分界)，计算每种结果保存到，取最小

#include <iostream>

using namespace std;

int N;  //总人数
int tall[10000];   //身高数组
int dp[10000];   //保存以i作为Ti需要踢掉人数的结果集

void kickout(int a)
{

}

int main()
{
    int i;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>tall[i];
    }
    for(i=0;i<N;i++)
    {

    }
    return 0;
}
*/

#include<cstdio>
#include<algorithm>

using namespace std;
int n,a[105],f[2][105],ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                f[0][i]=max(f[0][i],f[0][j]+1);
            }
        }
    }
    a[n+1]=0;
    for(int i=n;i;i--)
    {
        for(int j=n+1;j>i;j--)
        {
            if(a[i]>a[j])
            {
                f[1][i]=max(f[1][i],f[1][j]+1);
            }
        }

    }
    for(int i=1;i<=n;i++)
    {
        ans=max(f[0][i]+f[1][i]-1,ans);
    }
    printf("%d\n",n-ans);
    return 0;
}
