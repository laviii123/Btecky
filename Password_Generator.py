#password generator
print("This is a Password Generator.")
print("")
word1 = str(input("Enter a random and common word: "))
word2 = str(input("Enter another random and common word with the same amount of letters: "))

len1 = len(word1)
len2 = len(word2)

if len2 > len1:
  num = len2 - 2
  duh = len2 - len1 - 1
  space = str(input("Enter a number: "))
  spaces = space
  while True:
    spaces = spaces + space
    duh -= 1
    if duh <= 0:
      break
  word1 = str(word1 + spaces)

  
elif len1 > len2:
  num = len1 - 2
  duh = len1 - len2 - 1
  space = str(input("Enter a number: "))
  spaces = space
  while True:
    spaces = space + spaces
    duh -= 1
    if duh <= 0:
      break
  word2 = str(word2 + spaces)
else:
  num = len1 - 2


password = word1[0] + word2[0]
count = 1

while True:

  password = password + word1[count] + word2[count]
  
  if num <= 0:
    print(password)
    break
    
  count += 1
  num -= 1