#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

struct userInfo{
	string name;
	string course;
	string email;
	string number;
};

void createFile(const userInfo& info);
void readFile();
void appendFile();
void end();
void Menu();
bool checkForNum(string input);

int main(){
	userInfo ui;
	char choice;
	
	do{
		Menu();
		cin >> choice;
		switch(choice){
			case '1':
				bool isValidNumber;
				do{
					isValidNumber = true;
					cin.ignore();
					
					system("cls");
					cout << "Create File\n";
					cout << string(30, '-') << endl;
					
					cout << "Name: ";
					getline(cin, ui.name);
					cout << "Course: ";
					cin >> ui.course;
					cout << "Email: ";
					cin >> ui.email;
					cout << "Number: ";
					cin >> ui.number;
					
					isValidNumber = checkForNum(ui.number);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');		
				} while(!isValidNumber);
				createFile(ui);
				end();
				break;
				
			case '2':
				system("cls");
				cout << "View Contents\n";
				cout << string(30, '-') << endl;
				readFile();
				break;
				
			case '3':
				system("cls");
				cout << "Append Text\n";
				cout << string(30, '-') << endl;
				appendFile();
				break;
			case '4':
				system("cls");
				cout << "Program Ended\n";
				return 0;
			default:
				cout << "Enter Valid Option.";
				end();
				break;
		}
		
	} while(choice != '4');
	
	return 0;
}

void Menu(){
	cout << "MAIN MENU\n";
	cout << "1. Create\n";
	cout << "2. Read\n";
	cout << "3. Append\n";
	cout << "4. Exit\n\n";
	cout << "Choose an option: ";
}

void end(){
	system("pause");
	system("cls");
}

bool checkForNum(string input){
    
	for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];
        if(!isdigit(ch)){
        	cout << "Please enter valid number";
			end();
			return false;
		}
    }
    return true;
}

void createFile(const userInfo& info){
	ofstream file("mytext.txt"); 
	if(file.is_open()){
		file << "Name: " << info.name << endl; 
		file << "Course: " << info.course << endl;
		file << "Email: " << info.email << endl;
		file << "Number: " << info.number;
		
		file << endl;
	}
	else{
		cout << "ERROR! Unable to open file.\n";
		end();
	}
	file.close();
	cout << "\nRecords saved to 'mytest.txt'.\n"; 
}

void readFile(){
	ifstream file("mytext.txt");
	if(file.is_open()){
		string line;
		while(getline (file, line)){
			cout << line << endl;
		}
	}
	else{
		cout << "ERROR! Unable to open file.\n";
		end();
	}
	file.close();
	end();
}

void appendFile(){
	fstream file;
	string appendedText;
	file.open("mytext.txt", fstream::in | fstream:: out | fstream:: app);
	cin >> appendedText;
	file << appendedText;
	file.close();
	end();
}