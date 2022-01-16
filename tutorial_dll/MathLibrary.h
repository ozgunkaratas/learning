// MathLibrary.h - Contains declarations of math functions
#pragma once



/*extern: 
    tells the compiler that the variable or function which it modifies is defined in another translation unit.
    it specifies that the symbol has external linkage.

*/

/*ifdef as seen below:
    the new project template for a DLL project adds <projectname>_exports to the defined preprocessor macros.
    here, MSVC defines the MATLIBRARY_EXPORTS when the MathlIbrary DLL project is built.
    the modifiers seen in the preproc macros tell the compiler and the linker to export a function or a var
    from the DLL for use by other apps.
    more info under dllexport, dllimport
*/


/*
    to add an IMPLEMENTATION of the DLL (main, impl is where action occurs) 
    goto src >add>new item>create a .cpp file w the same name
    impls must always be cpp.
    impls must be used by a client app, in which the client app possesses the entry point to the program.

*/

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif



// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
extern "C" MATHLIBRARY_API void fibonacci_init(
    const unsigned long long a, const unsigned long long b);

// Produce the next value in the sequence.
// Returns true on success and updates current value and index;
// false on overflow, leaves current value and index unchanged.
extern "C" MATHLIBRARY_API bool fibonacci_next();

// Get the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned fibonacci_index();