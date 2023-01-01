def two_sum_brute_force(numbers, target):
    num_dict = {}
    for i, num1 in enumerate(numbers[:-1]):
        for j,num2 in enumerate(numbers[i+1:]):
            if num1 + num2 == target:
                return [i, i+1+j]

    

def two_sum(numbers, target):
    num_dict = {}
    for i, num in enumerate(numbers):
        remaining = target - num
        if remaining in num_dict.keys():
            if num_dict[remaining] != i:
                return [num_dict[remaining], i]
        num_dict[num] = i


for arr, target in [[[2, 7, 3, 5], 9], [[3, 2, 4], 6], [[3, 3], 6], [[2, 11, 7, 15], 26]]:
    print("BF  : [{}] adds up to {} in {}".format(two_sum_brute_force(arr, target), target, arr))
    print("HASH: [{}] adds up to {} in {}".format(two_sum(arr, target), target, arr))