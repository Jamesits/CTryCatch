/*
 This file is a part of CTryCatch library ( https://github.com/Jamesits/CTryCatch ).
 
 The MIT License (MIT)
 
 Copyright (c) 2016 James Swineson
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <stdio.h>
#include "../../../ctrycatch.h"

void throwArgumentException() {
    puts("Function reached.");
    throw(ArgumentException, "Ooh! Some ArgumentException was thrown. ");
}

int main() {
    
    puts("Test1: try/catch/finally, function, with message");
    try {
        throwArgumentException();
    } catch(ArgumentException) {
        puts("ArgumentException block reached");
        if (__ctrycatch_exception_message_exists) printf("message: %s\n", __ctrycatch_exception_message);
    } finally {
        puts("finally block reached");
    }
    
    puts("\nTest2: try/catch, default catch block, without message");
    try {
        throw(InvalidPrinterException);
    } catch(ArgumentException) {
        puts("ArgumentException block reached");
        if (__ctrycatch_exception_message_exists) printf("message: %s\n", __ctrycatch_exception_message);
    } catch() {
        puts("default block reached");
        if (__ctrycatch_exception_message_exists) printf("message: %s\n", __ctrycatch_exception_message);
    }
    
    return 0;
}