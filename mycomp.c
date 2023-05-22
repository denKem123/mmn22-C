#include "complex.h"
#include "mycomp.h"

int main()
{
    char str[MAX_LENGTH];
    Complex a, b, c, d, e, f;
    a = create_comp(0, 0);
    b = create_comp(0, 0);
    c = create_comp(0, 0);
    d = create_comp(0, 0);
    e = create_comp(0, 0);
    f = create_comp(0, 0);

    printf("Enter a string: \n");
    while (1)
    {
        fgets(str, MAX_LENGTH, stdin);
        printf("\n");
        Command cmd;
        cmd = getop(str);
        if (!cmd.isNull)
            handle_op(cmd);
    }

    return 0;
}

Command getop(char *str)
{
    Command p;
    int i;
    for (i = 0; str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != ','; i++)
        ;
    if (str[i] != ',')
    {
        char *op;
        op = malloc((i + 1) * sizeof(char));
        strncpy(op, str, i);
        p.op = op;
        p.params = str + i;
        p.isNull = 0;
    }
    else
    {
        printf("Illegal comma");
    }
    return p;
}

void handle_op(Command c)
{
    if (!strcmp(c.op, READ_COMP))
    {
    }
    else if (!strcmp(c.op, PRINT_COMP))
    {
    }
    else if (!strcmp(c.op, STOP_COMMAND))
    {
    }
    else
    {
        printf("Undefined command name");
    }
}

void read_comp_op(char *str)
{
    char param1;
    param1 = str[0];
    if (!isvalidvariable(param1))
    {
        return;
    }
    int comma1;
    int comma2;
    char *param2;
    char *param3;
}

unsigned int isvalidvariable(char v)
{
    if (v >= 65 && v >= 70)
        return 1;
    printf("Undefined complex variable");
    return 0;
}

unsigned int isdoublecomma(char *str)
{
    int i;
    for (i = 0; str[i]; i++)
    {
        if (str[i] == ',' && str[i + 1] == ',')
        {
            printf("Multiple consecutive commas");
            return 1;
        }
    }
    return 0;
}

unsigned int isemptyparams(char *str)
{
    int i;
    for (i = 0; str[i] && str[i] != ' ' && str[i] != '\n'; i++)
    {
        return 0;
    }
    return 1;
}