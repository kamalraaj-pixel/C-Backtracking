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
struct node* treeconstruct(int n,int i)
{
   if(i<=n){
      struct node* temp=newnode(i);
      temp->left=treeconstruct(n,i+1);
      temp->right=treeconstruct(n,i+1);
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
     void sum(struct node* node,int d)
     {
       if(node==NULL)
       {
         printf("%d",d);
         return;
       }
       sum(node->left,d);
       sum(node->right,d+node->data);
     }
     
int main()
{
  int a[4]={1,2,3,4};
  int i=0;
  struct node* root=treeconstruct(3,i);
  inorder(root);
  printf("\n");
  sum(root,0);
  return 0;
}
