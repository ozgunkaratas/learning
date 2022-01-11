

#include <iostream>

using namespace std;


class Box {  //introductory level class. doesnt have fancy members or methods
public:
    double length;
    double width;
    double height;

private:
};

class Shape { //this class is used to explain derived classes, aka inheritance
public:

    void setWidth(int w) { //this function accepts the w argument and assigns that arg to the width,
                            // which is a public member of the shape class
                            //function does not return anything, so you cant equate the result to a variable,
                            //but when the function is called, it will do its job
        width = w;
    }
    void setHeight(int h) { //same as above
        height = h;
    }

protected:
    int width;  //without declaring these vars, you cant initialize them, these could also be put in public.
    int height;
};




class Rectangle: public Shape{ //derives from shape, will inherit shape properties but will not inherit private properties
    public:
        int getArea() { //this is a function that returns int
            return { width * height };
        }
};




class printVariousThings { //we discuss function and operator overloading
public:
    void printInt(int i) {
        cout << "this is an integer " << i << endl;
    }
    void printFloat(double f) {
        cout << "this is a float " << f << endl;
    }
    void printChar(char c) {
        cout << "this is a char " << c << endl;
    }

    void printString(const char s[]) {
        cout << "this is a C string " << s << endl;
    }
};




class abstractionLevels { //this class will show abstraction levels in action

private:  //declared first so that you understand that we are using this variable
    // hidden data from outside world
    int total;
public:
    abstractionLevels(int i = 0){ //this is a constructor, each time an object of the data type "abstractionLevels" is created
                               //the program will first run whatever was written in the constructor and create the object
                               //with some initialization
                               //here, the "i" var is initialized as 0
                                //constructors have the same name of the class

        total = i;
    }

    void addNumbers(int number) { //this function takes the argument number to execute its body
        total += number; //this means total = total + number
    }

    int getTotal() { //this function returns a value, so total can be assigned
        return total;
    }


};


class abstractClass {
public:
    virtual double virtualFunction() = 0; //this is a pure virtual function, syntax of creating a vir func is like this.
};



class baseAbstractClass {
public:
    // pure virtual function providing interface framework.
    virtual int getArea() = 0;
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

protected:
    int width;
    int height;
};

class DerivedClass1 : public baseAbstractClass {
public:
    int getArea() {  //the derived class implements the getArea function by itself, which returns what it defines
        return (width * height);
    }
};

class DerivedClass2 : public baseAbstractClass{
public:
    int getArea() { //the derived class implements the getArea function by itself, 
                        //which returns something else that what the first derived class has implemented the function for
        return (width * height) / 2;
    }
};



//entry point of the c++ program, executing this cpp file will run the following code.

int main()
{
    /*
    first part of the tutorial, general class creations and accessing basic members are discussed.
    */
    Box Box1;  //init the boxtype class, this is just like double length but instead its Box Box1
    Box Box2;
    double volume = 0.0; //you will store the volume value here, unlike python, you CANNOT instantenously create vars to store data in,
                         //they have to be specifically created

    //access members of the Box type objects by using periods
    Box1.height =5.0;
    Box1.width= 6.0;
    Box1.length = 7.0;

    Box2.height = 10;
    Box2.width = 12;
    Box2.length = 15;

    cout << "Hello World!\n";
    cout << "no endl\n" <<endl;
    cout << "endl !\n" << endl;

    //do some calculations with the objects and its members
    volume = Box1.height * Box1.length * Box1.width; //this changed the volume variable 
    cout << "box1 vol is " << volume << endl;

    volume = Box2.height * Box2.length * Box2.width; //this changed the volume again 
    cout << "box2 vol is " << volume << endl;

    /*
    second part of the tutorial, class derivations and how to access a little bit more advaned members are discussed here.
    */

    Rectangle rectangle1;

    rectangle1.setWidth(5);  //a void function is called, see that no equations are present, because there is no result returned.
    rectangle1.setHeight(7); //similar function is called

    int area = rectangle1.getArea(); //you can equate the function to a variable, because it returns 
    cout << "the area of the rectangle is: " << area << endl;
    cout << "the area of the rectangle is: " << rectangle1.getArea() << endl;

    /*
    third part of the tutorial, function and operator overloading are discussed.
    */

    printVariousThings printer; //create a printer object and access its members in the following lines

    printer.printInt(5);
    printer.printFloat(3.0);
    printer.printChar('c');
    printer.printString("this is a c string");


    /*
    
    fourth part, data abstraction, here the difference between public and private members will be explained
    */
    abstractionLevels a;
    a.addNumbers(10);
    a.addNumbers(20);
    a.addNumbers(30);
    cout << "Total " << a.getTotal() << endl;

    /*
    fifth part, abstract classes, here we will see how implementation is stripped down from classes
    */

    DerivedClass1 derived1; //instantiate the object
    DerivedClass2 derived2; //same

    //since the derived class has inherited all the public members and functions, we can reach setHeight and setWidth
    
    //this is a rectangle
    derived1.setHeight(5);
    derived1.setWidth(10);


    //this is a triangle
    derived2.setHeight(7);
    derived2.setWidth(10);

    int rectangle_area =derived1.getArea();
    int triangle_area = derived2.getArea();

    cout << "Total Rectangle area: " << rectangle_area << endl;
    cout << "Total Triangle area: " << triangle_area<< endl;

    return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
