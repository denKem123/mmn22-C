#include "complex.h"
#include <math.h>

/*
    create a new Complex struct
*/
Complex create_comp(double real, double img)
{
    Complex c;
    c.real = real;
    c.img = img;

    return c;
}

/*
    print complex number
*/
void print_comp(Complex comp)
{
    printf("%.2f %s (%.2f)i", comp.real, comp.img < 0 ? "-" : "+", comp.img < 0 ? comp.img * -1 : comp.img);
}

/*
    add two Complex numbers and return the result value
*/
Complex add_comp(Complex first, Complex second)
{
    Complex c;
    c.real = first.real + second.real;
    c.img = first.img + second.img;

    return c;
}

/*
    subtract second complex from the first - return the result value
*/
Complex sub_comp(Complex first, Complex second)
{
    Complex c;
    c.real = first.real - second.real;
    c.img = first.img - second.img;

    return c;
}

/*
    multiply real number with complex number -return result complex
*/
Complex mult_comp_real(double real, Complex comp)
{
    Complex c;
    c.real = real * comp.real;
    c.img = real * comp.img;

    return c;
}

/*
    multiply imaginary number with complex number - return result complex
*/
Complex mult_comp_img(double img, Complex comp)
{
    Complex c;
    c.real = img * comp.img * -1;
    c.img = img * comp.real;

    return c;
}

/*
    multiply tow complex numbers - return the result value
*/
Complex mult_comp_comp(Complex first, Complex second)
{
    Complex c;
    c.real = first.real * second.real - first.img * second.img;
    c.img = first.real * second.img + first.img * second.real;

    return c;
}

/*
    multiply tow complex numbers - return the result value
*/
double abs_comp(Complex comp)
{
    return sqrt(comp.img * comp.img + comp.real * comp.real);
}