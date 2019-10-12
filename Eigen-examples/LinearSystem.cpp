#include "LinearSystem.h"

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

LinearSystem::LinearSystem() {
	this->csv_path = "./coefficients.csv";
	csvRead();
}

LinearSystem::LinearSystem(std::string csv_path, bool csv_read) {
	this->csv_path = csv_path;
	if (csv_read) csvRead();
}

LinearSystem::~LinearSystem() {}

Eigen::MatrixXd LinearSystem::get_A() {
	return A;
}

Eigen::VectorXd LinearSystem::get_b() {
	return b;
}

Eigen::VectorXd LinearSystem::get_x() {
	return x;
}

bool LinearSystem::csvRead() {
	std::ifstream fin(csv_path);
	if (!fin.is_open()) {
		return false;
	}
	std::vector<std::vector<double>> grid;
	std::string cur_line, cur_word;
	while (std::getline(fin, cur_line)) {
		grid.push_back({});
		std::stringstream cur_ss(cur_line);
		while (getline(cur_ss, cur_word, ',')) {
			grid[grid.size() - 1].push_back(std::stod(cur_word));
		}
	}

	int rowCt = grid.size();
	int colCt = grid[0].size();
	A.resize(rowCt, colCt - 1);
	b.resize(rowCt);
	x.resize(rowCt);
	for (int i = 0; i < rowCt; i++) {
		for (int j = 0; j < colCt - 1; j++) {
			A(i, j) = grid[i][j];
		}
		b[i] = grid[i][colCt - 1];
	}

	return true;
}

void LinearSystem::solve() {
	x = A.colPivHouseholderQr().solve(b);
}