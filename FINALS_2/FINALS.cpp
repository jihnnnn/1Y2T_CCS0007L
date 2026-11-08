#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Student {
    int id;
    char gender;
    string name;
    string bday;
    string address;
    string program;
    string yLevel;
};

class StudentRecordProgram {
private:
    const int MAX_STUDENTS = 3;
    const int mainBorder = 38;

    void cls(bool pause) {
        if (pause == 1) {
            system("pause");
            system("cls");
        }
        else
            system("cls");
    }

    void pageTitle(string title) {
        cout << string(mainBorder, '-') << endl;
        cout << "\t" << title << endl;
        cout << string(mainBorder, '-') << endl;
    }

public:
    void addRecord() {
    	bool isID_Number = true;
        	cls(0);
	        pageTitle("Add Student Record");
	
	        ofstream studentFile("student.txt", ios::app);
	
	        Student* newStudent = new Student;
	
	        cout << "Enter Student ID: ";
	        cin >> newStudent->id;
	        
	        if (cin.fail()){
			    errorSign("Enter only numbers.");
			    cin.clear(); 
			    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			    isID_Number = false;
  			}
  			
  			if(isID_Number){
  				
		        cout << "Enter Full Name: ";
		        cin.ignore();
				getline(cin, newStudent->name);
		        cout << "Enter Gender (M/F): ";
		        cin >> newStudent->gender;
		        cin.ignore();
		        cout << "Enter Birthday (MM/DD/YYYY): ";
		        getline(cin, newStudent->bday);
		        cout << "Enter Address: ";
		        getline(cin, newStudent->address);
		        cout << "Enter Degree Program: ";
		        getline(cin, newStudent->program);
		        cout << "Enter Year Level: Year ";
		        cin >> newStudent->yLevel;
	        
	
	        if (studentFile.is_open()) {
	            studentFile << newStudent->id << ", ";
	            studentFile << newStudent->name << ", ";
	            studentFile << newStudent->gender << ", ";
	            studentFile << newStudent->bday << ", ";
	            studentFile << newStudent->address << ", ";
	            studentFile << newStudent->program << ", ";
	            studentFile << newStudent->yLevel << endl;
	        }
	        else {
	            errorSign("Unable to add record.\n");
	        }
	
	        studentFile.close();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "\nRecord Add Successfully!" << endl;
	        delete newStudent;
	
	        cls(1);
	    }
    }

	void displayRecord() {
    	cls(0);
        pageTitle("Student Records List");

        ifstream studentFile("student.txt");
        if (!studentFile.is_open()) {
            cout << "\nError opening file." << endl;
            return;
        }

        Student tempStudent;
        bool isValidRecord = false;
        
        while (studentFile >> tempStudent.id) {
            studentFile.ignore();
            getline(studentFile, tempStudent.name, ',');
            studentFile >> tempStudent.gender;
            studentFile.ignore();
            getline(studentFile, tempStudent.bday, ',');
            getline(studentFile, tempStudent.address, ',');
            getline(studentFile, tempStudent.program, ',');
            getline(studentFile, tempStudent.yLevel);

            cout << "Student ID: " << tempStudent.id << endl;
            cout << "Name: " << tempStudent.name << endl;
            cout << "Gender: " << tempStudent.gender << endl;
            cout << "Birthday: " << tempStudent.bday << endl;
            cout << "Address: " << tempStudent.address << endl;
            cout << "Course Program: " << tempStudent.program << endl;
            cout << "Year Level: " << tempStudent.yLevel << endl;
			
            isValidRecord = true;
   		}
   		if(!isValidRecord){
   			errorSign("Student not found.");
		   }
		studentFile.close();
		cls(1);
	}
	
    void searchStudent() {
	    cls(0);
	    bool isID_Number = true;
	    pageTitle("Search Specific Record");
	
	    ifstream studentFile("student.txt");
	    if (!studentFile.is_open()) {
	        cout << "\nError opening file." << endl;
	        return;
	    }
	    
	    int searchID;
	    cout << "Enter Student ID to search: ";
	    cin >> searchID;
	    if (cin.fail()){
			    errorSign("Enter only numbers.");
			    cin.clear(); 
			    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			    isID_Number = false;
  		}
		if(isID_Number){
		    Student tempStudent;
		    bool isSearchFound = false;
		    bool isID_Number = true;
		    
		    while (studentFile >> tempStudent.id) {
		        studentFile.ignore();
		        getline(studentFile, tempStudent.name, ',');
		        studentFile >> tempStudent.gender;
		        studentFile.ignore();
		        getline(studentFile, tempStudent.bday, ',');
		        getline(studentFile, tempStudent.address, ',');
		        getline(studentFile, tempStudent.program, ',');
		        getline(studentFile, tempStudent.yLevel);
		        
		        if(tempStudent.id == searchID){
		            cout << "Student ID: " << tempStudent.id << endl;
		            cout << "Name: " << tempStudent.name << endl;
		            cout << "Gender: " << tempStudent.gender << endl;
		            cout << "Birthday: " << tempStudent.bday << endl;
		            cout << "Address: " << tempStudent.address << endl;
		            cout << "Course Program: " << tempStudent.program << endl;
		            cout << "Year Level: " << tempStudent.yLevel << endl;
		            isSearchFound = true;
		        }
		    }
		    
		    if(!isSearchFound){
		        errorSign("Student not found.");
		    }
		    
		    studentFile.close();
		    cls(1);
		}
}

