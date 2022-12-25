import random
from datetime import datetime

def find_max_sum_of_K_brute_force(arr, K):
    max_sum = float('-inf')
    for i in range(len(arr)-K+1):
        current_sum = sum(arr[i:i+K])            
        max_sum = max(current_sum, max_sum)            
    return max_sum

def find_max_sum_of_K_sliding_window(arr, K):
    current_sum = sum(arr[0:K])
    
    max_sum = current_sum
    for i in range(1, len(arr)-K+1):
        current_sum -= arr[i-1]
        current_sum += arr[i-1 + K]
        max_sum = max(current_sum, max_sum)            
    return max_sum
        

arr = random.sample(range(0, 100000), 99999)
K = 999
start = datetime.now()
max_br = find_max_sum_of_K_brute_force(arr, K)
print("max_br: {} ({})".format(max_br, (datetime.now()-start).total_seconds()))

start = datetime.now()
max_sw = find_max_sum_of_K_sliding_window(arr, K)
print("max_sw: {} ({})".format(max_sw, (datetime.now()-start).total_seconds()))