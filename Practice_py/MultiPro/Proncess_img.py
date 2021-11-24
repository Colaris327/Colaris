import time
import concurrent.futures
from PIL import Image, ImageFilter


img_names = [
        'photo-1593642532400-2682810df593.jpg',
        'photo-1637248761448-a3b0733a304d.jpg',
        'photo-1637580981009-c13f27517703.jpg',
        'photo-1637598094913-7e24488a4dfa.jpg',
        'photo-1637649228998-6c78a67dfa6c.jpg'
]

t1 = time.perf_counter()

size = (1200, 1200)

def process_image(img_name):
    img = Image.open(img_name)

    img = img.filter(ImageFilter.GaussianBlur(15))

    img.thumbnail(size)
    img.save(f'processed/{img_name}')
    print(f'{img_name} was processed...')

def main(): # 如果用ProcessPoolExecutor 記得放在 def main() 裡面
    with concurrent.futures.ProcessPoolExecutor() as executor: 
        executor.map(process_image, img_names)

    t2 = time.perf_counter()

    print(f'Finished in {t2-t1} seconds')

if __name__ == '__main__':
    main()