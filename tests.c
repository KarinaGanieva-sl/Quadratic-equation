#include <assert.h>
#include "tests.h"
#include "quadratic_equation.h"
#include <stdio.h>

void runAllTests()
{
    isCloseToZeroTest();
    solveLinearEquationTest();
    solveQuadraticEquationTest();
    solveTest();
    printf("All tests passed!\n");
}

void isCloseToZeroTest()
{
    assert(!isCloseToZero(3.3));
    assert(!isCloseToZero(-4.8));
    assert(isCloseToZero(0));
    assert(isCloseToZero(0.000000008));
    assert(!isCloseToZero(0.00001));
    assert(isCloseToZero(0.0));
}

void solveLinearEquationTest()
{
    assert(solveLinearEquation(2,4)[0] == 1);
    assert(solveLinearEquation(2,4)[1] == 2);
    assert(solveLinearEquation(2.5,10)[0] == 1);
    assert(solveLinearEquation(2.5,10)[1] == 4);
    assert(solveLinearEquation(2.5,10)[0] == 1);
    assert(solveLinearEquation(2.5,10)[1] == 4);
    assert(solveLinearEquation(3,0)[0] == 1);
    assert(solveLinearEquation(3,0)[1] == 0);
    assert(solveLinearEquation(0,0)[0] == 0);
    assert(solveLinearEquation(0,5)[0] == 0);
}

void solveQuadraticEquationTest()
{
    assert(solveQuadraticEquation(1, -2, 1)[0] == 1);
    assert(solveQuadraticEquation(1, -2, 1)[1] == 1);
    assert(solveQuadraticEquation(1, -6.6, 10.89)[0] == 1);
    assert(isCloseToZero(solveQuadraticEquation(1, -6.6, 10.89)[1] - 3.3));
    assert(solveQuadraticEquation(1, 1, -12)[0] == 2);
    assert(solveQuadraticEquation(1, 1, -12)[1] == 3);
    assert(solveQuadraticEquation(1, 1, -12)[2] == -4);
    assert(solveQuadraticEquation(1, -5.5, 4.84)[0] == 2);
    assert(isCloseToZero(solveQuadraticEquation(1, -5.5, 4.84)[1] - 4.4));
    assert(isCloseToZero(solveQuadraticEquation(1, -5.5, 4.84)[2] - 1.1));
    assert(solveQuadraticEquation(1, 3, 100)[0] == 0);
}

void solveTest()
{
    assert(solve(0, 2, 4)[0] == 1);
    assert(solve(0, 2, 4)[1] == 2);
    assert(solve(1, -2, 1)[0] == 1);
    assert(solve(1, -2, 1)[1] == 1);
    assert(solve(1, 1, -12)[0] == 2);
    assert(solve(1, 1, -12)[1] == 3);
    assert(solve(1, 1, -12)[2] == -4);
}
