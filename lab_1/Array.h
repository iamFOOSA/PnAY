#ifndef LAB_1_ARRAY_H
#define LAB_1_ARRAY_H
#include <iostream>

class Array
        {
    int rows;
    int cols;
    double** data;

public:
    Array(int r, int c);
    Array(const Array& other);
    ~Array();

    void input();
    void display() const ;

    static Array add(const Array& a, const Array& b);
    static Array multiply(const Array& a, const Array& b);
};

#endif