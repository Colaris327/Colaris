# File 實體物件的設計 : 包裝讀取檔案讀取的程式
class File:
    def __init__(self, name):
        self.name = name
        self.file = None
    
    def open(self):
        self.file = open(self.name, mode="r", encoding="utf-8")

    def read(self):
        return self.file.read()

f1 = File("data1.txt")
f1.open()
data = f1.read()
print(data)