/*
                    signals are interrupts delivered to a process by the OPERATING SYSTEM which
                    can terminate a program prematurely. for example: ctrl+ c is an interrupt on the console
                    signals are defined under the header file <csignal>

*/

#include <iostream>
#include <csignal>
//Sleep isnt present in the standard library, 
//has to be manually added,
//preproc if to determine if windows or unix is being used
#ifdef _WIN32
#include <Windows.h> 
#else
#include <unistd.h>
#endif

using namespace std;

void signalReceiver(int received_signal) {
    cout << "Interrupt signal (" << received_signal<< ") received.\n";

    exit(received_signal);
}
int main()
{
    std::cout << "Hello World!\n";
    signal(SIGINT, signalReceiver); //tell the program that this signal is of interest and we intend to use it inside the program
    int i = 0;
    while (++i) {
        cout << "Going to sleep...." << endl;
        if (i == 3) {
            raise(SIGINT);
        }
        Sleep(1);
    }



}


