#include <iostream>
#include <ctime>


//primitives on data types, usage of each data type with its intended properties

// #define and const (assuming type before writing)

// storage

// arrays, returning from funcs, supplying funcs with arrays as args

using namespace std;

#define DEF_NUM 10.5
#define DEF_CHAR "hello"


double getAverage(int arr[], int size);
int* getRandom();

int main() {


    //data types sizes of
    cout << "the followings are in bytes aka orders of 8 bits" << endl;
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    cout << "unsig char " << sizeof(unsigned char) << endl;

    //#define and const 
    const int CONST_NUM = 10;
    const char* CONST_CHAR = "he";

    cout << "shows the diffy btw #define and const" << endl;
    cout << "num define size: " << sizeof(DEF_NUM) << endl;
    cout << "num const size: " << sizeof(CONST_NUM) << endl;
    cout << "char define size: " << sizeof(DEF_CHAR) << endl;
    cout << "char const size: " << sizeof(CONST_CHAR) << endl;




    //A storage class defines the scope (visibility and life-time of variables and/or functions within a C++ Program)
    //These specifiers precede the type that they modify
    cout << "storage related things below\n" << endl;

    int intstorage=5;
    auto autostorage=5;  //default storage, let OS decide
    register int registerstorage = 5; //it MIGHT get stored in the register depending on HW and OS availability
    static int staticstorage = 5; //the compiler keeps the local or global variable in existence during the lifetime of the program
                                  //instead of creating and destroying it each time it comes and goes out of scope
    extern void extern_func(); //give a reference of a global var which is visible to ALL of the program files
                               //assuming that you are writing a project with multiple cpps
                               //no var can be init with extern because it points the var name at a storage location
                               //that has been previously defined.
                               //extern is used when multiple files share the same global vars.


    //array creation

    //      TYPE ARRAYNAME [ ARRAYSIZE ];

    double myArrayEmpty[5];
    double myArrayFull[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

    cout << "size of whole array in bytes: "<<sizeof(myArrayFull) << endl;
    cout << "print the dereffed array &: " << &myArrayFull << endl;
    cout << "size of dereffed & array in bytes: " << sizeof(&myArrayFull) << endl;
    cout << "size of pointer * array in bytes: " << sizeof(*myArrayFull) << endl;  //size of a pointer is 8 bytes on 64bit machines
    cout << "print the array pointer: " << *myArrayFull << endl;

    int myMultiArrayFull[3][4] = {
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
    };



    int* emptyPointer = NULL;
    int pointerArrayEmpty[3];
    cout << "empty pointer b4 init:" <<emptyPointer << endl;
    emptyPointer = pointerArrayEmpty;
    cout <<"empty pointer after init: "<<emptyPointer << endl;

    int* fullPointer=NULL;
    int pointerArrayFull[3] = { 1,2,3 };
    cout << "empty pointer b4 init:" << fullPointer << endl;
    fullPointer = pointerArrayFull;
    cout << "empty pointer after init:" << fullPointer << endl;



    //pass an array as arg to a function
    //sole arrays cant be passed, you need to pass a pointer to func 
    //by using the name of the array without any indexes,
    //you point to the zeroth element of the array


    //use the getAverage function to pass your array as args
    double avg;

    int *pointsToZerothElement; //points to a rando integer which will be changed later on
    int (*pointsToArrayof3)[3]; //points to an array of 3 integers
    int averageArray[3] = { 10,20,30 };  //a rando array which will be influenced by the pointers

    pointsToZerothElement = averageArray; //now the pointer defined above points to the zeroth element of the averageArray array
    pointsToArrayof3 = &averageArray; //now the pointer defined above points to the whole array of averageArray


    cout << "pass the pointer to the zeroth element of the array (averageArray)to a func by writing averageArray w/o indexes" << endl;
    avg = getAverage(averageArray, 3);
    cout << "calced avg: " << avg << endl;
    cout << "point to the zeroth element of the averageArray by writing averageArray: " << averageArray << endl;
    cout << "point to the zeroth element of the averageArray by writing pointsToZerothElement: " << pointsToZerothElement<< endl;
    cout << "point to the whole array of the averageArray by writing pointsToArrayof3: " << pointsToArrayof3<< endl;
    cout << "point to the whole array of the averageArray by writing &averageArray: " << &averageArray << endl;





    //return an array from a function
    //you cant return the address of a local variable to outside of the function
    //so you would have to define the local variable as static variable.

    int* returnFromFunctionPointer;  //cr an uninit pointer which will be init in the following line
    returnFromFunctionPointer = getRandom(); //the return value of the getRandom() function is assigned to the pointer

    for (int i = 0; i < 10; i++) {
        cout << "*returnFromFunctionPointer( + " << i << ") : ";
        cout << *(returnFromFunctionPointer + i) << endl;
    }

    return 0;
}


//used to test how you can supply a func with an array
double getAverage(int arr[], int size) {
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i) {
        sum += arr[i];
    }
    avg = double(sum) / size;

    return avg;
}

//used to test how you can return an array from a function
int* getRandom() {

    //a static variable needs to be defined here so that it can be transported outside of the function
    //try it without static to see that it doesnt work at all
    static int  r[10];

    // set the seed
    srand((unsigned)time(NULL));
    //create rando numbers and assign the creation to the empty r array which was defined above
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }

    return r;
}