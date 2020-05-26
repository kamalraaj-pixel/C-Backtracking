#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int row1[]={2,1,-1,-2,-2,-1,1,2};
int col1[]={1,2,2,1,-1,-2,-2,-1};
bool validmove(int visited[8][8],int newrow,int newcol){
    if ((newrow >= 0) && (newrow < 8) && (newcol >= 0) && (newcol < 8) && (visited [newrow][newcol] == 0))
            {
                return true;
            }
            return false;
        }


bool knighttour(int visited[8][8],int row,int col,int move)
{
    if(move==64)
    {
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
            {
                printf("%d ",visited[i][j]);
            }
              printf("\n");
        }
        return true;
    }
    else
    {
        for(int index=0;index<8;index++){
            int newrow=row+row1[index];
            int newcol=col+col1[index];
            if(validmove(visited,newrow,newcol))
            {
                move++;
                visited[newrow][newcol]=move;         
                if(knighttour(visited,newrow,newcol,move))
                {
                    return true;
                }
                else{
                move--;
                visited[newrow][newcol]=0;
                }
            }

        }

    }
    return false;
    
}
int main()
{
  int  visited[8][8]={{0,0,0,0,0,0,0,0 },
                      {0,0,0,0,0,0,0,0 },
                      {0,0,0,0,0,0,0,0 },
                      {0,0,0,0,0,0,0,0 },
                      {0,0,0,0,0,0,0,0 },
                      {0,0,0,0,0,0,0,0 },
                      {0,0,0,0,0,0,0,0 },
                      {0,0,0,0,0,0,0,0 }};;


    visited [0][0]=1;
    knighttour(visited,0,0,1);
    return 0;
}