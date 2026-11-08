#include <iostream>
#include <string>
using namespace std;

class StudentRecords {
private:
    string subject[3] = { "English", "Math", "Science" };

    struct Student {
        string admission;
        string name;
        float grade[3];
    };

    struct Node {
        Student student;
        Node* next;
    };

    Node* head = nullptr;

    void addStudent(const Student& student) {
        Node* newNode = new Node;
        newNode->student = student;
        newNode->next = head;
        head = newNode;
    }

public:
    void addStudents() {
        Student s;
        for (int i = 0; i < 2; i++) {
            cout << "\tStudent " << i + 1 << endl;
            cout << string(30, '-') << endl;

            cout << "Enter admission number: ";
            cin >> s.admission;
            cout << "Enter student name: ";
            cin >> s.name;

            cout << "Enter grades in English, Math, Science:" << endl;

            for (int j = 0; j < 3; j++) {
                cin >> s.grade[j];
            }
            addStudent(s);
        }
    }

    void viewList() {
    	system("cls");
        Node* current = head;
        while (current != nullptr) {
            cout << "Admission number: " << current->student.admission << endl;
            cout << "Student Name: " << current->student.name << endl;

            float sum = 0;
            for (int i = 0; i < 3; ++i) {
                cout << "Grade in " << subject[i] << ": ";
                cout << current->student.grade[i] << endl;
                sum += current->student.grade[i];
            }

            float average = sum / 3;
            cout << "Average Grade: " << average << endl;
            cout << string(30, '-') << endl;
            current = current->next;
        }
    }
};

int main() {
    StudentRecords record;
    record.addStudents();
    record.viewList();
    return 0;
}
