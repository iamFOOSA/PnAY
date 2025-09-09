#include "Array.h"
#include <iomanip>
#include <format>
#include <stdexcept>

Array::Array(int r, int c) : rows(r), cols(c)
{
    data = new double*[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[cols]{0};
    }
}

Array::Array(const Array& other) : rows(other.rows), cols(other.cols)
{
    data = new double*[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}

Array::~Array()
{

    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

void Array::input()
{
    std::cout << "Введите элементы матрицы через пробел  (" << rows << "x" << cols << "):" << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> data[i][j];
        }
    }
}

void Array::display() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << std::format("{:8} ", data[i][j]);
        }
        std::cout << " " << std::endl;
    }
}

Array Array::add(const Array& a, const Array& b)
{
    if (a.rows != b.rows || a.cols != b.cols)
    {
        throw std::invalid_argument("данные матрицы не возможно сложить!");
    }
    Array result(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Array Array::multiply(const Array& a, const Array& b)
{
    if (a.cols != b.rows)
    {
        throw std::invalid_argument("Умножение невозможно: число столбцов первой != числу строк второй!");
    }
    Array result(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            for (int k = 0; k < a.cols; k++)
            {
                result.data[i][j] = a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}
