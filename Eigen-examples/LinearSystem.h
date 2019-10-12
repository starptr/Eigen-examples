#include <string>
#include <Eigen/Dense>

#ifndef LINEAR_SYSTEM
#define LINEAR_SYSTEM

class LinearSystem
{
	Eigen::MatrixXd A;
	Eigen::VectorXd b;
	Eigen::VectorXd x;

	/*
	Location of csv file. Must have rectangular dimensions.
	*/
	std::string csv_path;

public:
	LinearSystem();
	LinearSystem(std::string csv_path, bool csv_read);
	~LinearSystem();

	Eigen::MatrixXd get_A();
	Eigen::VectorXd get_b();
	Eigen::VectorXd get_x();

	bool csvRead();
	void solve();
};

#endif // LINEAR_SYSTEM
