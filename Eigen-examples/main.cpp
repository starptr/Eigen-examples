#include <iostream>
#include <string>
#include <Eigen/Dense>

#include "examples.h"
#include "matrixCal.cpp"

int main()
{
	/*
	All of these functions are declared and defined in examples.h and examples.cpp files.
	*/
	
	//make a 2*2 matrix
	matrix2_2(1.0, 2.0, 2.5, 7.0);
	vector2(2.0,3.0)
	
	
        //creates metrixes m which has 2 rows and 2 columns
        MatrixXd m(2, 2);
        m << 1, 3,
            5, 7;

        MatrixXd n(2, 2);
        n << 1, 2,
             3, 4;
	
	//show the metrix m
        std::cout << "Here is a matrix m:\n" <<  m << std::endl <<std::endl;
	std::cout << "Here is a matrix n:\n" <<  n << std::endl <<std::endl;
	
	exInstance();
	exMultiply();
	
	//culculate matrix + matrix
	addition(m,n);
	//calculate scalar * matrix
	scalarMultiplication(2.5, m);
	//calculate matrix * matrix
	matrixMultiplication(m,m);
	
}
