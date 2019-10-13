#ifndef LINEAR_TRANSFORMATION
#define LINEAR_TRANSFORMATION

#include <Eigen/Dense>

class LinearTransformation
{
	Eigen::MatrixXd T;
public:
	LinearTransformation();
	~LinearTransformation();
};

#endif // !LINEAR_TRANSFORMATION
