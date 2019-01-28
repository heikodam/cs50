import sys
from cs50 import get_string

if len(sys.argv) == 2:
    k = int(sys.argv[1])
    p = get_string("plaintext: ");
    print("ciphertext: ", end="");

    for i in p:
        if i.isalpha:
            if i.isdigit():
                print(i, end="")
            if i.isupper():
                a = ord(i) - 65
                #print(f"       {a}")
                a += k
                a = a % 26
                a += 65
                print(chr(a), end="")
            elif i.islower():
                a = ord(i) - 97
                a += k
                a = a % 26
                a += 97
                print(chr(a), end="")
        else:
            print(i, end="")


else:
    print("You forgot to enter a key... Or you did something else wrong")


print()