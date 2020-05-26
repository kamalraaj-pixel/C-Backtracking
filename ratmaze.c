 #include<stdio.h>
 #include<stdbool.h>
 bool issafe(int maze[4][4],int x,int y)
 {
     if(x>=0 && x<4 && y>=0 && y<4 && maze[x][y]==1)
      return true;
      return false;
 }
 bool ratmaze(int maze[4][4],int x,int y,int sol[4][4])
 {
     if(x==3 && y==3 && maze[x][y]==1){
         return true;
     }
     if(issafe(maze,x,y)==true){
      sol[x][y]=1;
     
     if(ratmaze(maze,x+1,y,sol)==true)
     return true;
     if(ratmaze(maze,x,y+1,sol)==true)
     return true;
     sol[x][y]=0;
     return false;
     }
     else
     {
         return false;
     }
}
void print(int sol[4][4])
{
 for (int i = 0; i < 4; i++) { 
		for (int j = 0; j < 4; j++) 
			printf(" %d ", sol[i][j]); 
		printf("\n"); 
	} 
}
bool solve(int maze[4][4])
{
    int sol[4][4]={   {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}};
    if(ratmaze(maze,0,0,sol)==false)
    {
        printf("no solution exists");
        return false;
    }
    print(sol);
    return true;
}
int main()
{
    int maze[4][4]={ { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
    solve(maze);
    return 0;
}
     
     
 