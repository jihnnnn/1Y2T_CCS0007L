#include <iostream>
using namespace std;

char* stringRev(char *s);
int main() {
	char str[] = "Happy Day";
	cout << stringRev(str);
	system("pause > 0 ");
	return 0;
}

char* stringRev(char *s){
	char *tmp;
	tmp = new char;
	int i, cnt(0);
	
	for(i = 0; s[i] != '\0'; i++){
		cnt++;
	}
	for(i = 0; cnt > 0; i++){
		tmp[i] = s[cnt - 1];
		cnt--;
	}
	
	tmp[i] = '\0';
	return tmp;
}
