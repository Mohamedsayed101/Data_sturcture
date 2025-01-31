#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class LinkedStack
{
public:
    Node *top;
    LinkedStack()
    {
        top = NULL;
    }
    bool IsEmpty()
    {
        return (top == nullptr);
    }
    void peek(){
        if(IsEmpty()){
            cout << "Stack is empty!" << endl;
        }
        else{
            cout << "Top element is: " << top->data << endl;
        }
    }
    // search 
    bool search(int value){
        Node *temp = top;
        while(temp!=NULL){
            if(temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool IsFull(){
        Node *ptr=new Node(10);
        if(ptr==nullptr){
            delete ptr;
            cout<<"The stack is full!"<<endl;
            return true;
        }
            delete ptr;
            return false;
    }
    // get counter
    int getCounter(){
        int count = 0;
        Node *temp = top;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
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
    int pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty!";
            return -1;
        }
        int popped = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return popped;
    }
    void display()
    {
        Node *temp = top;
        cout << "Stack: \n";
        int i = 1;
        while (temp != NULL)
        {

            cout << "Item " << i++ << " = " << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedStack Stack;
    for (size_t i = 0; i < 5; i++)
    {
        cout << "Enter Item " << i + 1 << ": ";
        int item;
        cin >> item;
        Stack.push(item);
    }
    Stack.display();
    Stack.peek();
    cout << "Popped item: " << Stack.pop() << endl;
    Stack.display();
    cout << "Stack size: " << Stack.getCounter() << endl;

    // Test the IsFull function

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get(); // Pause before exit
    return 0;
}