import sys


def root(value):
    if value < 7:
        return 0
    left = value % 3
    first = value - left
    second = first/3 - 2
    total = second + root(second)
    return total


number = str(sys.argv[1])
numbers = number.split("\n")

total = 0

for i in numbers:
    total += root(int(i))

print(total)
