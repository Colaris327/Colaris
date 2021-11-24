from multiprocessing import Queue, Process
import time
import random

# https://github.com/jackfrued/Python-100-Days/blob/master/Day01-15/13.%E8%BF%9B%E7%A8%8B%E5%92%8C%E7%BA%BF%E7%A8%8B.md

def task_handler(curr_list, result_queue):
    total = 0
    for number in curr_list:
        total += number
    result_queue.put(total)

def main():
    # Method 1 : 直接從 1 加到 10000000
    total = 0
    number_list = [x for x in range(1, 10000001)]
    start = time.perf_counter()
    for number in number_list:
        total += number
    print(total)
    end = time.perf_counter()
    print('Execution time of Method 1 : %.3fs' % (end - start))

    # Method 2 : 切成八個部分再相加
    result_queue = Queue()
    num_list = [x for x in range(1, 10000001)]
    processes = []
    index = 0
    for _ in range(8):
        p = Process(target=task_handler, args=(num_list[index:index + 1250000], result_queue))
        processes.append(p)
        p.start()
        index += 1250000

    start = time.perf_counter()
    for p in processes:
        p.join()

    total = 0
    while not result_queue.empty():
        total += result_queue.get()

    print(total)
    end = time.perf_counter()
    print('Execution time of Method 2 : %.3fs' % (end - start))

if __name__ == '__main__':
    main()