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
struct node* treeconstruct(int n,int* a,int i,int d,int* count,int k)
{ 
   
   if(i<=n){
   struct node* temp=newnode(a[i]);
   temp->left=treeconstruct(n,a,i+1,d,count,k);
   temp->right=treeconstruct(n,a,i+1,d+temp->data,count,k);
   
   return temp;
   }
   else
    printf("sum is%d\n",d);
    if(d==k)
    (*count)++;
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
int main()
{
  int a[4]={1,2,3,4};
  int count;
  int k=7;
  struct node* root=treeconstruct(3,a,0,0,&count,k);
  inorder(root);
  printf("\n");
  printf("count is %d\n",count);
  return 0;
}
