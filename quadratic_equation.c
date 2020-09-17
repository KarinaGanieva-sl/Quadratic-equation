#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadratic_equation.h"

int isNull(double x)
{
     if(fabs(x - 0.0) < EPS)
         return 1;
     return 0;
}

void getCoefficient(char message[], double *coef)
{
    printf("%s", message);
    if(scanf("%lf", coef))
        return;
    printf(FAILURE_MESSAGE);
    exit(EXIT_FAILURE);
}

double* solveQuadraticEquation(double a, double b, double c)
{
    double disc = b * b - 4 * a * c;
    if(disc < 0 && !isNull(disc))
    {
        printf(EMPTY_SET_ANSWER);
        static double ans[1] = {0};
        return ans;
    }
    if(disc > 0 && !isNull(disc))
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
    if(isNull(b))
    {
        if(isNull(c))
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
    if(isNull(a))
        return solveLinearEquation(b, c);
    else
        return solveQuadraticEquation(a, b, c);
}

void printAnswer(double* ans)
{
    printf("Answer: ");
    if(ans[0] == 1)
        printf("x = %lf", ans[1]);
    else
        printf("x1 = %lf, x2 = %lf", ans[1], ans[2]);
}
