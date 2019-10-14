#include "LinearTransformation.h"

LinearTransformation::LinearTransformation(int dim) {
	refresh_T(Eigen::MatrixXd::Identity(dim, dim));
}

LinearTransformation::LinearTransformation(Eigen::MatrixXd A) {
	refresh_T(A);
}

LinearTransformation::~LinearTransformation() {}

void LinearTransformation::refresh_T(Eigen::MatrixXd T) {
	this->T = T;
	T_decomp.compute(T);
	T_eigens.compute(T);
}

Eigen::MatrixXd LinearTransformation::getTransformation() {
	return T;
}

void LinearTransformation::setTransformation(Eigen::MatrixXd T) {
	refresh_T(T);
}

int LinearTransformation::getDimDomain() {
	return T.rows();
}

int LinearTransformation::getDimCodomain() {
	return T.cols();
}

int LinearTransformation::getNullity() {
	return T_decomp.dimensionOfKernel();
}

int LinearTransformation::getRank() {
	return T_decomp.rank();
}

Eigen::VectorXcd LinearTransformation::getEigenvals() {
	return T_eigens.eigenvalues();
}

bool LinearTransformation::isInvertible() {
	return T_decomp.isInvertible();
}

Eigen::MatrixXd LinearTransformation::getBasisOfKernel() {
	return T_decomp.kernel();
}

Eigen::MatrixXd LinearTransformation::getBasisOfImage() {
	return T_decomp.image(T);
}

Eigen::MatrixXcd LinearTransformation::getEigenvecs() {
	return T_eigens.eigenvectors();
}

LinearTransformation LinearTransformation::getInverse() {
	return LinearTransformation(T_decomp.inverse());
}

Eigen::MatrixXd LinearTransformation::transform(Eigen::MatrixXd x) {
	return T * x;
}