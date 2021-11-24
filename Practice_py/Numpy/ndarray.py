import numpy as np

# # 建立一維陣列
# data = np.array([3, 2, 6, 4])
# print(data)
# data = np.empty(4) # 創建一個未指定的一維陣列
# print(data)
# data = np.zeros(3) # 創建一個全為 0 的一維陣列
# print(data)
# data = np.ones(3)
# print(data)
# data = np.arange(8)
# print(data)

# # 建立二維陣列
# data = np.array([
#     [2, 3, 2],
#     [1, 5, 2],
#     [4, 2, 1]
# ])
# print(data)
# data = np.empty([3, 3]) # 創造一個3*3的二維陣列，資料未指定
# print(data)
# data = np.ones([2, 3])
# print(data)

# 建立三維陣列
# data = np.array([ # 根據列表建立一個2*2*2的三維陣列
#     [
#         [3, 1], [1, 2]
#     ],
#     [
#         [2, 5], [10, 2]
#     ]
# ])
# print(data)
# data = np.zeros([3, 1, 3]) # 創造一個3*1*3的三維陣列
# print(data)

# 建立高維陣列
# data = np.array([ # 建立一個1*1*2*3的陣列
#     [
#         [
#             [3, 2, 1],
#             [5, 5, 10]
#         ]
#     ]
# ])
# print(data)
data = np.ones([2, 1, 1, 2]) # 建立一個全為0的四維陣列
print(data)