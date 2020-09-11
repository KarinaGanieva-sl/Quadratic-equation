#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static const char FAILURE_MESSAGE[] = "failed to read!";
static const char EMPTY_SET_ANSWER[] = "Answer: empty set";
static const char R_ANSWER[] = "Answer: R";

/**
 * This method is used to get coefficients from user.
 * @param message This is message for user
 * @param coef This is received coefficient
 */
void getCoefficient(char message[], double *coef)
{
    printf("%s", message);
    if(scanf("%lf", coef))
        return;
    printf(FAILURE_MESSAGE);
    exit(EXIT_FAILURE);
}

/**
 * This method is used to solve quadratic equation
 * @param a coefficient of x^2
 * @param b coefficient of x
 * @param c constant coefficient
 * @return double* This returns the answer
 */
double* solveQuadraticEquation(double a, double b, double c)
{
    double disc = b * b - 4 * a * c;
    if(disc < 0)
    {
        printf(EMPTY_SET_ANSWER);
        exit(EXIT_SUCCESS);
    }
    if(disc > 0)
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

/**
 * This method is used to solve linear equation
 * @param b coefficient of x
 * @param c constant coefficient
 * @return double* This returns the answer
 */
double* solveLinearEquation(double b, double c)
{
    if(b == 0.0)
    {
        if(c == 0.0)
            printf(R_ANSWER);
        else
            printf(EMPTY_SET_ANSWER);
        exit(EXIT_SUCCESS);
    }
    static double ans[2];
    ans[0] = 1;
    ans[1] = c / b;
    return ans;
}

/**
 * This method is used to solve equation
 * @param a coefficient of x^2
 * @param b coefficient of x
 * @param c constant coefficient
 * @return double* This returns the answer
 */
double* solve(double a, double b, double c)
{
    if(a == 0.0)
        return solveLinearEquation(b, c);
    else
        return solveQuadraticEquation(a, b, c);
}

/**
 * This method is used to print the answer.
 * @param ans the answer
 */
void printAnswer(double* ans)
{
    printf("Answer: ");
    if(ans[0] == 1)
        printf("x = %lf", ans[1]);
    else
        printf("x1 = %lf, x2 = %lf", ans[1], ans[2]);
}

int main()
{
    double a, b, c;
    getCoefficient("enter a:", &a);
    getCoefficient("enter b:", &b);
    getCoefficient("enter c:", &c);
    printf("coefficients: a = %f, b = %f, c = %f\n", a, b, c);
    double *ans = solve(a, b, c);
    printAnswer(ans);
    return 0;
}
