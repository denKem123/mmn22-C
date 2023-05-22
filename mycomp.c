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

    printf("Enter a string: ");
    /*  do
     {*/
    gets(str);
    printf("%s", getop(*str));
    printf("%s", str);
    /* } while ();*/
    return 0;
}

char *getop(char *str)
{
    char *res;
    int i;
    for (i = 0; str[i] && str[i] != ' '; i++)
        ;
    strncpy(res, str, i);
    str = str + i;
    return res;
}