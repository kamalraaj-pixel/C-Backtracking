#include<stdio.h>
#include<stdlib.h>
struct node{
       int data;
     struct node* left;
     struct node* right;
};
struct node* newnode(int data)
{
  struct node* node=(struct node*)malloc(sizeof(struct node));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
  return(node);
}
struct node* treeconstruct(int n,int* a,int i)
{ 
   
   if(i<=n){
   struct node* temp=newnode(a[i]);
   temp->left=treeconstruct(n,a,i+1);
   temp->right=treeconstruct(n,a,i+1);
   return temp;     
   }
   else
     return NULL;
  
}
void inorder(struct node* node)
{
  if(node==NULL)
    return;
   inorder(node->left);
   printf("%d",node->data);
   inorder(node->right);
}
int totalmatch()
{
  static int i=-1;
  i++;
  return i;
}
void sum(struct node* node,int* a,int d,int k)
{  
  if(node==NULL){
     if(d==k)
  {
    totalmatch();
  }
   printf("sum is %d\n",d);
   return;
  }
   sum(node->left,a,d,k);
   sum(node->right,a,d+node->data,k);
  
}



int main()
{
  int a[3]={1,2,3};
  struct node* root=treeconstruct(2,a,0);
  inorder(root);
  printf("\n");
  sum(root,a,0,7);
  int count=totalmatch();
  printf("count is%d\n",count);
  printf("tree is constructed");
  return 0;
}

