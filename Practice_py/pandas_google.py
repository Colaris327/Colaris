import pandas as pd
data = pd.read_csv("googleplaystore.csv")
# print("資料數量", data.shape)
# print("資料欄位", data.columns)
# print("======================================")

# condition = data["Rating"] <= 5
# data = data[condition]
# print("平均數", data["Rating"].mean())
# print("中位數", data["Rating"].median())
# print("取得前一千位應用程式的平均", data["Rating"].nlargest(1000).mean())

# 分析資料 : 安裝數的統計數據
# data["Installs"] = pd.to_numeric(data["Installs"].str.replace("[,+]", "", regex=True).replace("Free", ""))
# print("平均數", data["Installs"].mean())
# condition = data["Installs"] > 100000
# print("安裝數量大於十萬的應用程式有幾個", data[condition].shape[0])

# 關鍵字搜尋應用程式名稱
keyword = input("請輸入關鍵字 : ")
condition = data["App"].str.contains(keyword, case=False)
print("含關鍵字的應用程式數量", data[condition].shape[0])