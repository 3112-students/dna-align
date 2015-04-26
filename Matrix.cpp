#include "Matrix.h"

int Matrix::weight(int i, int j, string DNA1, string DNA2) {
        if (DNA1[i-1] == DNA2[j-1]) {
                return 1;
        } else {
                return 0;
        }
}
//virtual void Matrix::print() = 0;
//virtual void Matrix::into_file(string file_name) = 0;