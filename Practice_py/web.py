#獲取PTT LOL版
import urllib.request as req
url = "https://www.ptt.cc/bbs/LoL/index.html"

#建立Request物件 附加Request Header的資訊
request = req.Request(url, headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36 Edg/95.0.1020.53"
})
with req.urlopen(request) as response:
    data = response.read().decode("utf-8")
#print(data)

#解析原始碼
import bs4
root = bs4.BeautifulSoup(data, "html.parser")
titles = root.find_all("div", class_="title") #尋找 class="title" 的 div 標籤
with open("LOL.txt", "a", encoding="utf-8") as file:
    for title in titles:
        if title.a != None:
            print(title.a.string)
            file.write(title.a.string + "\n")
