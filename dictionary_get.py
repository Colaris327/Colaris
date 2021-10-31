# if name in counts:
#     x = counts[name]
# else:
#     x = 0

#x = counts.get(name, 0)

#these two have same meaning



counts = dict()
names = ['csev', 'cwen', 'csev', 'zqian', 'cwen']
for name in names:
    counts[name] = counts.get(name, 0) + 1
print(counts)
