# # 定義裝飾器
# def myDeco(callback):
#     def run():
#         print("裝飾器中的程式碼")
#         callback(5)
#     return run

# # 使用裝飾器
# @myDeco
# def test(n):
#     print("普通函式的程式碼", n)

# test()


# 定義一個裝飾器，計算 1+2+3+...+50 的總和
def cal(callback):
    def run():
        result = 0
        for n in range(51):
            result += n
        callback(result)
    return run

@cal
def show(n):
    print("結果是", n)

@cal
def showEng(n):
    print("Result is", n)

show()
showEng()