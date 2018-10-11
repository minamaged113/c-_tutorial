#include "main_usage.h"
#include <iostream>
#include <stdint.h>
#include <limits>

using namespace std;

void hello_world(void){
    /**
     * Prints "Hello, World!" to the screen
    */
    cout << "Hello, World!" << endl;
}

void get_text_print(void){
    /**
     * asks the user for a text input and prints it
    */
    string text;
    cout << "Enter your text: " << flush;
    cin >> text;
    cout << "You have entered: "<< text << endl;
}

void print_var_sizes(void){
    /**
     * prints all variable sizes in bytes and their
     * maximum and minimum values.
    */
    cout << "************************" << endl;
    cout << "bool:\t\t" << sizeof(bool) << " Bytes" << endl;
    cout << "char:\t\t" << sizeof(char) << " Bytes" << flush;
    cout << ", Max:\t" << UINT8_MAX << ", Min:\t" << "0" <<  endl;
    cout << "wchar_t:\t" << sizeof(wchar_t) << " Bytes" << flush;
    cout << ", Max:\t" << WCHAR_MAX << ", Min:\t" << WCHAR_MIN <<  endl;
    cout << "char16_t:\t" << "Not supported in g++" << flush;
    cout << ", Max:\t" << UINT16_MAX << ", Min:\t" << "0" <<  endl;
    cout << "char32_t:\t" <<"Not supported in g++"<< flush;
    cout << ", Max:\t" << UINT32_MAX << ", Min:\t" << "0" <<  endl;
    cout << "short:\t\t" << sizeof(short) << " Bytes" << flush;
    cout << ", Max:\t" << INT16_MAX << ", Min:\t" << INT16_MIN <<  endl;
    cout << "int:\t\t" << sizeof(int) << " Bytes" << flush;
    cout << "long:\t\t" << sizeof(long) << " Bytes" << flush;
    cout << "long long:\t" << sizeof(long long) << " Bytes" << flush;
    cout << "float:\t\t" << sizeof(float) << " Bytes" << flush;
    cout << "double:\t\t" << sizeof(double) << " Bytes" << flush;
    cout << "long double:\t" << sizeof(long double) << " Bytes" << flush;
    cout << "************************" << endl;
}