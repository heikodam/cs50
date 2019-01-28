a = "Helllo"
b = "Heallo"
n = 3

alist = []
blist = []
same = []

def seperate(s, n, l):
    for i in range(len(s)- n + 1):
        l.append(s[i:i + n])
    return l

def compare(alist, blist, same):
    for i in alist:
        for h in blist:
            if i == h:
                if i not in same:
                    same.append(i)
    return same


alist = seperate(a, n, alist)
blist = seperate(b, n, blist)

print(alist)
print(blist)

same = compare(alist, blist, same)

print(same)

















# from nltk.tokenize import sent_tokenize

# a = "Hello there. How are you! I am good."
# b = "Hello there. Whats up. How are you!"

# alist = sent_tokenize(a)
# blist = sent_tokenize(b)

# print(alist)
# print(blist)
# same = []


# def compare(alist, blist, same):
#     for i in alist:
#         for h in blist:
#             if i == h:
#                 if i not in same:
#                     same.append(i)
#     return same

# same = compare(alist, blist, same)

# print(same)





# a = "Hello there\nHow are you\n\nI am good\n\n\n"
# b = "Hello there\nWhats up\n\nHow are you"


# alist = []
# blist = []

# def findNext(s, l):
#     l.append(s[:s.find("\n")])
#     return s[s.find("\n")+1:], l

# while a.find("\n") != -1 :
#     a, alist = findNext(a, alist)
# alist.append(a)

# while b.find("\n") != -1 :
#     b, blist = findNext(b, blist)
# blist.append(b)

# print(alist)
# print(blist)

# #compare
# same = []

# for i in alist:
#     for h in blist:
#         if i == h:
#             if i not in same:
#                 same.append(i)

# print(same)


