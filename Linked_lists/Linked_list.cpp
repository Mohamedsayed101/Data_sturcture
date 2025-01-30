#include <iostream>
using namespace std;

class node
{
public:
    int Data;
    node *Next;
};

class Linked_list
{
public:
    node *Head;

    Linked_list()
    {
        Head = nullptr;
    }

    bool IsEmpty()
    {
        return (Head == nullptr);
    }

    void create_Front(int newItem)
    {
        node *n2 = new node();
        n2->Data = newItem;
        n2->Next = Head;
        Head = n2;
    }

    int getCount()
    {
        int nodeCount = 0;
        node *temp = Head;
        while (temp != nullptr)
        {
            temp = temp->Next;
            nodeCount++;
        }
        return nodeCount;
    }

    bool isFound(int Key)
    {
        node *temp = Head;
        while (temp != nullptr)
        {
            if (temp->Data == Key)
                return true;
            temp = temp->Next;
        }
        return false;
    }

    void display()
    {
        cout << "************* Linked List *************" << endl;
        node *temp = Head;
        int i = 1;
        while (temp != nullptr)
        {
            cout << "Item " << i << " = " << temp->Data << endl;
            temp = temp->Next;
            i++;
        }
        cout << "---------------------------------------" << endl;
    }

    void insert_end(int NewItem)
    {
        node *n2 = new node();
        n2->Data = NewItem;
        n2->Next = nullptr;

        if (IsEmpty())
        {
            Head = n2;
        }
        else
        {
            node *temp = Head;
            while (temp->Next != nullptr)
            {
                temp = temp->Next;
            }
            temp->Next = n2;
        }
    }

    void insert_at_position(int NewItem, int Pos)
    {
        if (Pos < 0 || Pos > getCount())
        {
            cout << "Invalid position" << endl;
            return;
        }
        
        if (Pos == 0)
        {
            create_Front(NewItem);
            return;
        }

        if (Pos == getCount()) // Append at end
        {
            insert_end(NewItem);
            return;
        }

        node *n2 = new node();
        n2->Data = NewItem;
        node *temp = Head;

        for (int i = 0; i < Pos - 1; i++)
        {
            temp = temp->Next;
        }

        n2->Next = temp->Next;
        temp->Next = n2;
    }
    // delete
    void delete_the_First_Item(){
        if(IsEmpty()){
            cout << "List is empty\n";
            return;
        }
        node *temp = Head;
        Head = Head->Next;
        delete temp;
    }
    void delete_at_position(int Pos){
        if(IsEmpty()){
            cout << "List is empty\n";
            return;
        }
        if(Pos < 0 || Pos >= getCount()){
            cout << "Invalid position\n";
            return;
        }
        if(Pos == 0){
            delete_the_First_Item();
            return;
        }
        if(Pos == getCount()-1){
            delete_the_last_item();
            return;
        }
        node *temp = Head;
        for (int i = 0; i < Pos - 1; i++){
            temp = temp->Next;
        }
        node *del = temp->Next;
        temp->Next = del->Next;
        delete del;        ;
        cout << "Item deleted successfully at position " << Pos << endl;
    }
    void delete_the_last_item() {
        if (IsEmpty()) {
            cout << "List is empty\n";
            return;

        }
        if (Head->Next == nullptr) {
            delete Head;
            Head = nullptr;
            return;
        }
        node *temp = Head;
        while (temp->Next->Next!= nullptr) {
            temp = temp->Next;
        }
        delete temp->Next;
        temp->Next = nullptr;
        cout << "Last item deleted successfully\n";
        cout << "---------------------------------------" << endl;
    }
    //search
    void search(int Key) {
        node *temp = Head;
        int index = 0;
        while (temp!= nullptr) {
            if (temp->Data == Key) {
                cout<<"number "<<Key<<" is exist in index "<< index<<" in list \n";
                return;
            }
            temp = temp->Next;
            index++;
        }
        cout<<"The number "<<Key<<" is not found in this list \n"; // Key not found
    }
    //Replace function
    void replace(int OldItem, int NewItem) {
        node *temp = Head;
        while (temp!= nullptr) {
            if (temp->Data == OldItem) {
                temp->Data = NewItem;
                cout << "Number "<<OldItem<<" replaced by "<<NewItem<<" successfully\n";
                return;
            }
            temp = temp->Next;
        }
        cout<<"The number "<<OldItem<<" is not found in this list \n"; // Key not found
    }
    ~Linked_list()
    {
        node *temp;
        while (Head != nullptr)
        {
            temp = Head;
            Head = Head->Next;
            delete temp;
        }
        cout << "Linked list deleted\n"; // Debugging message
    }
};

int main()
{
    Linked_list list1;
    list1.create_Front(1);
    list1.insert_end(2);
    list1.insert_at_position(3, 1);
    cout << "Total items in list: " << list1.getCount() << endl;
    list1.display();

    return 0;
}
