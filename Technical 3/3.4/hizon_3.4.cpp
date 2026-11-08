#include <iostream>
#include <cstring>
using namespace std;

void line();

int main() {
	char str[100];
	
	line();
	cout << "PALINDROME" << endl;
	line();
	
	cout << "Enter a word: ";
	cin.getline(str, 100);
	
	int length = strlen(str);
	bool palindrome = true;

    for(int i = 0; i < length / 2; ++i) {
        if(str[i] != str[length - 1 - i]) {
            palindrome = false;
        }
    }
    
	if(palindrome){
		cout << str << " is a palindrome";
	}
	else{
		cout << str << " is not a palindrome";
	}
	return 0;
}

void line(){
	for(int i = 0; i < 15; i++){
		cout << "*";
	}
	cout << endl;
}
