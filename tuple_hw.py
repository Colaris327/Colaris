name = input("Enter file:")
if len(name) < 1:
    name = "mbox-short.txt"
handle = open(name)
counts = dict()
for line in handle:
    if line.startswith('From'):
        words = line.split()
        if len(words) > 5:
            time = words[5].split(':')
            counts[time[0]] = counts.get(time[0], 0) + 1

imp = counts.items()
imp = sorted(imp)
for k,v in imp:
    print(k,v)