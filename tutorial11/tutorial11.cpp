#include <iostream>
#include <cstring>
#include <string>


//c-style character strings
//This string is actually a one-dimensional array of characters which is terminated by a null character '\0'


//data structures aka structs 
//structs can be initiated like c structs or c++ structs which have different syntax
//if you want to use char on struct, you have to use c-string methods str... otherwise you cant do fuck all

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    char greeting1[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char greeting2[] = "hello_new";
    char greeting3[5] = { 'H', 'e', 'l', 'l', 'o' };  //this doesnt work properly, as you can see by how it is displayed on the console

    cout << greeting1 << endl;
    cout << "size of greeting1: " << sizeof(greeting1) << endl;
    cout << greeting2 << endl;
    cout << "size of greeting2: " << sizeof(greeting2) << endl;
    cout << greeting3 << endl;
    cout << "size of greeting3: " << sizeof(greeting3) << endl;


    //string operations use the standard library cstring

    char str1[20] = "first";
    char str2[10] = "second";
    char str3[10];
    int  len;

    strcpy_s(str3, str1);
    cout << "copy procedure: strcpy( str3, str1) : " << str3 << endl;

    strcat_s(str1, str2); //to be concatted, the string needs to have enough bytes for the both of the strings altogether.
    cout << "concatanate both strings: strcat( str1, str2): " << str1 << endl;

    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;


    //c++ supports an advanced string library called string, which are used for the following methods.
    //string is then a type of var, which is manipulated more easily than c-strings


    string str1cpp = "first_cpp";
    string str2cpp = "second_cpp";
    string str3cpp;
    int  lencpp;

    // copy str1 into str3
    str3cpp = str1cpp;
    cout << "str3cpp : " << str3cpp << endl;

    // concatenates str1 and str2
    str3cpp = str1cpp + str2cpp;
    cout << "str1cpp + str2cpp : " << str3cpp << endl;

    // total length of str3 after concatenation
    lencpp = str3cpp.size();
    cout << "str3cpp.size() :  " << lencpp << endl;



    //usage of struct


    struct PERSON {   // Declare PERSON struct type
        int age;   // Declare member types
        long ss;
        float weight;
        string name;
    };   // Define object of type PERSON


    PERSON subject;  //declare the struct
    subject.age = 27;
    subject.ss = 1;
    subject.weight = 200;
    subject.name = "peter alert";


    cout << subject.age << endl;
    cout << subject.ss << endl;
    cout << subject.weight << endl;
    cout << subject.name << endl;
    return 0;
}
