import sys

number = str(sys.argv[1])
numbers = number.split("\n")

total = 0

for i in numbers:
    left = int(i) % 3
    value = int(i) - left
    final = value/3 - 2
    total += final

print(total)
