text = "X-DSPAM-Confidence:    0.8475"
num = text.find('0.8475')
str = text[num:]
ans = float(str)
print(ans)