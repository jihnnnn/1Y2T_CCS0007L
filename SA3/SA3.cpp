#include <iostream>
#include <string.h>
#include <limits>
#include <ctime>
using namespace std;
int border = 45;
 
struct Product {
	string name;
	double price;
};
 
struct Node {
	Product product;
	Node* next;
};
 
Product vskinProduct[] = {
	{"Kuronami", 3000},
	{"Neon Frontier", 2500},
	{"Prime", 2200},
	{"Reaver", 100},
	{"Oni", 2300}
};
const int MAX_PRODUCT = 5;
struct Node* head = NULL;
 
void Menu();
void selectProduct();
void addCart (const Product& product);
void viewCart();
void computeTotal(bool shopping_cart);
void END();
void cart(bool checker);
void group();
void endline();
void ERROR(bool shopping_cart);
void dot();
void loadingScreen();
void loadingBar(int bar, int space);
int countNameCharacters(const Node* node);
void priceSpace(const Node* current);
void getCurrentDateTime();
int main() {
	
	char input, addAgain, exit;
 	bool hasItem = false;
 	loadingScreen();
	do {
		system ("cls");
		Menu();
	    cin >> input;
	    system ("cls");
	    switch (input){
	    	case '1':
	    		hasItem = true;	
				do{
					system("cls");
	    			selectProduct();
	    			cout << "Would you like to add another item? (Y/N): ";
	    			cin >> addAgain;
				}
				while(addAgain == 'y' || addAgain == 'Y');	  
				break;
	    	case '2':
	    		if(hasItem == true){
	    			cout << string(20, '-') << endl;
					cout << string (3, ' ') << "Shopping Cart" << endl;
					cout << string(20, '-') << endl;
					viewCart();
	    			cart(hasItem);
	    			END();
				}
				else{
					ERROR(hasItem);
				}
	    	 	
	    		break;
	    	case '3':
	    		if(hasItem == true){
	                computeTotal(hasItem);
				}
				else{
					ERROR(hasItem);
				}
	    		break;
			case '4':
				
					cout << "Do you really want to exit? (Y/N): ";
					cin >> exit;
				if(exit == 'y'|| exit == 'Y'){
					system("cls");
					cout << "Exiting program.";
					dot();
					system("cls");
					cout << "Thank you for your purchase!" << endl; 
					group();
					return 0;
				}			
				break;
	    	default: 
	    		system("cls");
				cout << "Invalid choice.\n\n"; 
				END();
		}
	}
	while (input != 6);
	return 0;
}
 
void ERROR(bool shopping_cart){
	cout << string(20, '-') << endl;
	cout << string (3, ' ') << "Shopping Cart" << endl;
	cout << string(20, '-') << endl;
	cout << string (3, ' ') << "****ERROR!****";
	cout << "\n\nYour Cart is Empty. :(\n";
	cart(shopping_cart);
	cout << "\nPlease add an item first." << endl;
	cout << string(20, '_') << endl;
	END();
}
void END(){
	system("pause");
	system("cls");
}

void endline(){
	for(int i = 0; i < 2; i++){
		cout << endl;
	}	
}

void cart(bool checker){
	if(checker == true){
	 	cout << "   _" << endl;
	 	cout << "    \\###/" << endl;
		cout << "     o o" << endl;		
	}
	else{
		cout << "   _" << endl;
 		cout << "    \\___/" << endl;
		cout << "     o o" << endl;
	}
}

void group(){
	endline();
	cout << string(border, '=') << endl;
	cout << "\t\tGroup Dokito 466" << endl;
	cout << "\t\tMEMBERS NA MALUPET" << endl;
	cout << string(border, '=') << endl;
	cout << "-Jed Hizon\n";
	cout << "-Mark Anthony Petrimetre\n";
	cout << "-Patricia Nicole Formoso\n";
	cout << "-Kian Shane Basister\n";
}

