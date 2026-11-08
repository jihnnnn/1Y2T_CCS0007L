#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double add(double in1, double in2);
double subtract(double in1, double in2);
double multiply(double in1, double in2);
double divide(double in1, double in2);
int modulo(int in1, int in2);
void menu();
int main() {
	string op[6] = {"Sum", "Difference", "Product", "Quotient", "Modulo", "Power"};
	int choice;
	double num1 = 0, num2 = 0, result = 0;
	int mod1 = 0, mod2 = 0, modResult = 0; 
	
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;
	
	cout << endl;
	menu();
	cout << "\nChoose an Operator: ";
	
	cin >> choice;
	
	switch(choice){
		case 1:
			result = add(num1, num2);
			break;
		case 2:
			result = subtract(num1, num2);
			break;
		case 3:
			result = multiply(num1, num2);
			break;
		case 4:
			result = divide(num1, num2);
			break;
		case 5:
			modResult = modulo(mod1, mod2);
			break;
		case 6:
			result = pow(num1, num2);
			break;
		default:
			cout << "Invalid Choice!";
	}
	cout << "\nThe " << op[choice-1] << " of " << num1 << " and " << num2 << " is " << result;
	return 0;
}

void menu(){
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << "5. Modulo" << endl;
	cout << "6. Powers";
}

double add(double in1, double in2){
	return in1 + in2;
}
double subtract(double in1, double in2){
	return in1 - in2;
}
double multiply(double in1, double in2){
	return in1 * in2;
}
double divide(double in1, double in2){
	return in1 / in2;
}
int modulo(int in1, int in2){
	return in1 % in2;
}