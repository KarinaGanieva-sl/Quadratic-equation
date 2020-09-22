#include "tests.h"
#include "quadratic_equation.h"
#include <stdio.h>

int main()
{
    runAllTests();
    double a = 0, b = 0, c = 0;
    getCoefficient("enter a:", &a);
    getCoefficient("enter b:", &b);
    getCoefficient("enter c:", &c);
    printf("coefficients: a = %f, b = %f, c = %f\n", a, b, c);
    double *ans = solve(a, b, c);
    printAnswer(ans);
    return 0;
}

