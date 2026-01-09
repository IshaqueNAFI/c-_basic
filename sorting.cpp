//selctionn dort 
#include<iostream>
using namespace std;

//sort 
void selctionSort(int n,int arr[]){

	for (int i = 0; i<n - 1; i++) {

		int smallestValue = i;

		for (int j = i + 1; j < n; j++) {

			if (arr[j] < arr[smallestValue]) {
				smallestValue = j;
			}
		}
		swap(arr[i], arr[smallestValue]);
	}
}


//print fuction 

void printFunction(int n, int arr[]) {

	for (int i = 0; i < n; i++) {

		cout << arr[i] << " ";
	}
}




//array input and fuction call
int main() {
	int n;

	cout << " give the size of the array between 1 to 10 :";
	cin >> n;

	int* arr = new int[n]; // dyhnamic memory 

	cout<<	"give random numbers:";

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
		selctionSort(n, arr);
		printFunction(n, arr);
		return 0;

}





/* BUBBLE SORTING 
#include<iostream>
using namespace std;

//bubble sorting fuction
void bubblesort(int n, int arr[]) {
for (int i = 0; i <n - 1; i++) {
	bool isSwap = false;

	for (int	j = 0; j < n - i - 1;j++) {

		if (arr[j] > arr[j + 1])
		{
			swap(arr[j], arr[j + 1]);
			isSwap = true;
		}
		if (!isSwap)
		{
			return;
		}
	}
}
}
//function for print
void printFunction(int n, int arr[]) {
	for (int i = 0; i < n;i++) {
	
		int result = arr[i];

		cout << result << " ";
	}
	}


//main fuction for user input 
int main() {

	int n;
	cout << " give me the size of array: ";   //ask to give array size
	cin >> n;


	int* arr = new int[n];      //creating memories for new array dinemitically
cout << " Give me some random integers: ";  //ask to array integers
	for (int i = 0; i < n;i++) {

		cin >> arr[i];     //will take input one after another 

	}

	bubblesort(n, arr);  //call bubble function to do sorting 
	printFunction(n, arr);    //call print function to print

	return 0;
}
// Read all the input(loop) in Main
//  then sort (loop) in bubblesort
//  thn print (loop)
*/