# CTryCatch

A library which enables you to write try/catch statements in pure C. 

Notes: 

 * **Experimental project**. Updates may broke backward compatibility. Use with caution. 
 * Not sure if it is thread safety.

## Usage

To use CTryCatch, simply include its header: `#include "ctrycatch.h"`. 

Definitions: 

 * `try` starts a try block.
 * `catch(ExceptionType)` catches a specific error.
 * `catch()` catches any error; put it after other `catch`es if there are any. 
 * `finally` starts a finally block. 
 * `throw(ExceptionType)` throws an exception. 
 * `throw(ExceptionType, "message")` throws an exception with a message. 
 * `bool __ctrycatch_exception_message_exists;` is set to true if there is a message with exception. 
 * `char *__ctrycatch_exception_message` contains the message (if there is any) or NULL if not. 
 
Notes 

 * Inheritance is not implemented due to the limitations of C. 
 * The generic `catch()` should be put after other `catch`es if there are any. Otherwise more than one catch blocks may be executed. 
 * `catch()` is exactly the same to `catch(Exception)`.
 
## Add/Change Exception Types

Edit `ctrycatch_custom_exceptions.h`: 

```C
AccessViolationException,
AppDomainUnloadedException,
ApplicationException,
ArgumentException,
ArgumentNullException,
ArgumentOutOfRangeException,
ArithmeticException,
// ...
SomeCustomException,
AnotherCustomException,
```

## Example

[Here](https://github.com/Jamesits/CTryCatch/blob/master/tests/CTryCatchTest/CTryCatchTest/main.c) is an simple C program which demonstrates the usage of CTryCatch. 

### Comparison with C++ try/catch

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
	// error handling for default case
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
}
// C++ doesn't support finally
```

## Author

[James Swineson](https://swineson.me)

## Thanks

Exceptions list is from [.NET Exceptions (all of them)](https://mikevallotton.wordpress.com/2009/07/08/net-exceptions-all-of-them/).