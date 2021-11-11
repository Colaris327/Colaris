score = input("Enter Score: ")
try :
    sc = float(score)
except :
    print('error')
    quit()
if sc > 1 :
    print('score should be less than 1.0')
    quit()
elif sc >= 0.9 :
    print('A')
elif sc >= 0.8:
    print('B')
elif sc >= 0.7:
    print('C')
elif sc >= 0.6:
    print('D')
else :
    print('F')