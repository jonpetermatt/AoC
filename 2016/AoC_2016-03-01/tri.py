import sys

counter = 0
lines = (sys.argv[1]).splitlines()
for line in range(len(lines)):
    data = lines[line].split()
    side0 = int(data[0])
    side1 = int(data[1])
    side2 = int(data[2])
    if (side0 + side1) > side2:
        if (side0 + side2) > side1:
            if (side1 + side2) > side0:
                counter = counter + 1

print(counter)
