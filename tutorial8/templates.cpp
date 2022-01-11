
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

/*

                        templates are used to NOT repeat code,
                        you can write the same function with different accepting data types
                        but this would take a long time if you have a lot of variables to write
                        by creating templates, you can write the function once and then automatically
                        pass variables of different types to it

*/


using namespace std;


//write a function template that accepts integer, double or string values, regardless of these variables being specifically provided to the function

/*
inlines the function to reduce overhead
return value is automatically given as T, which was the type provided to the function
idk what const& does
*/
template <typename T>
inline T const& giveMaximum(T const& first_param, T const& second_param) {
    if (first_param < second_param){
        return second_param;
    }
    else {
        return first_param;
    }
}



//both of these variables need to be available in the main function, which will invoke the swap function
//thats why they have to be passed as reference
void swap(int& swap1, int& swap2) {
    int temp = swap1;
    swap1 = swap2;
    swap2 = temp;
}



//we created a "generic" type by the name of T, which replaces the usual ints, doubles, chars...
//just like writing a normal function with a determined type, you can do the same with using T as your type.
template <typename T>
void swap_template(T& swap1, T& swap2) {
    T temp = swap1;
    swap1 = swap2;
    swap2 = temp;
}


template <class T>
class template_class {
    T class_template_var1, class_template_var2;
    public:

        template_class(T constructor_arg1, T constructor_arg2) {        //constructor has to have the same name as the class name
            class_template_var1 = constructor_arg1;
            class_template_var2 = constructor_arg2;
        }

        T public_template_function(); //in order to make this function be template-like, it has to be defined outside of the class with template again


};


template <class T>                                  //this is the complete syntax required to create a function which will be used in a class
T template_class<T>::public_template_function() {
    return (class_template_var1 > class_template_var2 ? class_template_var1 : class_template_var2 ); //it returns type T
}





int main()
{
    std::cout << "Hello World!\n";


    //function template variables
    int int1 = 100;
    int int2 = 200;
    double double1 = 30;
    double double2 = 40;
    string string1 = "smaller";
    string string2 = "biggerrrr";

    //function template try-outs
    cout << "template with integers: " << giveMaximum(int1, int2) << endl;
    cout << "template with doubles: " << giveMaximum(double1, double2) << endl;
    cout << "template with strings: " << giveMaximum(string1, string2) << endl;
    cout << "size of strings; " << sizeof(string1) << ", " << sizeof(string2) << endl;


    //try out the function with passing as reference
    int ref1 = 10, ref2 = 15;
    cout << "swapping variables: " << ref1 << ", " << ref2 << endl;
    swap(ref1, ref2);
    cout << "swapped varialbes are: " << ref1 << ", " << ref2 << endl;






    //template function with a generic type that accepts the provided variable automatically

    /*
            you can auto decide the type of vars passed to the function as well
            swap_template <int>(template1,template2) will automatically know that you are passing an integer
            and it will replace all T's inside the function with the "int" type
    */
    int template1 = 31, template2 = 37;
    cout << "swapping int variables: " << template1 << ", " << template2 << endl;
    swap_template(template1, template2);
    cout << "swapped int varialbes are: " << template1 << ", " << template2 << endl;

    string char1 = "char1", char2= "char2";
    cout << "swapping string variables: " << char1<< ", " << char2 << endl;
    swap_template(char1, char2);
    cout << "swapped string varialbes are: " << char1 << ", " << char2 << endl;





    /*
                            CLASS TEMPLATES
    */

    template_class <int>init_class(69, 31); //create the class with constructor initialization parameters, you have to supply the type beforehand
                                            //anywhere the class has T, it will be substituted with int
    cout << init_class.public_template_function();

}
