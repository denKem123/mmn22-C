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
    fgets(str,MAX_LENGTH, stdin);
    Partition p =  getop(str);
    printf("%s",p.result);
    printf("%s", p.updateStr);
    /* } while ();*/
    return 0;
}

Partition getop(char *str)
{
    Partition p;
    int i;
    for (i = 0; str[i] && str[i] != ' '; i++);
    char* op = malloc((i+1) * sizeof(char));
    strncpy(op, str, i);
    p.result = op;
    p.updateStr = str+i;
    return p;
}