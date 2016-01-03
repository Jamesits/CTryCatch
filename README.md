# CTryCatch

A library which enables you to write try/catch statements in pure C. 

Experimental project. Updates may broke forward compatibility. Use with caution. 

## Usage

To use CTryCatch, simply include its header: `#include "ctrycatch.h"`. 

## Differences from C++ try/catch

```C
// CTryCatch

try {
	// do something
	throw(ArgumentsException);
	// or
	throw(ArgumentsException, "description");
} catch(ArgumentsException) {
	// error handling
} catch() {
	// error handling
} finally {
	// cleanup
}
```

```C++
// C++

try {
	// do something
	throw(new ArgumentsException());
	// or
	throw(new ArgumentsException("description"));
} catch(ArgumentsException e) {
	// error handling
} catch {
	// error handling
} finally {
	// cleanup
}
```


## Example

Here is an simple C program which demonstrates the usage of CTryCatch. 

```C
#include <stdio.h>
#include "ctrycatch.h"

void throwArgumentsException(void) {
    printf("second\n");
    throw(ArgumentsException, "ArgumentsException");
}

int main() {

    puts("Test1: try/catch/finally, function, with message");
    try {
        throwArgumentsException();
    } catch(ArgumentsException) {
        printf("ArgumentsException\n");
        if (exception_message) printf("message: %s\n", exception_message);
    } finally {
        printf("finally\n");
    }
    
    puts("Test2: try/catch, default catch block, without message");
    try {
        throw(NullPointerException);
    } catch(ArgumentsException) {
        printf("ArgumentsException\n");
        if (exception_message) printf("message: %s\n", exception_message);
    } catch() {
        printf("default\n");
        if (exception_message) printf("message: %s\n", exception_message);
    }
    
    return 0;
}
```

## Author

[James Swineson](https://swineson.me)

## Thanks

Exceptions list is from [.NET Exceptions (all of them)](https://mikevallotton.wordpress.com/2009/07/08/net-exceptions-all-of-them/).