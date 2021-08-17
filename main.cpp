#include<iostream>
#include"binarytree.hpp"
using namespace std;

int main(){
    bintree<int> t = bintree<int>(1);
    
    t.insert(2, 1, 0);
    t.insert(3, 1, 1);
cout<<"a"<<endl;
    t.insert(7, 2, 0);cout<<"a"<<endl;
    t.insert(6, 2, 1);cout<<"a"<<endl;
    t.insert(5, 3, 0);cout<<"a"<<endl;
    t.insert(4, 3, 1);cout<<"a"<<endl;


    t.printZigZag(0,0,1);
    return 0;
}