#include "LinearTransformationSquare.h"

LinearTransformationSquare::LinearTransformationSquare(int dim) : LinearTransformation(dim) {
	refresh_T(Eigen::MatrixXd::Identity(dim, dim));
}

LinearTransformationSquare::LinearTransformationSquare(Eigen::MatrixXd A) : LinearTransformation(A) {
	refresh_T(A);
}

LinearTransformationSquare::~LinearTransformationSquare() {}

void LinearTransformationSquare::refresh_T(Eigen::MatrixXd T) {
	this->T = T;
	T_decomp.compute(T);
	T_eigens.compute(T);
}

Eigen::VectorXcd LinearTransformationSquare::getEigenvals() {
	return T_eigens.eigenvalues();
}

Eigen::MatrixXcd LinearTransformationSquare::getEigenvecs() {
	return T_eigens.eigenvectors();
}