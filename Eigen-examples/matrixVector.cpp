#include <iostream>
#include "Eigen/Dense"
using Eigen::MatrixXd;
using Eigen::VectorXd;

void matrix2_2(double a, double b, double c, double d){
    //creates a metrix which has 2 rows and 2 columns
    MatrixXd m1(2,2);
    //add the values in each elements
    m1(0,0) = a;
    m1(1,0) = b;
    m1(0,1) = c;
    m1(1,1) = d;
    std::cout << "Here is a matrix m:\n" <<  m1 << std::endl <<std::endl;
    
    //creats a metrix and puts the values in other way
    MatrixXd m2(2,2);
    m2 << a, b,
          c, d;
    std::cout <<"Used other way to write a matrix:\n"<< m2 << std::endl << std::endl;
}

void Vector2(double a, double b){
    //creates a vector which is 2 dimention
    VectorXd v(2);
    //put the values in the vector
    v(0) = a;
    v(1) = b;
    std::cout << "Here is the vector v:\n" << v << std::endl;
}
