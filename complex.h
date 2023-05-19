#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double real;
    double img;
} Complex;


Complex create_comp(double real, double img);
void print_comp(Complex comp);
Complex add_comp(Complex first, Complex second);
Complex sub_comp(Complex first, Complex second);
Complex mult_comp_real(double real, Complex comp);
Complex mult_comp_img(double img, Complex comp);
Complex mult_comp_comp(Complex first, Complex second);
double abs_comp(Complex comp);