// Description: A polyalphabetic substitution cipher that uses a keyword to encrypt text.
#include <iostream>
#include <string>
using namespace std;

string vigenere_cipher(string text, string key) {
    string encrypted_text = "";
    int key_len = key.length();
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char key_char = key[i % key_len];
            char base = islower(c) ? 'a' : 'A';
            int shift = tolower(key_char) - 'a';
            c = (c - base + shift) % 26 + base;
        }
        encrypted_text += c;
    }
    return encrypted_text;
}

int main() {
    string plaintext = "Hello, World!";
    string key = "KEY";
    string ciphertext = vigenere_cipher(plaintext, key);
    cout << "Encrypted: " << ciphertext << endl;
    return 0;
}
