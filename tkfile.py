import random
import string
import tkinter as tk
from tkinter import ttk

# Define lists of characters
lowercase_letters = list(string.ascii_lowercase)
uppercase_letters = list(string.ascii_uppercase)
digits = list(string.digits)
special_characters = list("!@#$%^&*()_-+=<>?")

# Combine all character sets
all_characters = lowercase_letters + uppercase_letters + digits + special_characters

# Function to generate a random password
def generate_password(length):
    if length < 4:
        result_label.config(text="Password length must be at least 4 characters.")
        return

    random.shuffle(lowercase_letters)
    random.shuffle(uppercase_letters)
    random.shuffle(digits)
    random.shuffle(special_characters)
    random.shuffle(all_characters)

    # Ensure at least one character from each category
    password = [
        random.choice(lowercase_letters),
        random.choice(uppercase_letters),
        random.choice(digits),
        random.choice(special_characters),
    ]

    # Generate the rest of the password
    password += random.choices(all_characters, k=length - 4)

    # Shuffle the password characters
    random.shuffle(password)

    result_label.config(text="Generated Password: " + "".join(password))

# Create a Tkinter window
root = tk.Tk()
root.title("Password Generator")

# Create and configure a frame
frame = ttk.Frame(root)
frame.grid(column=0, row=0, padx=10, pady=10)

# Label and Entry for password length
length_label = ttk.Label(frame, text="Password Length:")
length_label.grid(column=0, row=0)

length_entry = ttk.Entry(frame)
length_entry.grid(column=1, row=0)

# Generate button
generate_button = ttk.Button(frame, text="Generate Password", command=lambda: generate_password(int(length_entry.get())))
generate_button.grid(column=0, row=1, columnspan=2)

# Result label
result_label = ttk.Label(frame, text="")
result_label.grid(column=0, row=2, columnspan=2)

root.mainloop()
