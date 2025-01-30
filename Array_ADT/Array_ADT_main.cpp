#include<iostream>
#include<string>
#include "D:\file_c\Desktop\Data_Structures\Array\Array_ADT.h"
using namespace std;


int main() {
    Array_ADT array;
    array.fill();
    array.display();
    array.append(5);
    array.display();
    array.insert(6,6);
    array.display();
    
    return 0;
}