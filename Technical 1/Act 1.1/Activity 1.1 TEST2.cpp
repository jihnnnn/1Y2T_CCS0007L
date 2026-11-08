#include <iostream>
using namespace std;

void Options();
int getOperator(int choice);
int solveNumbers(int choice, int input1, int input2);

int main(){
	char cont;
	do{
		int choice = 0, num1 = 0, num2 = 0, result = 0;
		
		system("cls");
		Options();
		
		cout << "Enter your choice (1-5): "; cin >> choice;
		if(choice >= 1 && choice <= 5){
			cout << "Enter your two interger numbers: "; cin >> num1 >> num2;
			
			result = solveNumbers(choice, num1, num2);
			cout << "Result: " << result << endl << endl;
			
			cout << "Would you like to solve for another set of numbers? (y/n) "; cin >> cont;	
			}   

		else{
			cout << "Invalid Operator! \n\nWould you like to try again?(y/n) ";
			cin.clear();
			cin.ignore();
			cin >> cont;
		}
	}
	while(cont == 'Y'||cont == 'y');
	cout << "\nEND";
	
	return 0;
}

void Options(){
	cout << "   1. Add" << endl;
	cout << "   2. Subtract" << endl;
	cout << "   3. Multiply" << endl;
	cout << "   4. Divide" << endl;
	cout << "   5. Modulus" << endl;
}

int solveNumbers(int choice, int input1, int input2){
	int result;
	
	switch(choice){
		case 1:
			return input1 + input2;
			break;
		case 2:
			return input1 - input2;
			break;
		case 3:
			return input1 * input2;
			break;
		case 4:
			return input1 / input2;
			break;
		case 5:
			return input1 % input2;
			break;
	
	}
}

