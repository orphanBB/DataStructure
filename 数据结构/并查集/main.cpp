/*
��������������ɲ���������ÿ�����������ĵ�1�и���������������
�ֱ��ǳ�����ĿN ( < 1000 )�͵�·��ĿM������M�ж�ӦM����·��
ÿ�и���һ�����������ֱ��Ǹ�����·ֱ����ͨ����������ı�š�
Ϊ������������1��N��š�

ע��:��������֮������ж�����·��ͨ,Ҳ����˵
3 3
1 2
1 2
2 1
��������Ҳ�ǺϷ���

��NΪ0ʱ�������������������������
��ÿ��������������1����������ٻ���Ҫ����ĵ�·��Ŀ��
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
