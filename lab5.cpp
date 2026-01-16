//NAME: ABU ISHAQUE MD ISRAIL
//ID: 0449749

#include<iostream>
using namespace std;
void bubblesort(int arr[], int length) {
    
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        }
    }
int main() {
    int n;
    cout << "Give me the size of the array : ";
    cin >> n;
    int* arr = new int[n];

    cout << "Give me the few integer numbers:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubblesort(arr, n);

    cout << "The sorted integers are :";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
	





























