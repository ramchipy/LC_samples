from collections import defaultdict

def majority_element(arr):
    num_dict = defaultdict(int)
    for e in arr:
        num_dict[e] += 1
        if num_dict[e] > len(arr)//2:
            return e
    return None

def majority_element_optimal(arr):
    candidate = 0
    counter = 0
    for i in range(len(arr)):
        if counter == 0:
            candidate = arr[i]
        if arr[i] == candidate:
            counter += 1
        else:
            counter -= 1
    return candidate
            

for arr in [[3,1,3], [2,2,1,1,1,2,2]]:
    print("{} is the majority element in {}".format(majority_element(arr), arr))
    print("{} is the majority element in {}".format(majority_element_optimal(arr), arr))    