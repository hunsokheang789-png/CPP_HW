#include <iostream>
using namespace std;
int main(){
    // a. Take 10 numbers as input and print them in a reverse order.
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 9; i >= 0; i--)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    // b. Count how many numbers are even in this array.
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}