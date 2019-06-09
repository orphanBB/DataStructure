#include <iostream>
#include "stdio.h"
#define N 20

using namespace std;

int n;  //�Թ��ĳ���
int maze[N][N]={0};
//��������
/* = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,0,1,0},{0,0,0,0,1,0,1,0},{0,1,0,0,0,0,1,0},
{0,1,0,1,1,0,1,0},{0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0},{0,1,1,1,1,1,1,0}};
*/
//��������
const int fx[4] = {0,1,0,-1};       //1,0,-1,0
const int fy[4] = {1,0,-1,0};       //0,1,0,-1
//maze[i][j] = 3;//��ʶ����
//maze[i][j] = 2;//��ʶ����ͬ
//maze[i][j] = 1;//��ʶǽ
//maze[i][j] = 0;//��ʶ������
//����ʾǽ
//����ʾ��ǰ����δ�߹���
//���ʾ·��

void input()
{
    FILE *fp;
    int i,j;
    if((fp=fopen("maze_map.txt","rb"))==NULL)
    {
        printf("�������Թ��Ľ�����");
        scanf("%d",&n);
        printf("�������Թ���ͼ��0��ʾ�գ�1��ʾǽ����");
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

//��ӡ·��
void printPath()
{
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (1 == maze[i][j])
            {
                cout<<"��";
            }
            else if(0 == maze[i][j])
            {
                cout<<"��";
            }
            else if(-1 == maze[i][j])
            {
                cout<<"��";
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
        //�����һ���������ȥ��̽�ܷ���
        newx = i+fx[k];
        newy = j+fy[k];
        //�������ǽ����û���߹�
        if ( (newx>=0) && (newx <n) && (newy>=0) && (newy<n) && (0 == maze[newx][newy]))
        {
            maze[newx][newy] = -1;  //��Ǳ�ʾ�߹�
            if ((n-2==newx) && (n-1==newy))  //���ߵ����½ǵĳ���ʱ
            {
                printPath();
                maze[newx][newy] = 0;  //�����һ��·���������±��Ϊδ�߹�̽����һ�������Ƿ��н�
            }
            else
            {
                search(newx,newy);   //����������һ��
            }
        }
    }
    //���ݵ�ʱ�򽫴˵���δ���ʣ�������һ��·��Ҳ���Է���
    maze[i][j] = 0;
}

int main()
{
    input();
    //print_maze();
    maze[1][0] = -1;  //����㿪ʼ  �������Ϊ�߹���
    search(1,0);
    return 0;
}
