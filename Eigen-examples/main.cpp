#include <iostream>
#include <string>
#include <Eigen/Dense>

#include "examples.h"
#include "LinearSystem.h"
#include "matrixCal.cpp"

int main()
{
	/*
	All of these functions are declared and defined in examples.h and examples.cpp files.
	*/
	exInstance();
	exAddition();
	exScalarMultiply();
	exMultiply();
	exSolveLinearEq();
	exLinearLeastSquares();
	exCSVsolver();
	exLinearTransformation();
}
