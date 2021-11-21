import pandas as pd

# data = pd.Series([30, 15, 20])
# condition = data > 18
# print(condition)
# filteredData = data[condition]
# print(filteredData)

# data = pd.Series(["你好", "Python", "Pandas"])
# condition = data.str.contains("P")
# print(condition)
# filteredData = data[condition]
# print(filteredData)

data = pd.DataFrame({
    "name":["Amy", "Bob", "Charles"],
    "salary":[30000, 50000, 40000]
})
print(data)
print("======================")
condition = data["salary"] > 35000
filteredData = data[condition]
print(filteredData)