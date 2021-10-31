#open the file named mbox-short.txt
fname = input("Enter file name: ")
fh = open(fname)
su = 0
count = 0
for line in fh:
    if not line.startswith("X-DSPAM-Confidence:"):
        continue
    count = count + 1
    num = len(line)
    a = line[num - 7:num - 1]
    su = su + float(a)
    #print(line)
#print("Done")
print('Average spam confidence:', su / count)