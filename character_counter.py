import re
test_str = "ThisIsTestString"
count = len(re.findall("i", test_str))
print("Count of i in ThisIsTestString" is : " + str(count))
