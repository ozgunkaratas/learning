/*
    to call the MathLibrary funcs in your source code, the proj must include the MathLibrary.h
    for third party libraries, copy the header file in your dir where the entry point is.
    for libs that you develop yourself, set the Additional Include Directories path.

    right cl MathClient > Properties > sl all config > config prop > c++ general > 

    if client proj is in a separate solution from the Dll
    ..\..\MathLibrary\MathLibrary

    if they are in the same solution
    ..\MathLibrary


*/



/*
    you have to specify that your project has a dependency on the MathLibrary.lib
    you have to inform the linker how to find the MathLibrary.lib file.
*/

/*
    you can set the Additional Dependencies property to tell the build system that the proj
    depends on MathLibrary.lib
    you can set an Additional Library Directories path in your proj to include the path to the library when you link.
    right cl MathClient > Properties > Config > All Config > Linker > Input > Additional Dependencies > Edit > MathLibrary.lib


    right cl MathClient > Prop > Linker > General > Additional Library Directories > add MathLibrary dir with %(IntDir)
    default, the .lib file is found in the debug, folder, the directory must point to this path.

*/

/*
    add a Post-Build Event to the proejct, this command copies the DLL to your build output directory.
    the command copies the DLL only if its missing or has changed.
    config > build events > post-build event > command line > copy the following ctrl c + v
    xcopy /y /d "..\..\MathLibrary\$(IntDir)MathLibrary.dll" "$(OutDir)"




*/

#include <iostream>
#include "MathLibrary.h" //this is made callable by the changes we applied discussed above.

int main()
{
    // Initialize a Fibonacci relation sequence.
    fibonacci_init(1, 1);
    // Write out the sequence values until overflow.
    do {
        std::cout << fibonacci_index() << ": " << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    // Report count of values written before overflow.
    std::cout << fibonacci_index() + 1 << " Fibonacci sequence values fit in an " << "unsigned 64-bit integer." << std::endl;
}