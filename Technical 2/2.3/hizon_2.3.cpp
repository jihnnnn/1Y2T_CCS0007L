#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	int vowels[5] = {0}, space = 0;
	bool caps = true;
	
	do{
		system("cls");
		caps = true;
		
		cout << "Enter a String: ";
		getline(cin, input);
	
		for(int i=0; i < input.length(); i++){
			char letter = input[i];
			
			if(islower(letter)){
				caps = false;
			}
		}
		
		if(caps == false){
			cout << "Please use only CAPITAL letters." << endl;
			system("pause");
		}
	}
	while(caps == false);
	
	for(int i=0; i < input.length(); i++){
			char letter = input[i];
			
			if(isalpha(letter)){
				switch(letter){
					case 'A':
						++vowels[0];
						break;
					case 'E':
						++vowels[1];
						break;
					case 'I':
						++vowels[2];
						break;
					case 'O':
						++vowels[3];
						break;
					case 'U':
						++vowels[4];
						break;
				}
			}
			
			else if(isspace(letter)){
				space++;
			}
		}
	cout << "Vowels: " << endl;
	cout << "A " << vowels[0] << endl;
    cout << "E " << vowels[1] << endl;
    cout << "I " << vowels[2] << endl;
    cout << "O " << vowels[3] << endl;
    cout << "U " << vowels[4] << endl;
    cout << "White Spaces: " << space;
	
	return 0;
}
