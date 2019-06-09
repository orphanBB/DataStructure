#include <iostream>
#include "stdio.h"
#define N_MAX 10         //最大进程数
#define NAME_MAX 100     //最大进程名长度

using namespace std;

int n;     //进程个数
char name[N_MAX][NAME_MAX];   //进程名数组
int arrival_time[N_MAX];          //进程到达时间
int run_time[N_MAX];          //进程运行时间
int star_time[N_MAX];         //进程开始时间
int Check[N_MAX];             //作业是否完成标记

/**输入函数
*如果文件input.txt不存在
*则手动输入
*/
void input()
{
    int i;
    FILE *fp;
    if((fp=fopen("input.txt","rb"))==NULL)
    {
        printf("请输入进程个数:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("请输入进程名:");
            scanf("%s",&name[i]);
            printf("请输入进程%s的到达时间:",name[i]);
            scanf("%d",&arrival_time[i]);
            printf("请输入进程%s的运行时间:",name[i]);
            scanf("%d",&run_time[i]);
        }
    }
        else
        {
            for(i=0;!feof(fp);i++)
            {
                fscanf(fp,"%s",&name[i]);
                fscanf(fp,"%d",arrival_time[i]);
                fscanf(fp,"%d",run_time[i]);
            }
            n=i;
        }
}

/**选择先到达的作业
*/
int select_first(int a[])
{
    int i=0,k,j;
	for(k=0;k<n;k++){
		if(Check[k]==0){
			i=k;
			break;
		}
	}
	for(j=0;j<n;j++){
		if(a[i]>a[j]&&Check[j]==0){
			i=j;
		}
	}
	Check[i]=1;
	return i;
}

/*先来先服务作业调度算法
*/
void FCFS()
{
    printf("作业名  提交时间  运行时间  开始时间  结束时间  周转时间  带权周转时间\n");
}

int main()
{
    input();
    return 0;
}
