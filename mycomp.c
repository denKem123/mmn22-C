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
    while (strcmp(fgets(str, MAX_LENGTH, stdin), STOP_COMMAND))
    {
    }
    printf("%s", str);
}