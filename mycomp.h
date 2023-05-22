#include <string.h>

#define MAX_LENGTH 80
#define STOP_COMMAND "stop"


typedef struct
{
    char* result;
    char* nextPartitions;
} Partition;

Partition getop(char* str);
void read_comp_op(char* str);
void print_comp_op(char* str);
void add_comp_op(char* str);
void sub_comp_op(char* str);
void mult_comp_real_op(char* str);
void mult_comp_img_op(char* str);
void mult_comp_comp_op(char* str);
void abs_comp_op(char* str);