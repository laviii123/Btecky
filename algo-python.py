def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


result = gcd(56, 48)
print(f"The GCD is: {result}")
