import requests
import time
import concurrent.futures

img_urls = [
    'https://images.unsplash.com/photo-1637649228998-6c78a67dfa6c',
    'https://images.unsplash.com/photo-1593642532400-2682810df593',
    'https://images.unsplash.com/photo-1637598094913-7e24488a4dfa',
    'https://images.unsplash.com/photo-1637248761448-a3b0733a304d',
    'https://images.unsplash.com/photo-1637580981009-c13f27517703'
]

start = time.perf_counter()

def img_download(img_url):
    img_bytes = requests.get(img_url).content
    img_name = img_url.split('/')[3]
    img_name = img_name + '.jpg'
    with open(img_name, 'wb') as img_file: # wb : 寫入二進位檔案
        img_file.write(img_bytes)
        print(f'{img_name} is downloading...')

with concurrent.futures.ThreadPoolExecutor() as executor:
    executor.map(img_download, img_urls)



finish = time.perf_counter()
print(f'Finished in {round(finish - start, 2)} second(s).')

