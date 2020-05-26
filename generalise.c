#include<stdio.h>
#include<stdbool.h>
#define N=4


void print(int array[N][N])  //print function
{
     for(int i=0;i<N;i++){
         for(int j=0;j<N;j++)
          printf("%d ",array[i][j]);
          printf("/n");
     }
}
//function to check constraints for nqueen
bool constraint(int m,int array[N][N],int row,int col)
{
    if(m==1){
bool isvalid(int array[N][N],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(array[i][col])
        return false;
    }
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(array[i][j])
        return false;
    }
    for(i=row,j=col;i<4&&j>=0;i++,j--)
    {
        if(array[i][j])
        return false;
    }
    return true;
}
    }
    else{
//constraint for ratmaze
bool correctpath(int array[N][N],int x,int y)
{
    if(x>=0 && x<N && y>=0 && y<N && array[x][y]==1)
    {
        return true;
    }
    return false;
}
    }
    if(isvalid(int array[N][N],int row,int col)||correctpath(int array[N][N],int row,int col)==1)
    return true;
    return false;
}
//intial condition check for backtracking
bool intialcheck(int n,int array[N][N],int row,int col)
{
    if(n==1)
    {
        if(col>4)
        return true;
    }
    else
    {
        if(row==3 && col==3 && array[row][col]==1)
        return true;
    }
     return false;
    
}
//generalised backtracking function
bool backtrack(int array[N][N],int row,int col,int sol[N][N],int n,int m)
{
      if(intialcheck(n)==true){
      return true;
      }
      for(i=0;i<N;i++)
      if(constraint(m)==true);
      sol[i][col]=1;
      if(backtrack(array,row+1,col,sol,n,m)==true);
      return true;
      if(backtrack(array,row,col+1,sol,n,m)==true);
      return true;
      sol[row][col]=0;
      return false;

}
