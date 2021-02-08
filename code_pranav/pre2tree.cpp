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
    node *pre_tree(node *root,int *arr,int n);
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
node* node::pre_tree(node* root,int *arr,int n)
{
    root=new node(arr[0]);
    for(int i=1;i<n;i++)
      root=insert(root,arr[i]);
   return root;   
}

void node::show(node *root)
{
    if(root==nullptr)
      return;
      cout<<root->data<<" ";
      show(root->l_child);
      show(root->r_child);
}

int main()
{
    int *arr;
    arr=new int[5];
    arr[0]=100;
    arr[1]=20;
    arr[2]=10;
    arr[3]=30;
    arr[4]=500;
    node T(0),*root=nullptr;
    root=T.pre_tree(root,arr,5);
    T.show(root);    
}