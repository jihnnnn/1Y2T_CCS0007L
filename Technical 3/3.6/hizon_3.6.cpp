#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string sentence;
	string word;
	
	cout << "Enter a string: ";
	getline(cin, sentence);
	
	for(int i = sentence.length(); i >= 0; i--){
		if(sentence[i] == ' ' || i == 0){
			if(i == 0){
				word = sentence[i] + word;
			}
			
			cout << word << endl;
			word = " ";
		}
		else{
			word = sentence[i] + word;
		}
	}
	
	return 0;
}
