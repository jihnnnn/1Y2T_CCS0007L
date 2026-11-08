#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n = 0;

	
	cout << "Enter the size of the array: ";
	cin >> n;
	
	int array[n];
	for(int i = 0; i < n; i++){
		cout << "Array element " << i+1 << ": ";
		cin >> array[i];
	}
	
	sort(array, array + n);
	
	cout << "The sorted array is: ";
	
	for(int i=0; i < n; i++){
		cout << array[i] << " ";
	}
	
	return 0;
}
