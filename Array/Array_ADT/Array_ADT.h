#include<iostream>
#include<string>

using namespace std;
class Array_ADT
{
private:
    int size;
    int* arr;
    int length;
public:
    //default constructor
    Array_ADT();
    //parameterized constructor
    Array_ADT(int size);
    //Fill array
    void fill();
    //Display array
    void display();
    // Append array
    void append(int newItem);
    // isFull function
    bool isFull();
    //isEmpty index function
    bool isEmptyIndex(int index);
    //insert array
    void insert(int index, int newItem);
    //search array
    int search(int key);
    //delete array
    void Delete(int index);
    //Enlarge to change size of
    void enlarge(int newSize);
    //merge array
    
    ~Array_ADT();
};
