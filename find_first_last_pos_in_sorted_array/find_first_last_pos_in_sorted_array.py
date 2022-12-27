def find_first_last_brute_force(arr, target):
    left = 0
    right = len(arr)-1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            mid_left = mid
            mid_right = mid
            while mid_left >= 1 and arr[mid_left-1]==target:
                mid_left -= 1
            while mid_right < len(arr)-1 and arr[mid_right+1]==target:
                mid_right += 1
            return [mid_left, mid_right]
        if arr[mid] > target:
            right = mid-1
        else:
            left = mid+1
    return [-1, -1]

def find_first_optimal(arr, target):
    left = 0
    right = len(arr)-1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            if mid == 0 or arr[mid-1] != target:
                return mid
            else:
                right = mid-1
        elif arr[mid] > target:
            right = mid-1
        else:
            left = mid+1
    return -1

def find_last_optimal(arr, target):
    left = 0
    right = len(arr)-1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            if mid == len(arr)-1 or arr[mid+1] != target:
                return mid
            else:
                left = mid+1
        elif arr[mid] > target:
            right = mid-1
        else:
            left = mid+1
    return -1

def find_first_last_optimal(arr, target):
    return [find_first_optimal(arr, target), find_last_optimal(arr, target)] 

for arr, target in [[[1,2,3,4], 2], [[1,2,2,3,4], 2], [[1,2,2,2,3,4], 2], [[1,2,2,3,4], 6], [[2,2,2,2,2], 2], [[2,2,2,2,3], 2]]:
    print("--------------------------------------")
    print("arr: {}, {} => {}".format(arr, target, find_first_last_brute_force(arr, target)))
    print("arr: {}, {} => {}".format(arr, target, find_first_last_optimal(arr, target)))    