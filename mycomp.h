#include <string.h>

#define MAX_LENGTH 80
#define STOP_COMMAND "stop"


typedef struct
{
    char* result;
    char* updateStr;
} Partition;

Partition getop(char* str);