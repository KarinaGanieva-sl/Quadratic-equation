//
// Created by user on 16.09.2020.
//

#ifndef QUADRATIC_EQUATION_QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_QUADRATIC_EQUATION_H

static const char FAILURE_MESSAGE[] = "failed to read!\n";
static const char EMPTY_SET_ANSWER[] = "Answer: empty set\n";
static const char R_ANSWER[] = "Answer: R\n";
static const double EPS = 0.00001;

/**
 * This method is used to check if double-value is close to zero.
 * @param x double-value
 * @return int returns 1 if true, 0 if false.
 */
int isNull(double x);

/**
 * This method is used to get coefficients from user.
 * @param message This is message for user
 * @param coef This is received coefficient
 */
void getCoefficient(char message[], double *coef);

/**
 * This method is used to solve quadratic equation
 * @param a coefficient of x^2
 * @param b coefficient of x
 * @param c constant coefficient
 * @return double* This returns the answer
 */
double* solveQuadraticEquation(double a, double b, double c);

/**
 * This method is used to solve linear equation
 * @param b coefficient of x
 * @param c constant coefficient
 * @return double* This returns the answer
 */
double* solveLinearEquation(double b, double c);

/**
 * This method is used to solve equation
 * @param a coefficient of x^2
 * @param b coefficient of x
 * @param c constant coefficient
 * @return double* This returns the answer
 */
double* solve(double a, double b, double c);

/**
 * This method is used to print the answer.
 * @param ans the answer
 */
void printAnswer(double* ans);

#endif //QUADRATIC_EQUATION_QUADRATIC_EQUATION_H
