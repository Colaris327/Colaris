# 定義 geometry 模組
def distance(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def slope(x1, y1, x2, y2):
    return (y2 - y1) / (x2 - x1)