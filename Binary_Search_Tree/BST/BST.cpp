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
            PreOrder(Pnode->NR);
        }
    }
    void PostOrder(Node* Pnode){// Left -> Right -> Root
        if(Pnode!= NULL){
            PostOrder(Pnode->NL);
            PostOrder(Pnode->NR);
            cout<<Pnode->Data<<" ";
        }
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
    // Destructor to free memory
    // After deleting all nodes, we should call destructor of base class Node.
    // Because we didn't change the Tree, we should have destructor take no parameter.
    // So, destructor should have no return type and no parameters.
    ~BST(){
        // Call PostOrder to delete all nodes recursively.
        cout<<"\nPostOrder: ";
        PostOrder(Root);
        cout<<"Removed from Tree \n";
        while(Root!= NULL){
            Node *temp = Root;
            Root = Root->NR;
            delete temp;
        }
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
    cout<<"PreOrder traversal of the constructed BST is \n";
    bst.PreOrder(bst.Root);
    cout<<"\nInorder traversal of the constructed BST is \n";
    bst.Inorder(bst.Root);
    cout<<"\nPostOrder traversal of the constructed BST is \n";
    bst.PostOrder(bst.Root);
    cout<<"\nSearch 20 in BST? "<<(bst.Search(bst.Root, 20)? "Found" : "Not Found");
    cout<<"\nSearch 90 in BST? "<<(bst.Search(bst.Root, 90)? "Found" : "Not Found");
    return 0;
}