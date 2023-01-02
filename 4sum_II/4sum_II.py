from collections import defaultdict
def sums_brute_force(nums1, nums2, nums3, nums4):
    count = 0
    for i, val1 in enumerate(nums1):
        for j, val2 in enumerate(nums2):
            for k, val3 in enumerate(nums3):
                for l, val4 in enumerate(nums4):
                    if (val1 + val2 + val3 + val4) == 0:
                        print("{} => {}".format([i, j, k, l], [val1, val2, val3, val4]))
                        count += 1
    return count

def sums_optimal(nums1, nums2, nums3, nums4):
    first = defaultdict(list)
    for i, val1 in enumerate(nums1):
        for j, val2 in enumerate(nums2):
            first[val1+val2].append(tuple([i, j]))
    
    count = 0
    for i, val1 in enumerate(nums3):
        for j, val2 in enumerate(nums4):
            negative = -(val1 + val2)
            if len(first[negative]) > 0:
                for b1,b2 in first[negative]:
                    print("[{}, {}, {}, {}] => [{}, {}, {}, {}]".format(b1, b2, i, j, nums1[b1], nums2[b2], nums3[i], nums4[j]))
                count += len(first[negative])
            
    
    return count

count = sums_brute_force([1,2], [-2, -1], [-1, 2], [0,2])
print(count)
count = sums_optimal([1,2], [-2, -1], [-1, 2], [0,2])
print(count)    