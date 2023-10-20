import string
import random

def generate_substitution_key():
    alphabet = list(string.ascii_lowercase)
    random.shuffle(alphabet)
    return ''.join(alphabet)

def cipher_encrypt(text, key):
    alphabet = string.ascii_lowercase
    table = str.maketrans(alphabet, key)
    return text.translate(table)

def cipher_decrypt(text, key):
    alphabet = string.ascii_lowercase
    table = str.maketrans(key, alphabet)
    return text.translate(table)


plaintext = str(input("Enter text"))

substitution_key = generate_substitution_key()
encrypted_text = cipher_encrypt(plaintext, substitution_key)
decrypted_text = cipher_decrypt(encrypted_text, substitution_key)

print("Key:", substitution_key)
print("Cipher Encrypted:", encrypted_text)
print("Cipher Decrypted:", decrypted_text)