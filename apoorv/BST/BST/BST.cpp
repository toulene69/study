//
//  BST.cpp
//  Sample
//
//  Created by Apoorv Anurag on 22/11/2020.
//

#include "BST.hpp"


// all keys are disctinct set implementation

BST::BST(){
    this->root = nullptr;
}

Node* BST::containsHelper(Node *node, int key) {
    
    if (node == nullptr) {
        return nullptr;
    }
    
    if (node->val == key) {
        return node;
    } else if (node->val < key) {
        Node *r = containsHelper(node->rChild, key);
        if (r == nullptr) {
            return node;
        } else {
            return r;
        }
    } else {
        Node *l = containsHelper(node->lChild, key);
        if (l==nullptr) {
            return node;
        } else {
            return l;
        }
    }
    
}

Node* BST::getNewNode(int key) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->val = key;
    newNode->lChild = nullptr;
    newNode->rChild = nullptr;
    return newNode;
}


bool BST::contains(int key) {
    Node *res = containsHelper(this->root, key);
    if (res == nullptr) {
        return false;
    } else if (res->val == key) { // when
        return true;
    } else {
        return false;
    }
}

void BST::insert(int key) {
    Node *newNode = getNewNode(key);

    Node *parent = containsHelper(this->root, key);
    
    if (parent == nullptr) { // tree is null
        this->root = newNode;
        return;
    }
    if (parent->val == key) {
        cout<< "Already present"<<endl;
        return;
    }
    if (parent->val < key) {
        parent->rChild = newNode;
    } else {
        parent->lChild = newNode;
    }
    
}
