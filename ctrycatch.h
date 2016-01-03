#pragma once
#ifndef ctrycatch_h
#define ctrycatch_h

#include <setjmp.h>
#include <stdbool.h>

// Some macro magic
#ifdef CAT
#undef CAT
#endif
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#ifdef PRIMITIVE_CAT
#undef PRIMITIVE_CAT
#endif
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#ifdef CTRYCATCH_NAME
#undef CTRYCATCH_NAME
#endif
#define CTRYCATCH_NAME(X) CAT(__ctrycatch_, X)

// New block arguments
#ifdef try
#undef try
#endif
#define try \
    if(!(CTRYCATCH_NAME(exception_type) = setjmp(CTRYCATCH_NAME(exception_env))))

#ifdef catch
#undef catch
#endif
#define catch(X) \
    else if((X +0) == 0 || CTRYCATCH_NAME(exception_type) == (X +0))

#ifdef finally
#undef finally
#endif
#define finally

#ifdef throw
#undef throw
#endif
#define throw(X,...) \
    CTRYCATCH_NAME(exception_message) = (__VA_ARGS__  +0), longjmp(CTRYCATCH_NAME(exception_env), (X))

// Exception type
typedef int CTRYCATCH_NAME(exception_types);

// Global variables to store exception details
extern jmp_buf CTRYCATCH_NAME(exception_env);
extern CTRYCATCH_NAME(exception_types) CTRYCATCH_NAME(exception_type);
extern char *CTRYCATCH_NAME(exception_message);

// Helper functions
#ifdef __ctrycatch_exception_message_exists
#undef __ctrycatch_exception_message_exists
#endif
#define __ctrycatch_exception_message_exists (bool)CTRYCATCH_NAME(exception_message)

// Exception types
#ifdef Exception
#undef Exception
#endif

enum exception_type {
    Exception, // Caution: 0 **IS** defined as "no error" to make it work. DO NOT modofy this line. 
#include "ctrycatch_custom_exceptions.h"
};

#define Exception 0

#endif /* ctrycatch_h */
