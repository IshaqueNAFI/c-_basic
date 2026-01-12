#include<iostream>
#include<string>
using namespace std;


//function for sum 
int sumArray(int n, int arr[]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = arr[i] + sum;
	}
	return sum;
}

// function for reverse
int* reverseArray ( int n , int arr[]){
	int* reverse = new int[n];
	for (int i = 0; i < n; i++) {
		reverse[i] = arr[n -1- i];
	}
	return reverse;
}





// sum of numbers using recursion
int recusionSum(int n, int arr[]) {

	if (n == 0) {
		return 0;
	}

	for (int i = 0; i < 0; i++) {
		int sum = 0;

		return 	sum = sum +arr[i];
		}
	}



//function for factorial using recursion
int factorial(int n, int* arr) {
	if (int i = n) {
		return 1;
	}
	else {
		for (int i = 0; i < n; i++) {
			return arr[i] * factorial arr[i - 1];
		}
	}
}



void printArray(int n, int arr[] , int sum, int reverse[]) {
	cout << "the numbers are : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	cout << endl;
	cout << "Their sum is: " << sum << endl;
	cout << endl;
	cout << "Their reverse array are: " << endl;
	for (int i = 0; i < n; i++) {
		cout << reverse[i] << endl;
	}
}

//function for reverse string using recursion
string  callString(string m) {
	if (n < 0) {
		return;
	}

}



int main(){

int n;
string m;
cout << "Give the size of the array :"; 
	cin >> n;
	cout << " give a random name: ";
	cin >> m;
	cout << " Give a random integers: ";
	int* arr = new  int[n];
	for (int i = 0; i < n;i++) {
			cin >> arr[i];
	}
		int s = sumArray(n, arr);
	int* r =reverseArray(n, arr);
	//int f = factorial (n, arr);
	//string st = callString(m);
			printArray(n, arr , s, r);
		return 0;
		delete[] r;
}