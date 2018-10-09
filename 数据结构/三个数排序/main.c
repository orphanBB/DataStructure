#include <stdio.h>
#include <stdlib.h>
/*题目：输入三个整数x,y,z，请把这三个数由小到大输出。
1.程序分析：我们想办法把最小的数放到x上，先将x与y进行比较，如果x>y则将x与y的值进行交换，
然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小。
*/

int main()
{
    int x,y,z,temp;
    printf("input the value of x,y,z:");
    scanf("%d %d %d",&x,&y,&z);
    if(x>y)
    {
        temp=x;
        x=y;
        y=temp;
        if(x>z)
    {
        temp=x;
        x=z;
        z=temp;
    }
    }
    printf("form min to max:%d %d %d",x,y,z);
    return 0;
}
