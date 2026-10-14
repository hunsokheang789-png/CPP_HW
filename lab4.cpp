#include <iostream>
using namespace std;

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
int main(){
    float a= computeA(5);
    float b = computeB(5);
    float c = computeC(5);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}