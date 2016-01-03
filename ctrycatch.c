#include "error_handler.h"

jmp_buf exception_env;
exception_types exception_type;
char *exception_message;