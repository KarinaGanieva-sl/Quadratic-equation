#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic_equation.h"

/**
 * This method is used to check if double-value is close to zero.
 * @param x double-value
 * @return int returns 1 if true, 0 if false.
 */
int isCloseToZero(double x)
{
     assert (isfinite(x));
     if(fabs(x - 0.0) < EPS)
         return 1;
     return 0;
}

void getCoefficient(char message[], double *coef)
{
    assert (message != NULL);
    assert (coef != NULL);
    printf("%s", message);
    if(scanf("%lf", coef) && isfinite(*coef))
        return;
    printf(FAILURE_MESSAGE);
    exit(EXIT_FAILURE);
}

double* solveQuadraticEquation(double a, double b, double c)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    double disc = getDiscriminant(a,b,c);
    if(!isfinite(disc))
    {
        printf(DISC_ERROR);
        static double ans[1] = {0};
        return ans;
    }
    if(disc < 0 && !isCloseToZero(disc))
    {
        printf(EMPTY_SET_ANSWER);
        static double ans[1] = {0};
        return ans;
    }
    if(disc > 0 && !isCloseToZero(disc))
    {
        static double ans[3];
        ans[0] = 2;
        ans[1] = (-b + sqrt(disc)) / (2 * a);
        ans[2] = (-b - sqrt(disc)) / (2 * a);
        return ans;
    }
    static double ans[2];
    ans[0] = 1;
    ans[1] = -b / (2 * a);
    return ans;
}

double* solveLinearEquation(double b, double c)
{
    assert (isfinite(b));
    assert (isfinite(c));
    if(isCloseToZero(b))
    {
        if(isCloseToZero(c))
            printf(R_ANSWER);
        else
            printf(EMPTY_SET_ANSWER);
        static double ans[1] = {0};
        return ans;
    }
    static double ans[2];
    ans[0] = 1;
    ans[1] = c / b;
    return ans;
}

double* solve(double a, double b, double c)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    if(isCloseToZero(a))
        return solveLinearEquation(b, c);
    else
        return solveQuadraticEquation(a, b, c);
}

void printAnswer(double* ans)
{
    assert (ans != NULL);
    if(ans[0] == 0)
        return;
    if(ans[0] == 1)
        printf("Answer: x = %lf", ans[1]);
    else
        printf("Answer: x1 = %lf, x2 = %lf", ans[1], ans[2]);
}

double getDiscriminant(double a, double b, double c) {
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    return b * b - 4 * a * c;
}
