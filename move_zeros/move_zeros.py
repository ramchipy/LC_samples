import random
from datetime import datetime

def move_zeros_with_space(arr):
    zero_cnt = 0
    while(True):
        try:
            ndx = arr.index(0)
            arr.pop(ndx)
            zero_cnt += 1
        except:        
            for i in range(zero_cnt):
                arr.append(0)
            break

def move_zeros_brute_force(arr):
    next_zero = len(arr)-1
    for i in range(len(arr)):
        if i >= next_zero:
            break
        if arr[i] == 0:
            for j in range(i, next_zero):
                arr[j] = arr[j+1]
            arr[next_zero] = 0
            next_zero -= 1

def move_zeros_efficient(arr):
    non_zero_ndx = 0    
    for i in range(len(arr)):
        if arr[i] != 0:
            arr[non_zero_ndx] = arr[i]
            non_zero_ndx += 1
    for k in range(non_zero_ndx, len(arr)):
        arr[k] = 0
        

random.seed(1234)
arr = [random.randint(0, 1000) for i in range(20000)]
start = datetime.now()
move_zeros_with_space(arr)
print("Total seconds space: {}".format((datetime.now()-start).total_seconds()))

random.seed(1234)
arr = [random.randint(0, 1000) for i in range(20000)]
start = datetime.now()
move_zeros_brute_force(arr)
print("Total seconds brute: {}".format((datetime.now()-start).total_seconds()))

random.seed(1234)
arr = [random.randint(0, 1000) for i in range(20000)]
start = datetime.now()
move_zeros_efficient(arr)
print("Total seconds effic: {}".format((datetime.now()-start).total_seconds()))