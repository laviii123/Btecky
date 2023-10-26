import random

def number_guessing_game():
    print("Welcome to the Number Guessing Game!")

    # Get the range from the user
    lower_limit = int(input("Enter the lower limit of the range: "))
    upper_limit = int(input("Enter the upper limit of the range: "))

    # Generate a random number within the asked range
    secret_number = random.randint(lower_limit, upper_limit)

    attempts = 0
    guessed_number = None
    # print(guessed_number)

    while guessed_number != secret_number:
        guessed_number = int(input(f"Guess the number between {lower_limit} and {upper_limit}: "))
        attempts += 1

        if (guessed_number < secret_number):
            print("Low. Try again.")
        elif (guessed_number > secret_number):
            print("High. Try again.")
        else:
            print(f"Congratulations! You guessed the number {secret_number} in {attempts} attempts.")

# if __name__ == "__main__":
number_guessing_game()
