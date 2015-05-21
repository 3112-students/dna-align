#pragma once
#include <string>
using namespace std;

class Matrix {
protected:
    int weight(int i, int j, string DNA1, string DNA2);
public:
    virtual void print() = 0;
    virtual void into_file(string file_name) = 0;
};