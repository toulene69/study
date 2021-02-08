#include<iostream>
using namespace std;

class node{
    int data;
    node *l_child;
    node *r_child;
    public:
    node(int dat)
    {
        data=dat;
        l_child=nullptr;
        r_child=nullptr;
    }
    node *insert(node *root,int key);
    node *post_tree(node *root,int *arr,int n);
    void show(node *root);
};

node* node::insert(node *root,int key)
{
    if(root==nullptr)
     return new node(key);
     
     if(root->data>key)
       root->l_child=insert(root->l_child,key);
     else
      root->r_child=insert(root->r_child,key);
   return root;     
}
node* node::post_tree(node* root,int *arr,int n)
{
    root=new node(arr[n-1]);
    for(int i=n-2;i>=0;i--)
      root=insert(root,arr[i]);
   return root;   
}

void node::show(node *root)
{
    if(root==nullptr)
      return;
      show(root->l_child);
      show(root->r_child);
      cout<<root->data<<" ";
}

int main()
{
    int *arr;
    arr=new int[5];
    arr[0]=10;
    arr[1]=30;
    arr[2]=20;
    arr[3]=500;
    arr[4]=100;
    node T(0),*root=nullptr;
    root=T.post_tree(root,arr,5);
    T.show(root);    
}