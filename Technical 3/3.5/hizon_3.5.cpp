#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	
	string word;
	cout << "Enter some string: ";
	getline(cin, word);
	
	for(int i=0 ; i < word.length(); i++){
		char ch = word[i];
		
		ch = toupper(ch);
		cout << ch;	
	}
	
	return 0;
}
