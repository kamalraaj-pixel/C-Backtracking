#include<stdio.h>
#include<stdbool.h>
void print(int array[3])
{
    
    printf("\n{ ");

for(int i=0; i<3; i++)
{
printf("%d ",array[i]);
}

printf("}\n");
}
void subset(int array[3],int n,int pos,int set[3])
{
    if(pos==n)
    {
        print(set);
        return;
    }
    set[pos]=array[pos];
    subset(array,n,pos+1,set);
    set[pos]=0;
    subset(array,n,pos+1,set);
    return;
}
int main()
{
    int array[3]={1,2,3};
    int set[3];
    subset(array,3,0,set);
    return 0;
}