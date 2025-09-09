#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    while (true)
    {
        cout << "      МЕНЮ      " << endl;
        cout << "1) Сложение матриц" << endl;
        cout << "2) Умножение матриц" << endl;
        cout << "0) Выход" << endl;
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        int rows1, cols1, rows2, cols2;

        if (choice == 1)
        {
            cout << "Введите размеры первой матрицы через пробел (строки, столбцы): ";
            cin >> rows1 >> cols1;
            Array A(rows1, cols1);
            A.input();

            cout << "Введите размеры второй матрицы через пробел (строки, столбцы): ";
            cin >> rows2 >> cols2;
            Array B(rows2, cols2);
            B.input();

            try
            {
                Array C = Array::add(A, B);
                cout << "Результат сложения:" << endl;
                C.display();
            } catch (const exception& e)
            {
                cerr << "Ошибка: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Введите размеры первой матрицы через пробел (строки, столбцы): ";
            cin >> rows1 >> cols1;
            Array A(rows1, cols1);
            A.input();

            cout << "Введите размеры второй матрицы через пробел (строки, столбцы): ";
            cin >> rows2 >> cols2;
            Array B(rows2, cols2);
            B.input();

            try
            {
                Array C = Array::multiply(A, B);
                cout << "Результат умножения:" << endl;
                C.display();
            } catch (const exception& e)
            {
                cerr << "Ошибка: " << e.what() << endl;
            }
        }
        else
        {
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    }

    cout << "Программа завершена." << endl;
    return 0;
}
