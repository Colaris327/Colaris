import pandas as pd

# 資料索引
data = pd.DataFrame({
    "name":["Amy", "Bob", "Charles"],
    "salary":[30000, 50000, 40000]
}, index=["a", "b", "c"])
# print(data)
# print("=================")

# 觀察資料
# print("資料數量", data.size)
# print("資料形狀(列,欄)", data.shape)
# print("資料索引", data.index)

# 取得列
# print("取得第二列\n", data.iloc[1])
# print("=================")
# print("取得第 c 列\n", data.loc["c"])

# 取得欄
# print("取得 name 欄位", data["name"], sep="\n")
# names = data["name"] # 取得單維度的 Series 資料
# print("把 name 全部轉成大寫", names.str.upper(), sep="\n")
# 計算薪水平均值
# salaries = data["salary"]
# print("薪水的平均值", salaries.mean())
data["revenue"] = [500000, 400000, 300000]
data["rank"] = pd.Series([3, 6, 1], index=["a", "b", "c"])
data["cp"] = data["revenue"] / data["salary"]
print(data)