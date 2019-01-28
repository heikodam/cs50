from nltk.tokenize import sent_tokenize

def compare(alist, blist, same):
        for i in alist:
            for h in blist:
                if i == h:
                    if i not in same:
                        same.append(i)
        return same

def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    alist = []
    blist = []

    def findNext(s, l):
        l.append(s[:s.find("\n")])
        return s[s.find("\n")+1:], l

    while a.find("\n") != -1 :
        a, alist = findNext(a, alist)
    alist.append(a)

    while b.find("\n") != -1 :
        b, blist = findNext(b, blist)
    blist.append(b)


    #compare
    same = []

    for i in alist:
        for h in blist:
            if i == h:
                if i not in same:
                    same.append(i)

    return same


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    alist = sent_tokenize(a)
    blist = sent_tokenize(b)


    same = []
    same = compare(alist, blist, same)

    return same


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    alist = []
    blist = []
    same = []

    def seperate(s, n, l):
        for i in range(len(s)- n + 1):
            l.append(s[i:i + n])
        return l


    alist = seperate(a, n, alist)
    blist = seperate(b, n, blist)

    print(alist)
    print(blist)

    same = compare(alist, blist, same)
    return same
