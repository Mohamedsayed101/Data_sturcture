#include<iostream>
#include<string>

using namespace std;
class Element {
public:
    int data;
    Element* next;
    Element(){
        next = NULL;
        data = 0;
    }
    };

class Queue
{
    Element* front;
    Element* back;
    
public:
    Queue(){ 
        front = back = NULL;
    }
    bool isEmpty(){
        return (front == NULL);//&&back == NULL);
    }
    bool IsFull(){
        Element* e = new Element();
        if(e==NULL)return false;
        delete e;
        return true;
    }
    void enqueue(int data){
        Element* newnode = new Element();
        newnode->data = data;
        if(isEmpty()){
            front = back = newnode;
        }
        else{
            back->next = newnode;
            back = newnode;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty. Dequeue operation not possible." << endl;
            return -1;
        }
        int data = front->data;
        Element* temp = front;
        front = front->next;
        if(front == NULL)
        back = NULL;
        delete temp;
        return data;
    }
    void Peak(){
        if(isEmpty()){
            cout << "Queue is empty. Peak operation not possible." << endl;
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }
    int getCounter(){
        int count = 0;
        Element* temp = front;
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    // search
    bool search(int data){
        Element* temp = front;
        while(temp!= NULL){
            if(temp->data == data){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    // remove all occurrences by using clear function
    void clear(){
        while(!isEmpty()){
            dequeue();
        }
    }
    void display(){
        Element* temp = front;
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue(){
        clear();
        cout << "Queue destroyed." << endl;
        delete front;
        delete back;
        front = back = NULL;
        cout << "Memory for queue destroyed." << endl; 
    }
};



int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front element is: " << q.dequeue() << endl;
    q.display();
    cout << "Is queue empty? " << (q.isEmpty()? "Yes" : "No") << endl;
    cout << "Is queue full? " << (q.IsFull()? "Yes" : "No") << endl;
    q.Peak(); 
    cout << "Size of queue: " << q.getCounter()<<endl;   
    return 0;
}