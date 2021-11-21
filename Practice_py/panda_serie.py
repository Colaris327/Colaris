import pandas as pd

# data = pd.Series([5, 4, -2, 3, 7], index = ["a", "b", "c", "d", "e"])
# print(data)

# 觀察資料
# print("資料型態", data.dtype)
# print("資料數量", data.size)
# print("資料索引", data.index)

# 取得資料
# 根據順序
# print(data[2], data[0])
# 根據索引
# print(data["e"], data["d"])

# 數字運算
# print("最大值", data.max())
# print("總和", data.sum())
# print("標準差", data.std())
# print("中位數", data.median())
# print("最大的三個數\n", data.nlargest(3)) # data.nsmallest


data = pd.Series(["你好", "Python", "Pandas"])
# 字串運算
# print(data.str.lower()) # 全部變小寫
# print(data.str.len()) # 算出每個字串的長度
# print(data.str.cat(sep="-")) # 串起字串
# print(data.str.contains("P")) # 判斷每個字串是否包含 P
print(data.str.replace("你好", "Hello")) # 取代