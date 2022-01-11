
#include <iostream>
#include <exception>

using namespace std;


double division(int a, int b);

int main()
{
    std::cout << "Hello World!\n";

    double temp;
    try {  //this is what we are trying to accomplish
        temp = division(10, 0);
        cout << temp << endl;
    }
    catch (const char* msg) { //if exception occurs, do the following
        cerr << msg << endl;
    }



    struct customException : public exception {  //define how the customexception will be handled,
                                                 // this must be known before the exception is thrown, otherwse undefined error will be encountered
        const char* what() const throw() {
            return "this is a custom exception return.";
        }
    };


    try {  //this is what we are trying to accomplish
        throw customException();
    }
    catch (customException& e) { //if exception occurs, do the following
        cout << "heads up: custom exception caught.\n";
        cout << e.what();
    }
}

   
double division(int a, int b) {
    if (b == 0)
    {
        throw "division by zero cant be handled by machines!"; //this will be written in the catch block
    }
    return (a / b);
}
