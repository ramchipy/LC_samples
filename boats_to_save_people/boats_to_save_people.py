from typing import List

def get_number_of_rescue_boats(arr, limit):
    arr_s = sorted(arr)
    start = 0
    end = len(arr_s)-1
    boats = 0    
    while start <= end:        
        people = []
        if start != end and arr_s[start] + arr_s[end] <= limit:
            people = [arr_s[start], arr_s[end]]
            start += 1
            end -=1
            boats += 1
        else:
            people = [arr_s[end]]
            end -=1
            boats += 1
        print("{} will go with boat {}".format(people, boats))
    return boats


for arr, limit in [ [[3, 2, 3, 1], 4], [[1,2,3,4], 4], [[3, 3, 3, 2], 4]]:
    boats = get_number_of_rescue_boats(arr, limit)
    print("{}:{} => boats: {}".format(arr, limit, boats))

