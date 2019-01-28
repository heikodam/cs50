from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 0 and height < 25:
        break


hash = '#';
space = ' ';
current = 2;

for i in range(height):
    for j in range(height - current + 1):
        print(space, end="")
    for k in range(current):
        print(hash, end="")
    print()
    current += 1