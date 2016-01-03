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