#ifndef LINEAR_TRANSFORMATION
#define LINEAR_TRANSFORMATION

#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

class LinearTransformation
{
	Eigen::MatrixXd T;
	Eigen::FullPivLU<Eigen::MatrixXd> T_decomp;
	Eigen::EigenSolver<Eigen::MatrixXd> T_eigens;

	void refresh_T(Eigen::MatrixXd T);

public:
	//dim is the dimension of the square identity transformation
	LinearTransformation(int dim);
	//A is the transformation matrix
	LinearTransformation(Eigen::MatrixXd A);
	~LinearTransformation();

	//Returns T
	Eigen::MatrixXd getTransformation();
	//Assigns T and handles initial computations
	void setTransformation(Eigen::MatrixXd T);

	//Returns dimension of domain of T
	int getDimDomain();
	//Returns dimension of codomain of T
	int getDimCodomain();
	//Returns nullity (i.e. dimension of kernel) of T
	int getNullity();
	//Returns rank (i.e. dimension of image) of T
	int getRank();
	//Returns a complex column vector containing eigenvalues, repeated by algebraic multiplicity
	Eigen::VectorXcd getEigenvals();
	//Returns whether T has an inverse
	bool isInvertible();
	//Returns a matrix whose columns form a basis of the kernel of T
	Eigen::MatrixXd getBasisOfKernel();
	//Returns a matrix whose columns form a basis of the image of T
	Eigen::MatrixXd getBasisOfImage();
	//Returns a matrix whose columns are the complex eigenvectors with corresponding eigenvalues
	Eigen::MatrixXcd getEigenvecs();
	
	//Returns the inverse of T, if it exists
	LinearTransformation getInverse();
	//x is the input matrix to be transformed
	Eigen::MatrixXd transform(Eigen::MatrixXd x);
};

#endif // !LINEAR_TRANSFORMATION
