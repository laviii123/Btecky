#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string GeneratePassword(int length, bool useUppercase, bool useNumbers, bool useSymbols) {
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numbers = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:',.<>?";

    string charset = lowercase;

    if (useUppercase)
        charset += uppercase;
    if (useNumbers)
        charset += numbers;
    if (useSymbols)
        charset += symbols;

    string password;
    int charsetSize = charset.size();

    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charsetSize;
        password += charset[randomIndex];
    }

    return password;
}

int main() {
    int length;
    bool useUppercase, useNumbers, useSymbols;

    cout << "Password Length: ";
    cin >> length;

    cout << "Include Uppercase Letters (1/0): ";
    cin >> useUppercase;

    cout << "Include Numbers (1/0): ";
    cin >> useNumbers;

    cout << "Include Symbols (1/0): ";
    cin >> useSymbols;

    string password = GeneratePassword(length, useUppercase, useNumbers, useSymbols);
    cout << "Generated Password: " << password << endl;

    return 0;
}

