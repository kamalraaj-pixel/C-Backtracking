#include<stdio.h>
#include<stdbool.h>
#define N 9

bool unassigned(int puzzle[N][N],int *row,int *col)
{
     int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
        
          if(puzzle[i][j]==0)
          {
           *row=i;
           *col=j;
          return true;
          }
        }
    }
    return false;

}
bool isvalid(int puzzle[N][N],int row,int col,int num)
{
    //for check along row
    for(int i=0;i<N;i++){
    if(puzzle[row][i]==num)
    return false;
    }
    
    //for check along col
    for(int i=0;i<N;i++){
        if(puzzle[i][col]==num)
        return false;;
    }
    //for checking sub box
    int row_start = (row/3)*3;
    int col_start = (col/3)*3;
    for(int i=row_start;i<row_start+3;i++)
    {
        for(int j=col_start;j<col_start+3;j++)
        {
            if(puzzle[i][j]==num)
                return false;
        }
    }
    return true;
}
bool solve(int puzzle[N][N])
{
      int row=0;
      int col=0;
    if(unassigned(puzzle,&row,&col)==false)
    {
        return true;
    }
    for(int num=1;num<=9;num++)
       { 
        if(isvalid(puzzle,row,col,num))
        {
        puzzle[row][col]=num;
        if(solve(puzzle)==true)
        return true;
        puzzle[row][col]=0;
        }
    }
    return false;
}
void print(int puzzle[N][N])
{
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
    printf("%d ",puzzle[i][j]);
    
    printf("\n");
    }
}
int main()
{
    int puzzle[N][N] = {
    {6,5,0,0,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,0,5,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,5,0,3},
    {5,7,8,3,0,1,0,2,6},
    {2,0,0,0,4,8,9,0,0},
    {0,9,0,6,2,5,0,8,1}
}; 
    if (solve(puzzle) == false) 
           printf("No solution exists"); 
    else
         print(puzzle);
  
    return 0; 
} 