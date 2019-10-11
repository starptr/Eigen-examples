#include <iostream>
//for the Eigen library
#include <Eigen/Dense>
//for creating metrix
using Eigen::MatrixXd;

//function for calculating matrix + matrix
void addition(MatrixXd m, MatrixXd n)
{
    //show the metrix m + m (metrix addition)
    std::cout << "Here is a metrix m+n:\n" << m + n << std::endl << std::endl;
}

//function for calculating scalar times matrix
void scalarMultiplication(int scalar, MatrixXd m){
    //show the metrix 2.5 * m (metrix scalar multiplication)
    std::cout << "Scalar multiplication (scalar  * m): \n" << scalar * m << std::endl << std::endl;
}

//funtion for calculating matrix times matrix
void matrixMultiplication(MatrixXd m, MatrixXd n){
    //show the metrix m * m (2 metrixes multiplication)
    std::cout << "Matrix-matrix multiplication :\n" <<  m * n << std::endl <<std::endl;
}
