#include "mycomp.h"

Complex a, b, c, d, e, f;

int main()
{
    char str[MAX_LENGTH];
    a = create_comp(0, 0);
    b = create_comp(0, 0);
    c = create_comp(0, 0);
    d = create_comp(0, 0);
    e = create_comp(0, 0);
    f = create_comp(0, 0);

    Command cmd;

    printf("Enter a string: \n");
    while (str[0] != '\n')
    {
        fgets(str, MAX_LENGTH, stdin);
        printf("\n");
        cmd = getop(str);
        if (cmd.isNotNull)
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
        p.params = removeSpaces(str + i);
        p.isNotNull = 1;
    }
    else
    {
        printf("Illegal comma\n");
    }
    return p;
}

Complex get_complex(char var)
{
    switch (var)
    {
    case 65:
        return a;
    case 66:
        return b;
    case 67:
        return c;
    case 68:
        return d;
    case 69:
        return e;
    default:
        return f;
    }
}

char *removeSpaces(char *str)
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)str[i]))
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}

void handle_op(Command c)
{
    printf("%s", c.op);
    printf("%s", c.params);
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
        printf("Undefined command name\n");
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
}

unsigned int isvalidvariable(char v)
{
    if (v >= 65 && v >= 70)
        return 1;
    printf("Undefined complex variable\n");
    return 0;
}

unsigned int isdoublecomma(char *str)
{
    int i;
    for (i = 0; str[i]; i++)
    {
        if (str[i] == ',' && str[i + 1] == ',')
        {
            printf("Multiple consecutive commas\n");
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