#include <iostream>
using namespace std;

int main() {
	int numbers[9], n=0;;
	cout << "Enter 10 numbers: ";
	
	for(int i=0; i < 10; i++){
		cin >> numbers[i];
	}
	cout << "Even numbers are located at indices: ";
	for(int i=0; i<10; i++){
		if(numbers[i] % 2 == 0){
			cout << n << " ";
		}
		n++;
	}
	if(numbers[9] % 2 == 0){
			n--;
			cout << n;
		}
	return 0;
}
