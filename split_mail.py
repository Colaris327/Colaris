line = 'From Colaris@gmail.com Sun Oct 24 16:27:33 2021'
words = line.split()
print('Mail:', words[1])
piece = words[1].split('@')
print(piece)