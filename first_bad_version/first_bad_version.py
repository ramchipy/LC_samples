def isBadVersion(version):
    print("version: {}".format(version))
    if version >= 13:
        return True
    return False

def get_first_bad_version(n):
    left = 1
    right = n
    last_bad_version = -1
    while left < right:
        mid = (left + right) // 2        
        if isBadVersion(mid):           
            right = mid
        else:
            left = mid + 1
    return left

for n in (128, 64, 32, 16, 28, 24, 26):
    print("First bad of {}: {}".format(n, get_first_bad_version(n)))
    print("===================================================")