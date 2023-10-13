def is_even(num):
    return num % 2 == 0
  
number = int(input("Enter a number: "))
result = is_even(number)
print(f"Is the number {number} even ?: {result}")
