/*
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，
分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，
每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。
为简单起见，城镇从1到N编号。

注意:两个城市之间可以有多条道路相通,也就是说
3 3
1 2
1 2
2 1
这种输入也是合法的

当N为0时，输入结束，该用例不被处理。
对每个测试用例，在1行里输出最少还需要建设的道路数目。
*/
#include "stdio.h"
#define MAXN 1000
int F[MAXN];
int find(int t)
{
    if(F[t]==-1)
        return t;
    return F[t]=find(F[t]);
}
void bing(int a,int b)
{
    int t1=find(a);
    int t2=find(b);
    if(t1!=t2)
        F[t1]=t2;
}
int main()
{
    int n,m;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
            F[i]=-1;
        int a,b;
        while(m--)
        {
            scanf("%d %d",&a,&b);
            bing(a,b);
        }
        int res=0;
        for(int i=1;i<=n;i++)
          if(F[i]==-1)
          res++;
        printf("%d\n",res-1);
    }
    return 0;
}
