#include <iostream>
#include <fstream>
#include <vector>
#include "matrix.hpp"

template <typename T>
class Matrix {

public:
    Matrix(std::size_t N) {
        data.resize(N, std::vector<T>(N, 0));
    }
    Matrix(std::vector<std::vector<T> nums) : data(nums) {}
    Matrix<T> operator+(const Matrix<T> &rhs) const {
        std::size_t N = data.size();
        Matrix<T> result(N);

        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < N; ++j) {
                result.data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T> &rhs) const {
        std::size_t N = data.size();
        Matrix<T> result(N);

        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < N; ++j) {
                result.data[i][j] = 0;
                for (std::size_t k = 0; k < N; ++k) {
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
                }
            }
        }
    return result;
    }

    void set_value(std::size_t i, std::size_t j, T n) {
        data[i][j] = n;
    }
    T get_value(std::size_t i, std::size_t)

int main(int argc, char *argv[]) {
    if (argc !=2) {
        std::cerr <<"Usage" <<argv[0] << "<matrix_file>\n";
        return 1;
    }
    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Failure to open file" << argv[1] << "\n";
        return 1;
    }
    std::size_t N;
    int type_flag;
    infile >> N >> type_flag;

    if(type_flag == 0) {
        std::vector<std::vector<int>> dataA, dataB;
        load_matrix<int>(infile, N, dataA);
        load_matrix<int>(infile, N, dataB);
        operations(dataA, dataB, N);
    }  else if (type_flag == 0) {
        std::vector<std::vector<double>> dataA, dataB;
        load_matrix<double>(infile, N, dataA);
        load_matrix<double>(infile, N, dataB);
        operations(dataA, dataB, N);
    }  else {
        std::cerr << "Invalid Type, Only 0 and 1 \n";
        return 1;
    }
}
