# def myFactory(base):
#     def myDeco(cb):
#         def run():
#             print(base)
#             result = base * 2
#             cb(result)
#         return run
#     return myDeco

# @myFactory(3)
# def test(result):
#     print(result)

# test()


# 計算 1+2+3+..+max 的裝飾器
def calculateFactory(max):
    def calculate(callback):
        def run():
            sum = 0
            for n in range(max + 1):
                sum += n
            callback(sum)
        return run
    return calculate

@calculateFactory(100)
def test(sum):
    print("結果 :", sum)

@calculateFactory(100)
def testEng(sum):
    print("Result :", sum)

test()
testEng()

