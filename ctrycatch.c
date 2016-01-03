#include "ctrycatch.h"

// Global variables to store exception details
jmp_buf CTRYCATCH_NAME(exception_env);
CTRYCATCH_NAME(exception_types) CTRYCATCH_NAME(exception_type);
char *CTRYCATCH_NAME(exception_message);
