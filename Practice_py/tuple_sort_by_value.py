c = {'a' : 10, 'b' : 1, 'c' : 22}
d = list()
for k,v in c.items():
    d.append((v, k))
print(d)

d = sorted(d, reverse=True)
print(d)