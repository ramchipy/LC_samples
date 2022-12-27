def missing_number(arr):
    n = len(arr)
    return ((n * (n+1)) //2) - sum(arr)

for arr in [ [3,0,1], [0,1], [9,6,4,2,3,5,7,0,1]]:
    print("{} is missing in {}".format(missing_number(arr), arr))

