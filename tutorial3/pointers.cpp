// dynamic_memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    cout << "Hello World!\n";

    double* double_pointer = NULL; // define null pointer 
    double_pointer = new double; // doublepointer is our variable

    cout << "print double_pointer address: " << double_pointer << endl; //print address of pointer, keep in mind that this is a null pointer
    cout << "print dereferenced double_pointer: " << &double_pointer << endl; //deref the pointer
    cout << "print real value of double_pointer: "<< *double_pointer << endl; //print real value of pointer, this will throw compiler warning because it is uninit memory

    *double_pointer = 5.0; //assign some random value to the pointer
    cout << "\n";
    cout << "print double_pointer address: " << double_pointer << endl; //print address of pointer, keep in mind that this is a null pointer
    cout << "print dereferenced double_pointer: " << &double_pointer << endl; //deref the pointer
    cout << "print real value of double_pointer: " << *double_pointer << endl; //print real value of pointer, this will throw compiler warning because it is uninit memory

    /*
    delete double_pointer;
    cout << "double pointer is deleted" << endl;
    cout << "print pointer address: " << double_pointer << endl; //print address of pointer, keep in mind that this is a null pointer
    cout << "print dereferenced pointer: " << &double_pointer << endl; //deref the pointer
    cout << "print real value of pointer: " << *double_pointer << endl; //print real value of pointer, this will throw compiler warning because it is uninit memory
    */

    char* char_pointer = NULL;
    char_pointer = new char[20];

    cout << "\n";
    cout << "print char_pointer address: " << char_pointer << endl; //print address of pointer, keep in mind that this is a null pointer
    cout << "print dereferenced char_pointer: " << &char_pointer << endl; //deref the pointer
    cout << "print real value of char_pointer: " << *char_pointer << endl; //print real value of pointer, this will throw compiler warning because it is uninit memory

}

