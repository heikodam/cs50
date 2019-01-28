from cs50 import get_float

while True:
    userchange = get_float("Change owed: ")
    if userchange > 0:
        break

userchange = userchange * 100
newuserchange = userchange
coincount = 0
quarter = 25
dime = 10
nickel = 5
penny = 1
rest = 0


if newuserchange >= quarter :
    rest = newuserchange%quarter
    coincount += (newuserchange - rest)/quarter
    newuserchange = newuserchange - (((newuserchange - rest)/quarter)*quarter)

if newuserchange >= quarter:
    rest = newuserchange%dime
    coincount += (newuserchange - rest)/dime
    newuserchange = newuserchange - (((newuserchange - rest)/dime)*dime)

if newuserchange >= nickel:
    rest = newuserchange%nickel
    coincount += (newuserchange - rest)/nickel
    newuserchange = newuserchange - (((newuserchange - rest)/nickel)*nickel)

if newuserchange >= penny:
    rest = newuserchange%penny
    coincount += (newuserchange - rest)/penny
    newuserchange = newuserchange - (((newuserchange - rest)/penny)*penny)

print(coincount)