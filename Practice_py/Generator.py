# # 定義生成器函式
# def test():
#     print("階段一")
#     yield 5
#     print("階段二")
#     yield 10

# # 呼叫並回傳生成器
# gen = test()

# # 搭配 for 迴圈使用
# for d in gen:
#     print(d)


def generateEven(max):
    number = 0
    while number <= max:
        yield number
        number += 2

even = generateEven(10)
for data in even:
    print(data)