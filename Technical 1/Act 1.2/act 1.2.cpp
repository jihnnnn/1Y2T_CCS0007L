#include <iostream>
#include <cmath>
using namespace std;

void lineAsterisk();
void lineDash();
void menu();
double solveSquare(double input1);

int main(){
	char choice;
	double input1=0, input2=0, result=0;

	menu();
	cout << endl << "Enter your choice: "; cin >> choice;
	lineDash();
	
	switch(choice){
		case '1':
			cout << "AREA OF SQUARE" << endl;
			lineDash();
			cout << "Enter the side of the square: "; cin >> input1;
			cout << endl << "The area is " << pow(input1, 2) << " sq. units";
			break;
			
		case '2':
			cout << "AREA OF RECTANGLE" << endl;
			lineDash();
			cout << "Enter the length and width of the rectangle: "; cin >> input1 >> input2;
			result = input1 * input2;
			cout << endl << "The area is " << result << " sq. units";
			break;
			
		case '3':
			cout << "AREA OF TRIANGLE" << endl;
			lineDash();
			cout << "Enter the base and width of the height: "; cin >> input1 >> input2;
			result = (input1 * input2)/2;
			cout << endl << "The area is " << result << " sq. units";
			break;
		case '4':
			cout << "AREA OF CIRCLE" << endl;
			lineDash();
			cout << "Enter the radius: "; cin >> input1;
			result = M_PI * pow(input1, 2);
			cout << endl << "The area is " << result << " sq. units";
			break;
		case '5':
			cout << "Thank You!" << endl;
			return 0;
			break;
			
		default:
			cout << "INVALID INPUT!";
	}
	return 0;
}
	
	

void lineAsterisk(){
	for(int i; i < 20; i++){	
		cout << "*";
	}
}
void lineDash(){
	for(int i; i < 20; i++){	
		cout << "-";
	}
	cout << endl;
}

void menu(){
	lineAsterisk();
	cout << endl << "MENU" << endl;
	lineAsterisk(); cout << endl;
	cout << "[1] - Area of Square" << endl;
	cout << "[2] - Area of Rectangle" << endl;
	cout << "[3] - Area of Triangle" << endl;
	cout << "[4] - Area of Circle" << endl;
	cout << "[5] - Exit" << endl;
	lineDash();
}