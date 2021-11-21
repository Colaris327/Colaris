#獲取PTT 八卦版
import urllib.request as req

def getData(url):
    #建立Request物件 附加Request Header的資訊
    request = req.Request(url, headers={
        "cookie":"over18=1",
        "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36 Edg/95.0.1020.53"
    })
    with req.urlopen(request) as response:
        data = response.read().decode("utf-8")
    #print(data)

    #解析原始碼
    import bs4
    root = bs4.BeautifulSoup(data, "html.parser")
    titles = root.find_all("div", class_="title") #尋找 class="title" 的 div 標籤
    with open("Gossip.txt", "a", encoding="utf-8") as file:
        for title in titles:
            if title.a != None:
                file.write(title.a.string + "\n")
                print(title.a.string)

    # 獲取上一頁的連結
    nextLink = root.find("a", string="‹ 上頁") # 找到內文是 ‹ 上頁 的 a 標籤
    return nextLink["href"]

# 抓取一個頁面的標題
pageURL = "https://www.ptt.cc/bbs/Gossiping/index.html"
count = 0
while count < 10:
    pageURL = "https://www.ptt.cc" + getData(pageURL)
    count += 1