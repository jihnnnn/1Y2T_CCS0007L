#include <iostream>
#include <cstring>
using namespace std;

void line();

int main(){
	char str1[100], str2[100];
	
	line(); 
	cout << "STRING CONCATENATION" << endl;
	line();
	
	cout << "Enter a first word (str1): ";
	cin.getline(str1, 100);
	cout << "Enter a second word (str2): ";
	cin.getline(str2, 100);
	
	strcat(str1, str2);
	
	cout << "new string for str1: " << str1;
	
}

void line(){
	for(int i = 0; i < 15; i++)
		cout << "*";
	cout << endl;
}
