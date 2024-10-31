//
// Created by Hongzhuo CHEN on 10/30/24.
//

#include "Vector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main(){
    Vector arr;

    // Adding elements
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    //arr.add(50);

    cout << "Array elements: ";
    arr.print();

    // Accessing elements
    cout << "Element at index 2: " << arr.get(2) << std::endl;

    // Removing an element
    arr.remove(2);
    cout << "Array after removing index 2: ";
    arr.print();

    arr.add(50);
    try { //try to add element to a full Vector
        arr.add(60);
    }
    catch (const exception& ex){
        cout<<ex.what()<<"\n";
    }
    return 0;
}