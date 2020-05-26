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

void sum(struct node* node,int* a,int d,int k, int* count)
{  
  if(node==NULL){
     if(d==k)
     (*count)++;
   printf("sum is %d\n",d);
   return;
  }
   sum(node->left,a,d,k,count);
   sum(node->right,a,d+node->data,k,count);
  
}



int main()
{
  int a[4]={1,2,3,4};
  int count = 0;
  struct node* root=treeconstruct(3,a,0);
  inorder(root);
  printf("\n");
  sum(root,a,0,7,&count);
  printf("count is%d\n",count);
  printf("tree is constructed");
  return 0;
}

