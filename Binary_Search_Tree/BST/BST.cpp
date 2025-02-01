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
    // Because we don't change the Tree ,you should have Insert function take only new Item
    void Insert(int newItem){
        Root = Insert(Root, newItem);
    }
    // Traversal function
    void PreOrder(Node* Pnode){
        if(Pnode!= NULL){
            cout<<Pnode->Data<<" ";
            PreOrder(Pnode->NL);
            PreOrder(Pnode->NR);
        }
        return;
    }
    void Inorder(Node* Pnode){// Left -> Root -> Right
        if(Pnode!= NULL){
            Inorder(Pnode->NL);
            cout<<Pnode->Data<<" ";
            Inorder(Pnode->NR);
        }
    }
    void PostOrder(Node* Pnode){// Left -> Right -> Root
        if(Pnode!= NULL){
            PostOrder(Pnode->NL);
            PostOrder(Pnode->NR);
            cout<<Pnode->Data<<" ";
        }
    }
    // overloading functions
    void PreOrder(){
        PreOrder(Root);
    }
    void Inorder(){
        Inorder(Root);
    }
    void PostOrder(){
        PostOrder(Root);
    }
    // Function to search an item in BST
    bool Search(Node* Pnode, int data){
        if(Pnode == NULL)
            return false;
        if(data < Pnode->Data)
            return Search(Pnode->NL, data);
        else if(data > Pnode->Data)
            return Search(Pnode->NR, data);
        else
            return true;
    }
    // overloading function
    bool Search(int data){
        return Search(Root, data);
    }
    // Function to delete an item in BST
    Node* Delete(Node* Pnode, int data){}
    void DestroyTree(Node* Pnode){
        if(Pnode == NULL) return;
        DestroyTree(Pnode->NL);
        DestroyTree(Pnode->NR);
    delete Pnode;
    }
    // overloading function
    void DestroyTree(){
        DestroyTree(Root);  // Delete all nodes
        cout<<"\nMemory freed\n";
    }

};


int main(){
    BST bst;
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(70);
    bst.Insert(60);
    bst.Insert(80);
    cout<<"PreOrder traversal is: ";
    bst.PreOrder();
    cout<<"\nInorder traversal is: ";
    bst.Inorder();
    cout<<"\nPostOrder traversal is: ";
    bst.PostOrder();
    cout<<"\nSearch 20: "<<(bst.Search(20)? "Found" : "Not Found")<<endl;
    cout<<"\nSearch 90: "<<(bst.Search(90)? "Found" : "Not Found" )<<endl;
    bst.DestroyTree();
    cout<<"\nSearch 20 after deleting: "<<(bst.Search(20)? "Found" : "Not Found")<<endl;
    return 0;
}