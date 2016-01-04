# CTryCatch

A library which enables you to write try/catch statements in pure C. 

Notes: 

 * Compatible with C99. Support of older C standards are not guaranteed.
 * **Experimental project**. Updates may broke backward compatibility. Use with caution. 
 * Not sure if it is thread safety. See: [issues/2](https://github.com/Jamesits/CTryCatch/issues/2)
 * WARNING: you might see a lot of messy errors if you break its grammer. See: [issues/3](https://github.com/Jamesits/CTryCatch/issues/3)

## Usage

To use CTryCatch, simply include its header in your program: `#include "ctrycatch.h"`. 

Definitions: 

 * `try` starts a try block.
 * `catch(ExceptionType)` catches a specific error.
 * `catch()` or `catch(Exception)` catches any error and executes the corresponding catch block; put it after other `catch`es if there are any. 
 * `finally` starts a finally block. 
 * `throw(ExceptionType)` throws an exception. 
 * `throw(ExceptionType, "message")` throws an exception with a message. 
 * `bool __ctrycatch_exception_message_exists;` is set to true if there is a message with exception. 
 * `char *__ctrycatch_exception_message` contains the message (if there is any) or NULL if not. 
 
Notes 

 * `ctrycatch.c` needs to be compiled and linked to your program. 
 * Full inheritance support is not implemented due to the limitations of C. However, any exception type is a "subclass" of `Exception`.
 * The generic `catch()` should be put after other `catch`es if there are any. Otherwise more than one catch blocks may be executed. 
 * `catch()` is exactly the same as `catch(Exception)`.
 * No good support for `throw`ing inside catch block or nested try/catch structure currently. *Help wanted.* See: [issues/1](https://github.com/Jamesits/CTryCatch/issues/1)
 * `__ctrycatch_exception_message` may bring memory leaks. See: [issues/4](https://github.com/Jamesits/CTryCatch/issues/4)
  
## Add/Change Exception Types

Edit `ctrycatch_exception_types.conf` and add/modify that list: 

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

## License

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