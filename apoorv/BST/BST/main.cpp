//
//  main.cpp
//  Sample
//
//  Created by Apoorv Anurag on 22/11/2020.
//

#include <iostream>
#include "BST.hpp"

using namespace::std;

//fib(n) = fib(n-1) + fib (n-2)
//fib(0) = 0;
//fib (1) = 1;

//fib(4) = fib(3) + fib(2)
//fib(3) = fib(2) + fib(1)
//fib(2) = fib(1) + fib(0)

int fib(int n) {

    // base case
    if(n==0)
        return 0;
    if (n==1)
        return 1;
    
    //recursive
    int x = fib(n-1);
    int y = fib(n-2);
    
    //combination
    return x+y;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    BST obj;
    
    obj.insert(20);
    obj.insert(5);
    obj.insert(30);
    obj.insert(-10);
    obj.insert(10);
    obj.insert(15);
    obj.insert(50);
    obj.insert(25);
    
    cout << obj.height(obj.root) << endl;
    
    //cout<< obj.lowestCommonAncestor(50, 10) << endl;
    
    //cout<< obj.successor(-10) << endl;
//    int c = -10;
//    while (c != -1000009) {
//        c =obj.successor(c);
//        cout << c << endl;
//    }
    
    //cout<< obj.contains(-10);
    
    
    return 0;
}
