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
    node *construct(node *root,int i,int n,int *arr);
    node *in_tree(node *root,int *arr,int n);
    void show(node *root);
};

node* node::construct(node* root,int i,int n,int *arr)
{
    if(i<0 || i>n)
      return nullptr;

      int mid=(i+n)/2;
      root=new node(arr[mid]);
      root->l_child=construct(root->l_child,i,mid-1,arr);
      root->r_child=construct(root->r_child,mid+1,n,arr);
      return root;
}

node* node::in_tree(node* root,int *arr,int n)
{
    return construct(root,0,n-1,arr);
}

void node::show(node *root)
{
    if(root==nullptr)
      return;
      show(root->l_child);
      cout<<root->data<<" ";
      show(root->r_child);
}

int main()
{
    int *arr;
    arr=new int[5];
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=100;
    arr[4]=500;
    node T(0),*root=nullptr;
    root=T.in_tree(root,arr,5);
    T.show(root);    
}