//
// Created by Hongzhuo CHEN on 10/30/24.
//

#ifndef HANDSON11_VECTOR_H
#define HANDSON11_VECTOR_H
#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* data;      // Pointer to the array of elements
    int capacity;   // Maximum capacity of the array
    int size;       // Current number of elements in the array

    // Resizes the array when capacity is reached
    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        // Copy existing elements to the new array
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        // Delete old array and reassign pointer
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // Constructor
    Vector(int initialCapacity = 4) : capacity(initialCapacity), size(0) {
        data = new int[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Adds an element to the end of the array
    void add(int value) {
        if (size == capacity) {
            throw std::out_of_range("Maximum capacity reached");
        }
        data[size++] = value;
    }

    // Removes the element at the given index
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        // Shift elements left to fill the gap
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // Gets the element at the given index
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Returns the current size of the array
    int getSize() const {
        return size;
    }

    // Prints the elements of the array
    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};


#endif //HANDSON11_VECTOR_H
