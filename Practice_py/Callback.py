# def test(arg):
#     arg("Hello") # 呼叫回呼函式

# # 回呼函式
# def handle(a):
#     print(a)

# test(handle)


def add(n1, n2, cb):
    cb(n1 + n2)

def handle1(result):
    print("結果是", result)

def handle2(result):
    print("Result of add is:", result)

add(3, 4, handle1)
add(3, 4, handle2)