#include <iostream>
#include <cmath>
using namespace std;

const double epsilon = 1e-6;

void method1();
void method2();
void method3();

int main()
{
    setlocale(LC_ALL, "ru");

    int methodNumber;

    cout << "Выберите метод: " << endl;
    cout << "1. Метод половинного деления: " << endl;
    cout << "2. Метод  Ньютона: " << endl;
    cout << "3. Метод итераций: " << endl;

    cin >> methodNumber;

    switch (methodNumber)
        case 1: {

        method1();
        break;

        case 2:

            method2();
            break;

        case 3:

            method3();
            break;

        default:
            break;
         }
}

//Метод половинного деления

void method1() {
    double a, b, x;
    double fb, fc;
    cout << "Введите а: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    while (b - a > epsilon)
    {
        x = (a + b) / 2;
        fb = exp(b) - exp(-b) - 2;
        fc = exp(x) - exp(-x) - 2;
        if (fb * fc < 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }
    cout << "x = " << (a + b) / 2 << endl;
}

//Метод  Ньютона

double f(double x) {
    return exp(x) - exp(-x) - 2;
}
double f1(double x) {
    return exp(x) + exp(-x);
}
double f2(double x) {
    return exp(x) - exp(-x);
}

void method2() {
    double a, b, x;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    if (f(a) * f2(a) > 0)
    {
        x = a;
    }
    else
    {
        x = b;
    }
    while (abs(f(x) >= epsilon))
    {
        x = x - f(x) / f1(x);
    }
    cout << "x = " << x << endl;
}

//Метод итераций

double e = exp(1.0);
double j(double x) {
    return pow(e, x) - pow(e, -x) - 2;
}
double j_j(double x) {
    return pow(e, x) + pow(e, -x);
}
double phi(double x) {
    return x - j(x) / j_j(x);
}
void method3() {
    double a, b;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;

    double x0 = (b + a) / 2;
    int count_iterations = pow(10, 5), iterations = 0;
    double x = x0;
    while (abs(j(x))> epsilon && iterations < count_iterations)
    {
        x = phi(x);
        iterations++;
    }
    cout << x;
}