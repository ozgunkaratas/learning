#include <iostream>
#include <fstream>
#include <ostream>



/*
void fileOpenerAppend(const char* filename, ios::app mode);
void fileOpenerAtEnd(const char* filename, ios::ate mode);
void fileOpenerRead(const char* filename, ios::in mode);
void fileOpenerWrite(const char* filename, ios::out mode);
void fileOpenerTrunc(const char* filename, ios::trunc mode);
*/
 

int main()
{
    std::cout << "Hello World!\n";

    char write_buffer[100];


    //open file
    std::ofstream outfile; //create file object in write mode
    outfile.open("dummyfile.dat"); //by using the open method of the object, we opened a new file

    std::cout << "heads up: the following will be written to the file\n";
    std::cout << "Enter name: ";
    std::cin.getline(write_buffer, 100); //use the getline method of cin to get up to 100 chars of whats written on console

    //use write_buffer to write to the dummyfile.dat with the file object "outfile"
    outfile << write_buffer << std::endl;  //when you are writing to a file, the syntax is exactly the same with writing to the console with cout


    //get some more info from the console, no cin methods are needed 
    //because we will get everything written on the console without char limits
    std::cout << "enter your age: ";
    std:: cin >> write_buffer;

    outfile << write_buffer << std::endl;

    std::cout << "writing process complete, closing the dummyfile.dat file... \n";
    outfile.close();  //use close method to be done with the file.


    //open a file in read mode
    std::ifstream readFile;
    readFile.open("dummyFile.dat"); //use open method of readfile object to read the file without altering anything
    std::cout << "by using ifstream, dummyFile is being read to you...\n";

    readFile >> write_buffer; //when you are reading from a file, the syntax is exactly the same with writing to the console with cin
                              //this assigns the contents of the file to the write_buffer, which can be human readable later on
                              //this reads the first line
                              //reading each of the lines must be manually iterated

    std::cout << write_buffer << std::endl; //display the first line


    readFile >> write_buffer;   //read the next line
    std::cout << write_buffer << std::endl; //diqsplay the next line


    readFile.close();  //close dummyFile.dat and be done with it



}

