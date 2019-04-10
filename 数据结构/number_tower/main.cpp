
/*
题目描述：（动态规划）
从数塔的顶层出发，寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。
路径上的每一步都只能往左下或右下走。只需要求出这个最大和即可，不必给出具体路径。
 三角形的行数为1-100，数字为0-99。

样例输入：           输入样式：
5                       5
8                       8
12 15                   12 15
3 9 6                   3 9 6
8 10 5 12               8 10 5 12
16 4 18 10 9            16 4 18 10 9

样例输出：           输出样式：
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
