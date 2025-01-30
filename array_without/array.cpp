#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Array_ADT
{
private:
    int size;
    int *arr;
    int length;

public:
    Array_ADT() : length(0)
    {
        cout << "Enter Size of Array: ";
        cin >> size;
        arr = new int[size];
    }
    Array_ADT(int size) : size(size), length(0)
    {
        arr = new int[size];
    }
    void fill()
    {
        cout << "How many items you want to fill: ";
        int no_items;
        cin >> no_items;
        if (no_items <= size && no_items > 0)
        {
            cout << "********  Fill Array with elements  ***********" << endl;
            for (size_t i = 0; i < no_items; i++)
            {
                cout << "Enter element at index " << i << ": ";
                cin >> arr[i];
                cout << endl;
            }
            length = no_items;
            cout << "--------------------------------------------------------\n";
        }
    }
    void display()
    {
        cout << "********  Displaying Array  ***********" << endl;
        cout << "Array: ";

        for (size_t i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
        cout << "--------------------------------------------------------\n";
    }
    void append(int newItem)
    {
        if (length < size)
        {
            arr[length] = newItem;
            length++;
        }
        else
        {
            cout << "Array is full. Cannot append " << newItem << endl;
            cout << "--------------------------------------------------------\n";
        }
    }
    bool isFull()
    {
        if (size == length)
            return true;
        return false;
    }
    bool isEmptyIndex(int index)
    {
        if (index >= length)
            return true;
        return false;
    }
    void insert(int index, int newItem)
    {
        if (index < size && index >= 0)
        {
            if (isFull())
                cout << "array is full" << endl;
            else
            {
                if (isEmptyIndex(index))
                {
                    arr[index] = newItem;
                    length++;
                }
                else
                {
                    for (int i = length; i > index; i--)
                    {
                        arr[i] = arr[i - 1];
                    }
                }
            }
        }
        else
            cout << " error: index out of range " << endl;
        cout << "--------------------------------------------------------\n";
    }
    void setlength(int l)
    {
        length = l;
    }
    int search(int key)
    {

        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
            {
                return i;
                break;
            }
        }
        return -1;
    }
    void Enlarge(int NewSize)
    {
        if (NewSize <= size)
        {
            cout << "New size must be greater than " << size << endl;
            return;
        }
        else
        {
            int *old = arr;
            arr = new int[NewSize];
            for (int i = 0; i < length; i++)
                arr[i] = old[i];

            delete[] old;
            size = NewSize;
        }
    }
    friend Array_ADT Merge(Array_ADT a, Array_ADT b);
    void Delete(int index)
    {
        if (index >= 0 && index < length)
        {
            for (size_t i = index; i < length - 1; i++)
                arr[i] = arr[i + 1];
            length--;
        }
        else
            cout << " error: index out of range " << endl;
    }
    int getSize()
    {
        return size;
    }
    int getLength()
    {
        return length;
    }
};
Array_ADT Merge(Array_ADT a, Array_ADT b)
{
    int i;
    Array_ADT result(a.getSize() + b.getSize());
    for (i = 0; i < a.getLength(); i++)
    {
        result.arr[i] = a.arr[i];
        result.setlength(i + 1);
    }
    int j = i;
    for (int i = 0; i < b.getLength(); i++)
    {
        result.arr[j++] = b.arr[i];
        result.setlength(j);
    }

    delete[] a.arr;
    delete[] b.arr;

    return result;
}
int main()
{
    Array_ADT array;
    cout << "********  Creating Array  ***********" << endl;
    cout << "--------------------------------------------------------\n";
    array.fill();
    // array.display();
    // cout << "Enter number to add in the array end: " << endl;
    // int item;
    // cin >> item;
    // array.append(item);
    // array.display();
    // cout << "Enter item to insert in this array: " << endl;
    // cin >> item;
    // cout << "Enter index for this item to add to array: \n";
    // int index;
    // cin >> index;
    // array.insert(index, item);
    // array.display();
    // cout << "Enter index for deletation: " << endl;
    // cin >> index;
    // array.Delete(index);
    // array.display();
    // cout << "Size of array: " << array.getSize() << endl;
    // cout << "Length of array: " << array.getLength() << endl;
    // cout << "Enter the value to search for: \n";
    // int key;
    // cin >> key;
    // index = array.search(key);
    // if (index != -1)
    //     cout << "Found " << key << " in array at index: " << index << endl;
    // else
    //     cout << "This key " << key << " is not found in array" << endl;

    // cout<<"Enter new size for array: \n";
    // int newSize;cin>>newSize;
    // array.Enlarge(newSize);

    // cout << "Size of array: " << array.getSize() << endl;
    // cout << "Length of array: " << array.getLength() << endl;
    array.display();
    Array_ADT array2(3);
    array2.fill();
    array2.display();
    Array_ADT mergedArray = Merge(array, array2);
    cout << "Size of array: " << mergedArray.getSize() << endl;
    cout << "Length of array: " << mergedArray.getLength() << endl;
    mergedArray.display();
    return 0;
}
