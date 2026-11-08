#include <iostream>
#include <string.h>
using namespace std;

struct Player {
	string nickname;
	int age = 0;
	double score1 = 0, score2 =0;
};

void line();
void menu();
void cleanScrn();
void noInput();
void addRecord(Player player[], int& playerNum, int& playerCounter);
void viewRecord(const Player player[], int& playerNum, int& playerCounter);
double computeAverage(const Player& player);
void showMax(const Player player[], int playerNum, int playerCounter);
void showMin(const Player player[], int playerNum, int playerCounter);


int main() {
	int choice, playerNum = 0, playerCounter = 0;
	Player player[5];
	bool checkForRecord = false;
	
	do{
		menu();
		cin >> choice;
		
		switch(choice){
			case 1:
				system("cls");
				if(playerNum < 5){
					addRecord(player, playerNum, playerCounter);
					checkForRecord = true;
				}
				else{
					system("cls");
					cout << "Player record is full!\n\n";
					cleanScrn();
				}
				break;
				
			case 2:
				system("cls");
				if(checkForRecord == true){
					viewRecord(player, playerNum, playerCounter);
				}
				else{
					noInput();
				}
				break;
				
			case 3:
				system("cls");
				if(checkForRecord == true){
					cout << "*****AVERAGE SCORES*****\n\n";
					
					playerNum = 0;
					for(int i = 0; i < playerCounter; i++){
						double result = computeAverage(player[i]);
						cout << "The average of " << player[playerNum].nickname << " is " << result << endl;
						playerNum++;
					}
					
					cleanScrn();
				}
				else{
					noInput();
				}
				break;
			case 4:
				system("cls");
				showMax(player, playerNum, playerCounter);
				break;
			case 5:
				system("cls");
				showMin(player, playerNum, playerCounter);
				break;
		}
	}
	while(choice != 6);
	
	return 0;
}

void line(){
	for(int i = 0; i < 40; i++){
		cout << "=";
	}
	cout << endl;
}

void cleanScrn(){
	system("pause");
	system("cls");
}

void menu(){
	line();
	cout << "\t\tMENU" << endl;
	line();
	cout << "1. Add record" << endl;
	cout << "2. View players record" << endl;
	cout << "3. Compute for the average" << endl;
	cout << "4. Show the player(s) who gets the max average" << endl;
	cout << "5. Show the player(s) who gets the min average" << endl;
	cout << "6. Exit\n\n";
	cout << "Enter Choice: ";
}

void noInput(){
	line();
	cout << "\t\tERROR!" << endl;
	line();
	
	cout << "Please add a record of a player first." << endl;
	cleanScrn();
}

void addRecord(Player player[], int& playerNum, int& playerCounter){
	cout << "*****ADD PLAYER*****\n\n";
	cout << "====" << "Player " << playerNum + 1 << "====" << endl;
	
	cout << "Nickname: ";
	cin >> player[playerNum].nickname;
	cout << "Age: ";
	cin >> player[playerNum].age;
	
	cout << "First Best Score: ";
	cin >> player[playerNum].score1;
	cout << "Second Best Score: ";
	cin >> player[playerNum].score2;
	
	cout << "\nPlayer recorded successfully.\n";
	playerNum++;
	playerCounter++;
	cleanScrn();
}

void viewRecord(const Player player[], int& playerNum, int& playerCounter){
	cout << "*****VIEW PLAYER RECORDS*****\n\n";
	playerNum = 0;
	for(int i=0; i < playerCounter; i++){
		cout << "===Player " << i + 1 << "===" << endl;
		cout << "Nickname: " << player[playerNum].nickname << endl;
		cout << "Age: " << player[playerNum].age << endl;
		cout << "First Best Score: " << player[playerNum].score1 << endl;
		cout << "Second Best Score: " << player[playerNum].score2 << endl << endl;
		playerNum++;
	}
	cleanScrn();
}

double computeAverage(const Player& player){
	return (player.score1 + player.score2)/2;
}

void showMax(const Player player[], int playerNum, int playerCounter){
	double maxAverage = computeAverage(player[0]);
	
	playerNum = 1;
	for(int i = 0; i < playerCounter; i++){
		double currentAverage = computeAverage(player[i]);
		if(currentAverage > maxAverage){
			maxAverage = currentAverage;
			playerNum = i;
		}
	}
	cout << "Player(s) with the maximum average score: " << endl;
	cout << player[playerNum].nickname << " with an average of " << maxAverage << endl;
}

void showMin(const Player player[], int playerNum, int playerCounter){
	double minAverage = computeAverage(player[0]);
	
	playerNum = 1;
	for(int i = 0; i < playerCounter; i++){
		double currentAverage = computeAverage(player[i]);
		if(currentAverage < minAverage){
			minAverage = currentAverage;
			playerNum = i;
		}
	}
	cout << "Player(s) with the average score: " << endl;
	cout << player[playerNum].nickname << " with an average of " << minAverage << endl;
}