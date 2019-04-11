#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int N,K;
char ch[45];

void calBSum();

int main()
{
	int i;
	scanf("%d%d",&N,&K);
	getchar();
	for (i=1;i<=N;i++)
	{
		scanf("%c",&ch[i]);
	}
	calBSum();
	return 0;
}

void calBSum()
{
	int F[45],i,iSum,itmpK,itmpN;
	char ctemp[45];
	iSum=0;
	for (i=1;i<=N-K;i++)
	{
		iSum=ch[i]-'0'+iSum*10;
		F[i]=iSum;
	}
	for (itmpK=1;itmpK<=K;itmpK++)
	{
		for (itmpN=N-K+itmpK;itmpN>=itmpK+1;itmpN--)
		{
			F[itmpN]=INT_MIN;
			for (i=itmpK;i<=itmpN-1;i++)
			{
				memcpy(ctemp,ch+i+1,itmpN-i);
				ctemp[itmpN-i]=0;
				if (F[i]*atoi(ctemp)>F[itmpN])
				{
					F[itmpN]=F[i]*atoi(ctemp);
				}
			}
		}
	}
	printf("%d\n",F[N]);
}
