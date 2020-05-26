#include<stdio.h>
#include<stdlib.h>

void sumofsubsets(int a[],int i,int n,int sum)
{
    if(i>n)
    {
        printf("sum is %d\n",sum);
        return;
    }
    sumofsubsets(a,i+1,n,sum+a[i]);
    sumofsubsets(a,i+1,n,sum);
}
int main()
{
    int a[3]={1,2,3};
    int i=0;
    int n=2;
    sumofsubsets(a,i,n,0);
    return 0;
}