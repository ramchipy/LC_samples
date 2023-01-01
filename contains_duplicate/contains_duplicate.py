def contains_duplicate(arr):
    arr_set = set(arr)
    return len(arr_set) < len(arr)

for arr in [[1,2,3,1], [3,2,4,5]]:
    print("{} contains duplicate: {}".format(arr, contains_duplicate(arr)))