void Menu(){
	cout << string(border, '=') << endl;
	cout << "\t\tDokito Skins 466\n";
	cout << string(border, '=') << endl;
	cout << "1. Buy Bundle Skin\n";
	cout << "2. View Cart\n";
    cout << "3. Checkout\n";
	cout << "4. Exit\n";
	cout << string(border, '-') << endl;
	cout << "Enter your choice: ";
}

void selectProduct(){
	int choice = 0;
	bool checkFail = true;
	do{
		checkFail = true;
		cout << string(border, '-') << endl;
		cout << "\t\tAvailable Products\n";
		cout << string(border, '-') << endl;
		
		for(int i = 0; i < MAX_PRODUCT; i++){
			cout << i+1 << ". " << vskinProduct[i].name << " = Php " << vskinProduct[i].price << endl;
		}
		cout << string(border, '*') << endl;
		
		cout << "Select your product: ";
		cin >> choice;
		
		if(cin.fail()||choice < 0 || choice > MAX_PRODUCT){
			system("cls");
			cout << "***ERROR!***\n";
			cout << "Invalid Choice\n\n";
			END();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			checkFail = false;
		}
	}
	while(checkFail == false);
	 system("cls");
    cout << "Processing order.";
    for(int i = 3; i >= 1; i--) {
        cout << ".";
        usleep(750000);
    }
    cout << string(border, '*') << endl;
    addCart(vskinProduct[choice-1]);
    system ("cls");
    cout << "Product has been added to your cart." << endl << endl;
}

void dot(){
	for(int i = 0; i < 3; i++){
		usleep(750000);
		cout << ".";
	}
}

void addCart (const Product& product) {
	Node* newNode = new Node;
	newNode -> product = product;
	newNode -> next = head;
	head = newNode; 
	}
 
 void viewCart() {
    Node* current = head;
    while (current != nullptr) {
    	int spaceLength = countNameCharacters(current);
       
	    cout << current->product.name;
		
		for(int i = 20; i > spaceLength; i--){
    		cout << " ";
		}
		
		cout << " = Php " << current->product.price << endl;
        current = current->next;
    }
}

int countNameCharacters(const Node* node) {
    return node->product.name.length();
}

void computeTotal(bool checker) {
	cout << "+" << string(border, '-') << "+" << endl;
	cout << "\t    --Dokito Skins 466--" << endl;
    cout << "+" << string(border, '-') << "+" << endl;
    cout << "Date: ";
    getCurrentDateTime();
    cout << endl;
    cout << "\t    R e c e i p t\n" << endl;
    cout << "Items" << endl;
    viewCart();
    cout << "+" << string(border, '-') << "+" << endl;
	
    double total = 0.0;
    Node* current = head;
    while (current != NULL) {
        total += current -> product.price;
    	current = current->next;
    }
    cout << "Total: " << "\t\t\tPhp " << total << endl;
    double cash;
    cout << "Enter amount:  " << "\t\tPhp "; 
    cin >> cash;
 
    if (cash < total) {
        cout << "kulang bhie... utang ka na lang muna sa kapitbahay mo" << endl;
        system("pause");
        return;
    }
    double change = cash - total;
    cout << "Change: " << "\t\tPhp " << change << endl;
    cout << "+" << string(border, '-') << "+" << endl;
    cout << "\t Thank you for shopping mwa!" << endl;
    cout << "\t (. 3 .)" << endl;
    cart(checker);
    system("pause");
}

void getCurrentDateTime() {
    time_t currentTime = time(0);
    char* dateTime = ctime(&currentTime);
    cout << dateTime << endl;
}

void loadingScreen(){
	int space = 20, bar=0;
	cout << "Program Loading" << endl;
	cout << "|" << string(20, ' ') << "|" << endl;
	for(int i = 0; i < 5; i++){
		loadingBar(bar,space);
		bar+=4;
		space-=4;
	}
	loadingBar(bar,space);
	
	system("cls");
	cout << "Program Loaded.\n";
	sleep(1);
}

void loadingBar(int bar, int space){
	system("cls");
	cout << "Program Loading" << endl;
	cout << "|" << string(bar, '#') << string(space, ' ') << "|" << endl;
	usleep(750000);
}