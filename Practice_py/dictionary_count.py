count = dict()
names = ['csev', 'cwen', 'csev', 'zqian', 'cwen']
for name in names:
    if name not in count:
        count[name] = 1
    else:
        count[name] += 1
print(count)