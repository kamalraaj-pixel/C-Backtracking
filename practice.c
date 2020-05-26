#include<stdio.h>
#define Arraysize(a)  (sizeof(a)/sizeof(a[0]))
void printarr(int a[],int size)
{
  for(int i=0;i<size;i++)
   {
     printf("%*d",10,a[i]);
   }
}
int main()
{
int a[6]={1,2,3,4,5,6};
int length=Arraysize(a);
printarr(a,length);
return 0;
}

