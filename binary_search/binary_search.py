def binary_search(arr, elem):
    left = 0
    right = len(arr)-1
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == elem:
            return mid

        if arr[mid] < elem:
            left = mid+1            

        elif arr[mid] > elem:
            right = mid-1            
    return -1

start = 0
end = 7
for i in range(start -2, start + end+4):
    print("-----------------------")
    ndx = binary_search(list(range(start, end, 2)), i)
    if ndx != -1:
        print("{} is present at {}".format(i, ndx))
    else:
        print("{} is not present in the array".format(i))