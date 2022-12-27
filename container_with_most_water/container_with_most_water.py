from datetime import datetime
import random

def with_most_water_brute_force(arr):
    max_area = 0
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            distance = j-i
            height = min(arr[i], arr[j])
            max_area = max(max_area, height*distance)
    return max_area

def with_most_water_two_pointers(arr):
    max_area = 0
    left = 0
    right = len(arr)-1
    while left<right:
        distance = right-left
        height = min(arr[left], arr[right])
        max_area = max(max_area, height*distance)
        if arr[left] < arr[right]:
            left += 1
        else:
            right -= 1
    return max_area



for arr in [[1,8,6,2,5,4,8,3,7], [1,1], [5,3,2,1,4], [5,9,2,1,4], [5,9,2,4]]:
    print("BF-Most water contained in {} is {}".format(arr, with_most_water_brute_force(arr)))
    print("TP-Most water contained in {} is {}".format(arr, with_most_water_two_pointers(arr)))

random.seed(1234)
arr = [random.randint(0, 99) for i in range(4000)]

start = datetime.now()
area = with_most_water_two_pointers(arr)
print("Total seconds 2 pointers : {}: area: {}".format((datetime.now()-start).total_seconds(), area))

start = datetime.now()
area = with_most_water_brute_force(arr)
print("Total seconds brute force: {}: area: {}".format((datetime.now()-start).total_seconds(), area))