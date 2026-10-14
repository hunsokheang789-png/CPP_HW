#include <iostream>
using namespace std;

// 1. Write a C++ program to print out the following information:
void printInfo()
{
    cout << "-----------------------" << "\n\n";
    cout << "Welcome to Data Structure and Programming class" << endl;
    cout << "-----------------------" << endl;
    cout << "My name is Sokheang I am currently a year 2 student from group 2 and CS  department. I am so excited to start my class in this term. " << endl;
}


// 4. Create functions in C++ to compute the following formula,
// where n is a parameter passed to this function. Protype of this function is: float compute(int n);

// a. 1 + 2 + 3 + …. n = ?
float computeA(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

// b. 12 + 22 + 32 + … n2 = ?
float computeB(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i * i;
    }
    return sum;
}

// c.1 / 1 + 1 / 2 + 1 / 3 + ….+ 1 / n = ?
float computeC(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1.0f / i;
    }
    return sum;
}
int main()
{
    printInfo();

    arr();

    float a = computeA(5);
    float b = computeB(5);
    float c = computeC(3);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}