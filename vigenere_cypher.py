import string

def cipher_encrypt(plaintext, key):
    key = key.lower()
    encrypted_text = []
    key_index = 0

    for char in plaintext:
        if char.isalpha():
            shift = ord(key[key_index % len(key)]) - ord('a')
            if char.isupper():
                base = ord('A')
            else:
                base = ord('a')
            encrypted_char = chr((ord(char) - base + shift) % 26 + base)
            encrypted_text.append(encrypted_char)
            key_index += 1
        else:
            encrypted_text.append(char)

    return ''.join(encrypted_text)

def cipher_decrypt(ciphertext, key):
    key = key.lower()
    decrypted_text = []
    key_index = 0

    for char in ciphertext:
        if char.isalpha():
            shift = ord(key[key_index % len(key)]) - ord('a')
            if char.isupper():
                base = ord('A')
            else:
                base = ord('a')
            decrypted_char = chr((ord(char) - base - shift) % 26 + base)
            decrypted_text.append(decrypted_char)
            key_index += 1
        else:
            decrypted_text.append(char)

    return ''.join(decrypted_text)

plaintext = str(input("type message"))
key = str(input("give appropriate key to process"))

encrypted_text = cipher_encrypt(plaintext, key)
decrypted_text = cipher_decrypt(encrypted_text, key)
print("Cipher Encrypted:", encrypted_text)
print("Cipher Decrypted:", decrypted_text)