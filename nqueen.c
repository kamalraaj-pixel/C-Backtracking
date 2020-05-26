#include<stdio.h>
#include<stdbool.h>

bool issafe(int board[4][4],int row,int col){
     int i,j;
    for(i=0;i<col;i++){
        if(board[row][i])
        return false;
    }
    for(i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j])
        return false;
    }
    for(i=row,j=col;i<4 && j>=0;i++,j--){
        if(board[i][j])
        return false;
    }
    return true;
}
bool nqueen(int board[4][4],int col){
       if(col>=4){
       
        return true;
       }
       for(int i=0;i<4;i++){
           if(issafe(board,i,col)){
            board[i][col]=1;
           if(nqueen(board,col+1))
           return true;
           board[i][col]=0;
           }
       }
       return false;
}
    
void print(int board[4][4]) 
{ 
	for (int i = 0; i < 4; i++) { 
		for (int j = 0; j < 4; j++) 
			printf(" %d ", board[i][j]); 
		printf("\n"); 
	} 
}     
    
    
bool solve(int board[4][4])
{

      if(nqueen(board,0)==false){
           printf("NO soln exists");
           return false;
       }
        else
            print(board);
            return true;
        
}
int main()
{      
    int board[4][4]={ {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}};
        solve(board);
        return 0;              
}