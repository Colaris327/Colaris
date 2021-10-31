##open the file named word.txt
fname = input("Enter file name: ")

try:
    fh = open(fname)
except:
    print('Not a file')
    quit()

for line in inp:
    line = line.strip()
    line = line.upper()
    print(line)