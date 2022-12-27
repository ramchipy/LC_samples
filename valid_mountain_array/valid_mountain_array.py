def valid_mountain_array(arr):
    increasing = True
    if len(arr) < 3:
        return False
    for i in range(len(arr)-1):
        if arr[i] == arr[i+1]:
            return False
        if increasing:
            if arr[i]>arr[i+1]:
                if i == 0:
                    return False
                increasing = False
        else:
            if arr[i] < arr[i+1]:
                return False
    return not increasing

def valid_mountain_array2(arr):
    i = 1
    while (i < len(arr)) and (arr[i-1] < arr[i]):
        i += 1
    if i == 1 or i == len(arr):
        return False
    while(i < len(arr)) and arr[i-1] > arr[i]:
        i += 1     
    return i == len(arr)

for arr in [[2, 1],[3,5,5],[0,3,2,1],[1,2,3,2,1], [2, 3, 4, 5,4], []]:
    print("Is {} valid mountain array1: {}".format(arr, valid_mountain_array(arr)))
    print("Is {} valid mountain array2: {}".format(arr, valid_mountain_array2(arr)))
