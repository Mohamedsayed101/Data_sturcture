#include<iostream>
#include<string>

using namespace std;
class Node
{
public:
    int Data;
    Node *NR;// next rigth node
    Node *NL;// next left node
    Node(int data){
        NR = NL = NULL;
        Data = data;
    }
    Node(){}
};
class BST
{
    public:
    Node *Root;
    BST():Root(NULL){}
    Node* Insert(Node* Pnode, int data){
        if(Pnode == NULL){ // base case
            Node *newnode = new Node(data);
            Pnode=newnode; 
        }else if(data < Pnode->Data){
            Pnode->NL = Insert(Pnode->NL, data);
        } else{
            Pnode->NR = Insert(Pnode->NR, data);
        }
        return Pnode;
    }
    ~BST(){}
};


int main(){

    return 0;
}