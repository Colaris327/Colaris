sum = 0.0
num = 0
while True :
    sval = input('Enter a number: ')
    if sval == 'done' :
        break
    try:
        fval = float(sval)
    except:
        print('Invalid number')
        continue
    num = num + 1
    sum = sum + fval
print(sum, num, sum / num)