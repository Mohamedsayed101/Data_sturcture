#include "Array_ADT.h"

Array_ADT::Array_ADT():length(0)
{
    cout<<"Enter Size of Array: ";
    cin>>size;
    arr = new int[size];
}

Array_ADT::Array_ADT(int size):size(size),length(0)
{
    arr = new int[size];
}

void Array_ADT::fill()
{
    cout<<"How many items you want to fill: ";
    int no_items;
    cin>> no_items;
    if(no_items<=length&& no_items>0){
        cout<<"********  Fill Array with elements  ***********"<<endl;
        for (size_t i = 0; i < no_items; i++)
        {
            cout<<"Enter element at index "<<i<<": ";
            cin>>arr[i];
            cout<<endl;
        }
        length=no_items; 
    }
}

void Array_ADT::display()
{
    cout<<"********  Displaying Array  ***********"<<endl;
    cout<<"Array: ";

    for (size_t i = 0; i < length; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void Array_ADT::append(int newItem)
{
    if(length <size){
        arr[length] = newItem;
        length++;
    }
    else 
        cout<<"Array is full. Cannot append "<<newItem<<endl;
}

bool Array_ADT::isFull()
{
    if(size ==length)
        return true;
    return false;
}

bool Array_ADT::isEmptyIndex(int index)
{
    if(index >= length)
        return true;
    return false;
}

void Array_ADT::insert(int index, int newItem)
{
    if(index <size&&index >=0){
        if(isFull())
            cout<<"array is full"<<endl;
        else{
            if(isEmptyIndex(index)){
                arr[index]=newItem;
                length++;
            }
            else{
                for(int i=length;i>=index;i--){
                    arr[i]=arr[i-1];
                }
            }
        } 
    }
    else 
        cout<<" error: index out of range "<<endl;
}
