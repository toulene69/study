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

Node* lcaHelper(Node* root, int a, int b) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == a || root->val == b) {
        return root;
    } else if (root->val > a && root->val < b ) {
        return root;
    } else if (root->val > a && root->val > b) {
        return lcaHelper(root->lChild, a, b);
    } else {
        return lcaHelper(root->rChild, a, b);
    }
}

int BST::lowestCommonAncestor(int a, int b) {
    
    if (a > b) {
        swap(a, b);
    }
    if(this->contains(a) && this->contains(b)) {
        Node *lca = lcaHelper(this->root, a, b);
        if (lca != NULL) {
            return lca->val;
        }
    }
    return -10000009;
}

int BST::successor(int a) {
    stack<Node*> path;
    Node *current = this->root;
    // find a
    // store the path
    // if a has right subtree -> find the smallest in right subtree of a
    // else trace back the path and find first right turn
    while (current != nullptr) {
        if (current->val == a) {
            break;
        } else if (current->val > a) {
            path.push(current);
            current = current->lChild;
        } else {
            path.push(current);
            current = current->rChild;
        }
    }
    if (current == NULL) {
        return -1000009;
    }
    if (current ->rChild != NULL) {
        current = current->rChild;
        while (current->lChild != nullptr) {
            current = current->lChild;
        }
        return current->val;
    } else {
    
        while (!path.empty()) {
            Node *parent = path.top();
            
            if (parent->lChild == current) {
                return parent->val;
            } else {
                current = parent;
                path.pop();
            }
        }
        return -1000009;
    }
}

int BST::height(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    
    return max(this->height(root->lChild), this->height(root->rChild)) + 1;
}

bool BST::isBST(Node * root) {
    if (root == nullptr) {
        return true;
    }
    if (root->lChild-> val < root->val && root->rChild->val > root->val) {
        return isBST(root->lChild) && isBST(root->rChild);
    } else {
        return false;
    }
}
