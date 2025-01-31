#include<iostream>
#include <string>

using namespace std;

class Node {
    public:
    
    int data;
    Node* next;
    
    Node(int value){
        data = value;
        next = NULL;
    }
};
class LinkedStack {
    public:
    Node* top;
    LinkedStack(){
        top = NULL;
    }
    bool IsEmpty(){
        return (top == nullptr);
    }
    void push(int NewItem)
    {
        Node *n2 = new Node(NewItem);
        n2->next = nullptr;

        if (IsEmpty())
        {
            top = n2;
        }
        else
        {
            n2->next = top;
            top = n2;
        }
    }
    int pop(){
        
    }
    void display()
    {
        Node* temp = top;
        cout<<"Stack: \n";
        int i=1;
        while(temp!=NULL)
        {

            cout<<"Item "<<i++<<" = "<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
        LinkedStack Stack;
    for (size_t i = 0; i < 5; i++)
    {
        cout<<"Enter Item "<<i+1<<": ";
        int item;
        cin>>item;
        Stack.push(item);
    }
    Stack.display();
    


    return 0;
}