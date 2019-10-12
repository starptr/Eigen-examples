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
	
	exInstance();
	exAddition();
	exMultiply();
		
        //creates metrixes m which has 2 rows and 2 columns
        MatrixXd m(2, 2);
        m(0,0) = 1;
        m(1,0) = 3;
        m(0,1) = 5;
        m(1,1) = 7;

        MatrixXd n(2, 2);
        n << 1, 2,
             3, 4;
	
	//creates vector v which is 2 dimensions
        VectorXd v(2);
        v(0) = 2.5;
        v(1) = 5;
	
	//show the metrix m
        std::cout << "Here is a matrix m:\n" <<  m << std::endl <<std::endl;
	std::cout << "Here is a matrix n:\n" <<  n << std::endl <<std::endl;
	
	//calculate scalar * matrix
	scalarMultiplication(2.5, m);
	//calculate matrix * matrix
	matrixMultiplication(m,m);
	
	//show the vector v
	std::cout << "Here is the vector v:\n" << v << std::endl << std::endl;
	
        //solve the system of the linear equation
        linearEqua(m, v);
	
}
