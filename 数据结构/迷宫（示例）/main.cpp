#include <iostream>
#include "stdio.h"
#define N 20

using namespace std;

int n;  //迷宫的长宽
int maze[N][N]={0};
//测试数据
/* = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,0,1,0},{0,0,0,0,1,0,1,0},{0,1,0,0,0,0,1,0},
{0,1,0,1,1,0,1,0},{0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0},{0,1,1,1,1,1,1,0}};
*/
//右下左上
const int fx[4] = {0,1,0,-1};       //1,0,-1,0
const int fy[4] = {1,0,-1,0};       //0,1,0,-1
//maze[i][j] = 3;//标识已走
//maze[i][j] = 2;//标识死胡同
//maze[i][j] = 1;//标识墙
//maze[i][j] = 0;//标识可以走
//■表示墙
//□表示当前方案未走过的
//●表示路径

void input()
{
    FILE *fp;
    int i,j;
    if((fp=fopen("maze_map.txt","rb"))==NULL)
    {
        printf("请输入迷宫的阶数：");
        scanf("%d",&n);
        printf("请输入迷宫地图（0表示空，1表示墙）：");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&maze[i][j]);
            }
        }
    }
    else
    {
        fscanf(fp,"%d",&n);
        for(i=0;i<n;i++)
        {
			for(j=0;j<n;j++)
            {
                fscanf(fp,"%d",&maze[i][j]);
            }
        }
		n=i;
    }
}
void print_maze()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

//打印路径
void printPath()
{
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (1 == maze[i][j])
            {
                cout<<"■";
            }
            else if(0 == maze[i][j])
            {
                cout<<"□";
            }
            else if(-1 == maze[i][j])
            {
                cout<<"●";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void search(int i, int j)
{
    int newx;
    int newy;
    for (int k=0;k<4;++k)
    {
        //获得下一个点的坐标去试探能否走
        newx = i+fx[k];
        newy = j+fy[k];
        //如果不是墙，且没有走过
        if ( (newx>=0) && (newx <n) && (newy>=0) && (newy<n) && (0 == maze[newx][newy]))
        {
            maze[newx][newy] = -1;  //标记表示走过
            if ((n-2==newx) && (n-1==newy))  //当走到右下角的出口时
            {
                printPath();
                maze[newx][newy] = 0;  //已输出一种路径，则重新标记为未走过探测下一个方向是否有解
            }
            else
            {
                search(newx,newy);   //继续搜索下一格
            }
        }
    }
    //回溯的时候将此点标记未访问，这样下一条路径也可以访问
    maze[i][j] = 0;
}

int main()
{
    input();
    //print_maze();
    maze[1][0] = -1;  //从起点开始  将起点标记为走过的
    search(1,0);
    return 0;
}
