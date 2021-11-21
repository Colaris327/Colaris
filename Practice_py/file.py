#儲存檔案
# file = open("data1.txt", mode = "w", encoding = "utf-8")
# file.write("Hello file\nSecond\n測試中文")
# file.close()
# with open("data1.txt", mode = "w", encoding = "utf-8") as file:
#     file.write("5\n3")

#讀取檔案
# sum = 0
# with open("data1.txt", mode = "r", encoding = "utf-8") as file:
#     for line in file:
#         sum += int(line)
# print(sum)

#使用JSON格式讀取
import json
with open("config.json", mode = "r") as file:
    data = json.load(file)
print(data)
#print("name : ", data["name"])
#print("version : ", data["version"])
data["name"] = "Newname"
with open("config.json", mode = "w") as file:
    json.dump(data, file)