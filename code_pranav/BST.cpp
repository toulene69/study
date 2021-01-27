#include<iostream>
using namespace std;

class tree{
private:
    int data;
    tree *l_child;
    tree *r_child;
public:
   tree(int data)
   {
       this->data=data;
       l_child=nullptr;
       r_child=nullptr;
   }  

   tree *search(tree*,int);
   tree *insert(tree *,int);  
   tree *delete_node(tree *,int);
   void display(tree* root);
   tree *successor(tree*);
};

tree* tree::search(tree* node,int key)
{
    if(node==nullptr)
    return nullptr;

    if(node->data==key)
     return node;
     else if(node->data>key)
    {
        tree* l=search(node->l_child,key);
        if(l==nullptr)
        return node;
        else
        return l; 
    }
    else if (node->data<key)
    {
        tree* r=search(node->r_child,key);
        if(r==nullptr)
         return node;
        else
         return r;
    }
    return node;
} 

 tree* tree::insert(tree *node,int data)
 {
  tree T(0);

  tree *temp=T.search(node,data);

   if(temp==nullptr)
     return new tree(data);
    else if(temp->data<data)
   {
       temp->r_child=new tree(data);
       return node;
   }  
   else if(temp->data>data)
   {
       temp->l_child=new tree(data);
       return node; 
   }
   return temp;
}

tree* tree::successor(tree *node)
{
    tree *temp;
    while(node)
    {
        temp=node;
        node=node->l_child;
    }
    
    return temp;
}

tree* tree:: delete_node(tree *node,int key)
{
    tree T(0);
    tree *temp=T.search(node,key);
    if(temp->l_child==nullptr && temp->r_child==nullptr)
    {
        delete temp;
        temp=NULL;
        return node;
    }
    if(temp->l_child==nullptr)
    {
        tree* local=temp;
        temp=temp->r_child;
        delete local;
        return node;
    }
    else if(temp->r_child==nullptr)
    {
        tree* local=temp;
        temp=temp->l_child;
        delete local;
        return node;
    }
    else
    {
        tree* local=T.successor(temp->r_child);//finding smallest element in the right subtree
        temp->data=local->data;
        temp->r_child=delete_node(node->r_child,local->data);
        return node;
    }
}


void tree::display(tree *root)
{
    if(root!=NULL)
    {
        display(root->l_child);
        cout<<root->data<<" ";
        display(root->r_child);
    }
}

int main()
{
   int a;
    tree T(0),*node=nullptr;
   
    for(int i=0;i<6;i++)
    {
        cin>>a;
        node=T.insert(node,a);
    }
    T.display(node);
    cout<<endl<<"Enter to Delete : ";
    cin>>a;
    node=T.delete_node(node,a);
    T.display(node);
}