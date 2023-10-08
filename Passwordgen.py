import random
import string

def generate_password(length=12):
    # Define character sets for password generation
    lowercase_letters = string.ascii_lowercase
    uppercase_letters = string.ascii_uppercase
    digits = string.digits
    special_characters = '!@#$%^&*()_+-=[]{}|;:,.<>?'

    # Create a pool of characters
    all_characters = lowercase_letters + uppercase_letters + digits + special_characters

    # Generate a password with random characters
    password = ''.join(random.choice(all_characters) for _ in range(length))
    
    return password

if __name__ == "__main__":
    password_length = int(input("Enter the desired password length: "))
    if password_length < 8:
        print("Password length should be at least 8 characters for security.")
    else:
        generated_password = generate_password(password_length)
        print("Generated Password:", generated_password)
