import numpy as np

# 多維陣列的索引
# 單維度的資料
# data = np.array([1, 5, 2, 10])
# print(data[2])

# 多維度的資料
# data = np.array([
#     [0, 1],
#     [10, -5],
#     [2, 6]
# ])
# print(data[0, 1]) # 1
# print(data[1, 0]) # 10

# 多維陣列的切片 Slicing
# 單維度
# data = np.array([-1, -5, 2, 3])
# print(data[0:3]) # [-1, -5, 2]
# print(data[:2]) # [-1, -5]
# print(data[:]) # [-1, -5, 2, 3]

# 多維度的切片
# data = np.array([
#     [0, 1, 2], [3, 4, 5],
#     [5, 4, 3], [2, 1, 0]
# ])
# print(data[1:3, 0:2])
# print(data[0:2, 1])

# 使用 ... 代表全部
data = np.array([
    [
        [8, 1, 3],
        [-5, 5, 2]
    ],
    [
        [0, 1, 6],
        [4, 4, -3]
    ]
])
print(data[0, ...]) # [[8, 1, 3], [-5, 5, 2]]
print(data[..., 1:3]) # [[[1, 3], [5, 2]], [[1, 6], [4, -3]]]