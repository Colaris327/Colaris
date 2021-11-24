import numpy as np

# 逐元運算 (elementwise)
# data1 = np.array([3, 2, 10])
# data2 = np.array([1, 3, 6])
# result = data1 + data2
# print("加法", result)
# result = data1 * data2
# print("乘法", result)
# result = data1 > data2
# print("大於", result)
# result = data1 == data2
# print("是否相等", result)

# 矩陣運算(matrix)
# data1 = np.array([
#     [1, 3]
# ]) # 1*2
# data2 = np.array([
#     [2, -1, 3],
#     [-2, 4, 1]
# ]) # 2*3
# result = data1@data2 # result = data1.dot(data2) # 1*3 內積
# print("內積", result)
# result = np.outer(data1, data2) # 2*6 外積
# print("外積", result)

# 統計運算
data = np.array([
    [2, 1, 7],
    [5, 6, 3]
]) # 2*3
result = data.cumsum()
print(result)
result = data.cumsum(axis=0) # 針對欄做逐值累加
print(result)
# result = data.sum(axis=0) # 針對欄做總和 column (針對第一維度)
# print(result)
# result = data.sum(axis=1) # 針對列作總和 row (針對第二維度)
# print(result)
# result = data.max(axis=0)
# print(result)
# result = data.mean(axis=1)
# print(result)

# result = data.sum()
# print("總和", result)
# result = data.max()
# print("最大值", result)
# result = data.mean()
# print("平均數", result)
# result = data.std()
# print("標準差", result)