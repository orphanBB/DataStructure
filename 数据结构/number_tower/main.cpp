
/*
��Ŀ����������̬�滮��
�������Ķ��������Ѱ��һ���Ӷ������ױߵ�·����ʹ��·����������������֮�����
·���ϵ�ÿһ����ֻ�������»������ߡ�ֻ��Ҫ���������ͼ��ɣ����ظ�������·����
 �����ε�����Ϊ1-100������Ϊ0-99��

�������룺           ������ʽ��
5                       5
8                       8
12 15                   12 15
3 9 6                   3 9 6
8 10 5 12               8 10 5 12
16 4 18 10 9            16 4 18 10 9

���������           �����ʽ��
60                      60
*/

#include <iostream>
#define N 100

using namespace std;

int main()
{
    int data[N][N],result[N][N];
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            cin>>data[i][j];
            result[i][j]=data[i][j];
        }
    }
    for(i=(n-1);i>0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if(result[i][j]>result[i][j+1])
                result[i-1][j]=result[i][j]+data[i-1][j];
            else
                result[i-1][j]=result[i][j+1]+data[i-1][j];
        }
    }
    cout<<result[0][0]<<endl;
    return 0;
}
