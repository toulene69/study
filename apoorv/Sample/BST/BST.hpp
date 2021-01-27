//
//  BST.hpp
//  Sample
//
//  Created by Apoorv Anurag on 22/11/2020.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


struct Node {
    
    int val;
    struct Node *lChild;
    struct Node * rChild;
    
};


class BST {
    
private:
    Node *root;
    Node* containsHelper(Node *node, int key);
    Node* getNewNode(int key);
public:
    BST();
    bool contains(int key);
    void insert(int key);
};


#endif /* BST_hpp */
