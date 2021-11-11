fname = input("Enter file name: ")
fh = open(fname)
lst = list()
for line in fh:
    words = line.split()
    for i in range(len(words)):
        lst.append(words[i])
lst = sorted(set(lst))
print(lst)
lst.reverse()
print(lst)