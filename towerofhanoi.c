#include<stdio.h>
void towerofhanoi(int n,char from,char to,char aux)
{
    if(n==1){
        printf("\nmove disk 1 form rod %c to rod %c",from,to);
        return;
    }
    towerofhanoi(n-1,from,aux,to);
    printf("\nmove disk %d from rod %c to rod %c",n,from,to);
    towerofhanoi(n-1,aux,to,from);
}
int main()
{
     
     int n=4;
     towerofhanoi(n,'A','B','C');
     return 0;

}