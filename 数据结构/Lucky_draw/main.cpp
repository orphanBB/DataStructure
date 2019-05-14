/*
题目描述：
有这样一个抽奖活动，主办方会向人们出售一些卡片，每张卡片上印有若干字母，
每个人可以凭身份证购买若干卡片（由于卡片很贵，一个人不可能买很多）。开
奖的时候，主办方会随机给出一串字母，如果这串字母中的每种字母都能在某一个
人的卡片上找到的话，那么那个人就能获得主办方颁发的奖品。CoCo购买了若干张
卡片，现在请你判断她是否能获奖。

Input：
第一行输入一个字符串表示主办方随机给出的那串字符。（长度小于100）
第二行输入一个正整数n（n≤50）,表示CoCo购买的卡片数量。
接下来n行，每行输入一个字符串，表示CoCo手上每一张卡片上的内容。

Output：
如果CoCo能够获奖输出Yes，否则输出No。

输入样式：
zhimakaimen
6
sdm
zmk
ai
idf
henfd
nk

输出样式：
Yes
*/

//测试数据
//<p>ilikethisgame</p><p>3</p><p>ac</p><p>bc</p><p>d</p>
//<p>abcdefghigk</p><p>5</p><p>abba</p><p>ok</p><p>ihgfe</p><p>dcmo</p><p>pob</p>

#include <iostream>
#include "string.h"
#define N 50

using namespace std;

char luckystr[101],str[101];
int res[N];
int m;

int findchar(char c,char* tempstr)
{
    int i,n;
    n=strlen(tempstr);
    for(i=0;i<n;i++)
    {
        if(tempstr[i]==c)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    int i,temp=0;
    char card[N][101];
    cin>>luckystr;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>card[i];
        strcat(str,card[i]);
    }
    m=strlen(luckystr);
    for(i=0;i<m;i++)
    {
        res[i]=findchar(luckystr[i],str);
    }
    for(i=0;i<m;i++)
    {
        if(res[i]==1)
            temp++;
    }
    if(temp==m)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
