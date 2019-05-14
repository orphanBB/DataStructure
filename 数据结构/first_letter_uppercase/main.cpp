//输入一句英语  将每个单词第一个字母大写

#include <iostream>
#include "stdio.h"
#include "string.h"
using namespace std;
char cstr[110];

int main()
{
    int i,n;
    gets(cstr);
    n=strlen(cstr);
    cstr[0]-=' ';
    for(i=0;i<n;i++)
    {
        if(cstr[i]==' ')
            cstr[i+1]-=' ';
    }
    cout<<cstr;
    return 0;
}