    void deleteRecord() {
    	cls(0);
        int deleteID;
        bool isID_Number = true;
        
        cout << "\nEnter Student ID to delete: ";
        cin >> deleteID;
        
		if (cin.fail()){
			    errorSign("Enter only numbers.");
			    cin.clear(); 
			    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			    isID_Number = false;
  		}
		if(isID_Number){
	        ifstream studentFile("student.txt");
	        if (!studentFile.is_open()) {
	            cout << "\nError opening file." << endl;
	            return;
	        }
	
	        ofstream tempFile("temp.txt");
	        if (!tempFile.is_open()) {
	            cout << "\nError creating temporary file." << endl;
	            studentFile.close();
	            return;
	        }

	        Student tempStudent;
	        bool isID_Deleted = false;
	        while (studentFile >> tempStudent.id) {
	            studentFile.ignore();
	            getline(studentFile, tempStudent.name, ',');
	            studentFile >> tempStudent.gender;
	            studentFile.ignore();
	            getline(studentFile, tempStudent.bday, ',');
	            getline(studentFile, tempStudent.address, ',');
	            getline(studentFile, tempStudent.program, ',');
	            getline(studentFile, tempStudent.yLevel);
	
	            if (tempStudent.id != deleteID) {
	                tempFile << tempStudent.id << ", " << tempStudent.name << ", " << tempStudent.gender << ", " << tempStudent.bday << ", " << tempStudent.address << ", " << tempStudent.program << ", " << tempStudent.yLevel << endl;
	            }
	            else {
	                cout << "\nRecord with Student ID " << deleteID << " deleted successfully!" << endl;
	                isID_Deleted = true;
	            }
	        }
	        if (!isID_Deleted) {
				errorSign("Student not found.");
				return;
	        }
	        studentFile.close();
	        tempFile.close();
	
	        remove("student.txt");
	        rename("temp.txt", "student.txt");
	        cls(1);
		}
    }
    
    void errorSign(string errorMessage) {
    	cls(0);
        cout << string(40, '=') << endl;
        cout << "  ______ _____  _____   ____  _____   |" << endl;
        cout << " |  ____|  __ \\|  __ \\ / __ \\|  __ \\  |" << endl;
        cout << " | |__  | |__) | |__) | |  | | |__) | |" << endl;
        cout << " |  __| |  _  /|  _  /| |  | |  _  /  |" << endl;
        cout << " | |____| | \\ \\| | \\ \\| |__| | | \\ \\  |" << endl;
        cout << " |______|_|  \\_\\_|  \\_\\\\____/|_|  \\_\\ o" << endl;
        cout << string(40, '=') << endl;
        cout << errorMessage << endl;
        cls(1);
    }
};

void displayMenu();
void pageTitle(string title);

int main() {
    StudentRecordProgram program;
	
    char choice = 0;
    do {
    	pageTitle("466 Dokito System");
        displayMenu();
        cin >> choice;
        switch (choice) {
        case '1': //Add student to records list
            program.addRecord();
            break;
        case '2': //Search student by ID
        	program.searchStudent();
            break;
        case '3': //Delete record
            program.deleteRecord();
            break;
        case '4': //View records list
            program.displayRecord();
            break;
        case '5': //Exit Program
        	char confirm;
        	system("cls");
        	cout << "Are you sure you want to exit? (Y/N): ";
        	cin >> confirm;
        	if(confirm == 'y' || confirm == 'Y'){
        		system("cls");
        		pageTitle("466 Dokito System");
	            cout << "\nThank you for trusting 466 Dokito Information System!" << endl << endl;
	            cout << "Group: 466" << endl;
	            cout << "Members:" << endl;
	            cout << "- Jed Hizon" << endl;
	            cout << "- Mark Petrimetre" << endl;
	            cout << "- Kian Basister" << endl;
	            cout << "- Patricia Formoso" << endl << endl;
	            return 0;
			}
			system("cls");
            break;
        default:  //Error when invalid option
        	program.errorSign("Invalid choice");
            break;
        }

    } while (choice);

    return 0;
}

void displayMenu() {
    cout << "1. Add new record\n";
    cout << "2. Search record\n";
    cout << "3. Delete record\n";
    cout << "4. Display records\n";
    cout << "5. Exit\n";
    cout << "\nChoose an option: ";
}

void pageTitle(string title) {
    cout << string(38, '-') << endl;
    cout << "\t" << title << endl;
    cout << string(38, '-') << endl;
}