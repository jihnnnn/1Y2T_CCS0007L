#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string word(string word) {
    for (size_t i = 0; i < word.length(); ++i) {
        char& c = word[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + 1) % 26 + base;
        }
    }
    return word;
}

int main() {
    string Word;

    cout << "Enter a word: ";
    getline(cin, Word);

    cout << "\nOriginal string: " << Word << endl;

    string Strings = word(Word);

    cout << "\nNew String: " << Strings << endl;

    return 0;
}