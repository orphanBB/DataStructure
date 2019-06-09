/*
设有一个N*N(2<=N<10)方格的迷宫，入口和出口分别在左上角和右上角。
迷宫格子中分别放0和1，0表示可通，1表示不能，入口和出口处肯定是0。
迷宫走的规则如下所示：即从某点开始，有八个方向可走，前进方格中
数字为0时表示可通过，为1时表示不可通过，要另找路径。找出所有从
入口（左上角）到出口（右上角）的路径(不能重复)，输出路径总数，
如果无法到达，则输出0。
*/
#include <iostream>
#include "cstdio"
#include "cmath"
#define MAX 10
using namespace std;

int N;               //迷宫的阶数
int map[MAX][MAX];   //二维数组保存迷宫地图，0为可走，1为不可走
int entrance[2];     //入口坐标 entrance[0]为横坐标，entrance[1]为纵坐标
int exit[2];         //出口坐标 exit[0]exit[1]为纵坐标

void input()
{
    int i,j,k=0;
    int temp[100];
    FILE *fp;
    if((fp=fopen("maze_map.txt","rb"))==NULL)
    {
        printf("请输入迷宫的阶数：");
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
    }
    else
    {
        for(i=0;!feof(fp);i++)
        {
            fscanf(fp,"%d",&temp[i]);
        }
        N=sqrt(i);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                map[i][j]=temp[k];
                k++;
            }
        }
    }
    //出口入口在地图数组中的位置（下标）
    entrance[0]=1,entrance[1]=0;  //初始化入口坐标为第二行第一列
    exit[0]=N-2,exit[1]=N-1;      //初始化出口坐标为倒数第二行最后一列
}

int main()
{
    int i,j;
    input();
//    for(i=0;i<N;i++)
//    {
//        for(j=0;j<N;j++)             //输入测试
//        {
//            printf("%d ",map[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}
