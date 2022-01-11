

#include <iostream> 
#include <math.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
we are declaring variables
*/
int global_var_uninit; //auto init to 0
int global_var_init = 5;
char c;
//char* long_char ="has to be initialized";
const char s[] = "initialized string"; //this has to be initialized otherwise
                                      //theres gonna be compiler errors

const char s1[] = "different length, lets see the size difference"; //check size diff
/*declare a function, this means that this function MIGHT be used in the 
whole program, so we are giving the compiler a heads up
*/

int hexa = 0xFeeL;
int un_signed = 5u;
int long_ = 5l;

#define NUMBER 100
#define NUMBER2 200
#define STRING "hello"



///////////////////////////////////////////////////////////////////////////////////////////////////
/*we are talking about modifiers
modifiers can change the behavior of int double and char
*/
unsigned x; //auto assigns int
unsigned int y;
short short_;






///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
/*
* we are declaring functions
*/
void tutorialFunc();
void func();
void accessToGlobalVars();
void argFunc(); //a function that takes arguments from user input

int callByValue( int outer_arg1,  int outer_arg2); //a function that specifically requires arguments 
                                                    //this is a call by value, it copies the actual value of an argument
                                                    //into the parameter of the function.
                                                    //changes made to the parameter inside the function have NO EFFECT on the argument.


void callByPointer(int* p1, int* p2);           //call by pointer, copies the address of the argument into the formal parameter
                                                //changes made to the parameter AFFECT the passed argument

void callByRef(int& ref1, int& ref2);               //call by reference, copies the reference of the argument into the formal parameter,
                                                //the reference is used to access the actual argument used in the call.

int defaultValue(int def1, int def2=5);

int main()
{
    cout << "im making various function calls in this program\n";
    //accessToGlobalVars();
    //tutorialFunc();
    //func();
    //argFunc();
    

    //defaultValue();
    /*
    int def1 = 3;
    int def2 = 4;
    int sum;

    sum = defaultValue(def1, def2);
    cout << sum << endl;


    sum = defaultValue(def1);
    cout << sum << endl;
    */

    //callByValue();
    /*
    int outer1 = 5.2;
    int outer2 = 10.2;
    int storage;
    storage = callByValue(outer1, outer2);
    cout << "stored value from outerargfunc" << endl;
    cout << storage << endl;
    */

    //callByPointer();
    /*
    int swap1 = 100;
    int swap2 = 200;

    callByPointer(&swap1, &swap2);

    cout << "we swapped values \n";
    cout << "swapped \n" << swap1;
    cout << "swapped \n" << swap2;
    */

    //callByRef();
    /*
    int swap1 = 100;
    int swap2 = 200;

    callByRef(swap1, swap2);

    cout << "we swapped values \n";
    cout << "swapped \n" << swap1;
    cout << "swapped \n" << swap2;
    */ 





}


/*
we are defining functions, aka writing the body of the functions
*/

void accessToGlobalVars() {
    cout << global_var_uninit << endl;
    cout << global_var_uninit << endl;
    cout << c << endl;
    cout << "size " << sizeof(c) << endl;
    cout << s << endl;
    cout << "size " << sizeof(s) << endl;
    cout << s1 << endl;
    cout << "size " << sizeof(s1) << endl;
    cout << hexa << endl;
    cout << "size " << sizeof(hexa) << endl;
    cout << un_signed << endl;
    cout << "size " << sizeof(un_signed) << endl;
    cout << long_ << endl;
    cout << "size " << sizeof(long_) << endl;
    cout << NUMBER << endl;
    cout << "size " << sizeof(NUMBER) << endl,
    cout << STRING << endl;
    cout << "size " << sizeof(STRING) << endl;
    cout << "size " << sizeof(x) << endl;
    cout << "size " << sizeof(y) << endl;
    cout << "size " << sizeof(short_) << endl;
}

void tutorialFunc() {

    float number;
    float square;
    cout << "Hello World!\n";
    cout << "enter a number and lets take the square root of it\n";
    cin >> number;
    square = sqrt(number);
    cout << "is this correct my nigga?\n";
    cout << square << endl;

    int divisor, divident, quotient, remainder;

    cout << "enter top and bottom \n";
    cin >> divident >> divisor;

    quotient = divident / divisor;
    remainder = divident % divisor;

    cout << "quotient= " << quotient << endl;
    cout << "remainder= " << remainder << endl;

    cout << "calculate the size of quotient " << sizeof(quotient) << endl;
    cout << "calculate the size of square " << sizeof(square) << endl;
    cout << "calculate the size of default float " << sizeof(float) << endl;

    cout << "we are now checking for oddity, enter a number\n";
    int checker;
    cin >> checker;

    if (checker % 2 == 0)
        cout << checker << "is even\n";
    else
        cout << checker << "is odd\n";

}

void func() {
cout << "the function has been called, this is a void return \n";
}

void argFunc() {
    int sum;
    int arg1, arg2;
    cout << "provide arg1 and arg2 separated with spacebar to sum them up\n inside this function which i call on main\n";
    cin >> arg1 >> arg2;

    sum = arg1 + arg2;

    cout << "here is the sum " << sum;
}

int callByValue(int outer_arg1, int outer_arg2) {

    cout << "this function will return int" << endl;
    
    return (outer_arg1 + outer_arg2);

}

void callByPointer(int *p1, int *p2) {

    int temp;       //temporary store value to swap the formal parameters

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "we are swapping both parameters with call by pointer\n";
}

void callByRef(int &ref1, int &ref2) {

    int temp;       //temporary store value to swap the formal parameters

    temp = ref1;
    ref1 = ref2;
    ref2 = temp;

    cout << "we are swapping both parameters with call by pointer\n";
}


int defaultValue(int def1, int def2) {  //showcases how you can supply less than the arguments necessary for the function by giving 
                                        //a default case so that the function always performs

    int result;
    result = def1 + def2;
    
    return (result);
};
