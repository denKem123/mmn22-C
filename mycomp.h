#define MAX_LENGTH 80
#define STOP_COMMAND "stop"

typedef struct
{
    char *type;
} Param;

typedef struct
{
    char *key;
    void (*operation)(, ...);
    Param *params;
} Action;