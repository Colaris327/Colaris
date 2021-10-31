max = None
print('Before:', max)
for i in [9, 41, 12, 3, 74, 15] :
    if max == None :
        max = i
    elif i > max :
        max = i
    print(i)
print('After:', max)