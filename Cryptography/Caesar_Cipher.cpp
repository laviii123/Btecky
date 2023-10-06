// Description: A simple substitution cipher that shifts characters in the plaintext by a fixed number.
//Linkedin:-https://www.linkedin.com/in/abhishek-mishra-016b75218/
#include <iostream>
#include <string>
using namespace std;

string caesar_cipher(string text, int shift) {
    string encrypted_text = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        encrypted_text += c;
    }
    return encrypted_text;
}

int main() {
    string plaintext = "Hello, World!";
    int shift = 3;
    string ciphertext = caesar_cipher(plaintext, shift);
    cout << "Encrypted: " << ciphertext << endl;
    return 0;
}
