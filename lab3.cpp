#include <iostream>
using namespace std;
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    int max = arr[0];
    // Find min
    for (int i = 0; i < size;i++){
        if(min>arr[i]){
            min = arr[i];
        }
    }
    // Find max
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << min << endl;
    cout << max << endl;
    return 0;
}