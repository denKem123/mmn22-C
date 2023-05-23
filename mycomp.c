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

    while (1)
    {
        printf("Enter a command: \n");
        if (fgets(str, MAX_LENGTH, stdin) != NULL)
        {
            Command cmd;
            cmd = getop(str);
            if (cmd.isNotNull && !handle_op(cmd))
                break;
        }
        else
        {
            printf("End of input!!");
            break;
        }
    }

    return 0;
}

Command getop(char *str)
{
    Command p;
    int i;
    for (i = 0; str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != DIVIDER; i++)
        ;
    if (str[i] != DIVIDER)
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

Complex *get_complex(char var)
{
    switch (var)
    {
    case 65:
        return &a;
    case 66:
        return &b;
    case 67:
        return &c;
    case 68:
        return &d;
    case 69:
        return &e;
    default:
        return &f;
    }
}

ComplexParams getcomplexvar(char *str, unsigned int isLast)
{
    ComplexParams cp;
    if (isvalidvariable(str[0]))
    {
        if (isLast && str[1] != DIVIDER)
        {
            cp.isNotNull = 1;
            cp.params = "";
            cp.var = get_complex(str[0]);
        }
        else if (!isLast && str[1] == DIVIDER)
        {
            cp.isNotNull = 1;
            cp.params = str + 2;
            cp.var = get_complex(str[0]);
        }
        else if (!isLast)
        {
            printf("Missing comma\n");
        }
        else
        {
            printf("Extraneous text after end of command \n");
        }
    }
    else
    {
        if (str[0] == '\0')
        {
            printf("Missing parameter\n");
        }
        else
        {
            printf("Undefined complex variable\n");
        }
    }
    return cp;
}

DoubleParams getdoubleparams(char *str, int isLast)
{
    DoubleParams dp;
    int i;
    for (i = 0; str[i] && str[i] != DIVIDER; i++)
        ;
    char *doubleStr;
    doubleStr = malloc((i + 1) * sizeof(char));
    strncpy(doubleStr, str, i);
    double number;
    number = atof(doubleStr);
    free(doubleStr);
    if (number != 0.0)
    {
        if (isLast && str[1] != DIVIDER)
        {
            dp.isNotNull = 1;
            dp.params = "";
            dp.num = number;
        }
        else if (!isLast && str[1] == DIVIDER)
        {
            dp.isNotNull = 1;
            dp.params = str + i;
            dp.num = number;
        }
        else if (!isLast)
        {
            printf("Missing comma\n");
        }
        else
        {
            printf("Extraneous text after end of command \n");
        }
    }
    else
    {
        if (str[0] == '\0')
        {
            printf("Missing parameter\n");
        }
        else
        {
            printf("Invalid parameter – not a number\n");
        }
    }

    return dp;
}

char *removeSpaces(char *str)
{
    int i, j;
    for (i = 0, j = 0; str[i]; i++)
    {
        if (!isspace((unsigned char)str[i]))
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}

unsigned int handle_op(Command c)
{
    if (!strcmp(c.op, READ_COMP))
    {
        read_comp_op(c.params);
    }
    else if (!strcmp(c.op, PRINT_COMP))
    {
        print_comp_op(c.params);
    }
    else if (!strcmp(c.op, STOP_COMMAND))
    {
        return 0;
    }
    else
    {
        printf("Undefined command name\n");
    }
    return 1;
}

void read_comp_op(char *str)
{
    ComplexParams cp;
    DoubleParams dpReal;
    DoubleParams dpImg;
    cp = getcomplexvar(str, 0);
    if (cp.isNotNull)
        dpReal = getdoubleparams(cp.params, 0);
    if (dpReal.isNotNull)
        dpImg = getdoubleparams(dpReal.params, 1);

    if (cp.isNotNull && dpReal.isNotNull && dpImg.isNotNull)
    {
        *cp.var = create_comp(dpReal.num, dpImg.num);
    }
}

void print_comp_op(char *str)
{
    ComplexParams cp;
    cp = getcomplexvar(str, 0);
    if (cp.isNotNull)
    {
        print_comp(*cp.var);
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
        if (str[i] == DIVIDER && str[i + 1] == DIVIDER)
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