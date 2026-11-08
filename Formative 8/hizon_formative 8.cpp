#include <iostream>
#include <string>
using namespace std;

struct Student{
	string admission;
	string name;
	string subject[3] = {"English", "Math", "Science"};
	string grade[3];
};

int main(){
	Student student;
	
	cout << "Enter admission number: ";
	cin >> student.admission;
	cout << "Enter student name: ";
	cin >> student.name;
	
	cout << "Enter grades in English, Math, Science:" << endl;
	for(int i = 0; i < 3; i++){
		cin >> student.grade[i];
	}
	
	cout << "Admission number: " << student.admission << endl;
	cout << "Student name: " << student.name << endl;
	
	for(int i = 0; i < 3; i++){
		cout << student.subject[i] << ": ";
		cout << student.grade[i] << endl;
	}
	return 0;
} 
