from collections import defaultdict
def get_single_number_brute_force(arr):
    for i in range(len(arr)):
        count = 0
        for j in range(len(arr)):
            if arr[i] == arr[j]:                
                count += 1
        if count == 1:            
            return arr[i]

def get_single_number1(arr):
    numbers = defaultdict(int)
    for i, val in enumerate(arr):
        numbers[val] += 1

    for i, val in numbers.items():
        if val == 1:
            return i

def get_single_number2(arr):
    numbers = [0] * 60001
    for i, val in enumerate(arr):
        ndx = val + 30000
        numbers[ndx] += 1

    for i, val in enumerate(numbers):
        if val == 1:
            return i-30000 

def get_single_number3(arr):
    return sum(set(arr))*2-sum(arr)

def get_single_number4(arr):
    numbers = set()
    once = 0
    for i, val in enumerate(arr):
        once = once ^ val

    return once

for arr in [[1,2,2,1,3], [1,2,2,1,3,3,5], [1,2,2,33,1,3,3,5,5]]:
    print("Brute force: There is only one instance of {} in {}".format(get_single_number_brute_force(arr), arr))
    print("Optimal 1  : There is only one instance of {} in {}".format(get_single_number1(arr), arr))
    print("Optimal 2  : There is only one instance of {} in {}".format(get_single_number2(arr), arr))
    print("Optimal 3  : There is only one instance of {} in {}".format(get_single_number3(arr), arr))
    print("Optimal 4  : There is only one instance of {} in {}".format(get_single_number4(arr), arr))
    print("=================================================")