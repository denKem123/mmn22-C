#include <string.h>

#define MAX_LENGTH 80
#define STOP_COMMAND "stop"


typedef struct
{
    char* result;
    char* nextPartitions;
} Partition;

Partition getop(char* str);
void read_comp(char* str);
void print_comp(char* str);
void add_comp(char* str);
void sub_comp(char* str);
void mult_comp_real(char* str);
void mult_comp_img(char* str);
void mult_comp_comp(char* str);
void abs_comp(char* str);