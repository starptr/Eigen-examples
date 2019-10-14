#ifndef LINEAR_TRANSFORMATION_SQUARE
#define LINEAR_TRANSFORMATION_SQUARE

#include "LinearTransformation.h"
class LinearTransformationSquare :
	public LinearTransformation
{
protected:
	Eigen::EigenSolver<Eigen::MatrixXd> T_eigens;

	virtual void refresh_T(Eigen::MatrixXd T);
public:
	//dim is the dimension of the square identity transformation
	LinearTransformationSquare(int dim);
	//A is the transformation matrix
	LinearTransformationSquare(Eigen::MatrixXd A);
	~LinearTransformationSquare();

	//Returns a complex column vector containing eigenvalues, repeated by algebraic multiplicity
	Eigen::VectorXcd getEigenvals();
	//Returns a matrix whose columns are the complex eigenvectors with corresponding eigenvalues
	Eigen::MatrixXcd getEigenvecs();
};


#endif // !LINEAR_TRANSFORMATION_SQUARE
