from datetime import datetime

def longest_substring_brute_force(str):
    longest = 0
    longest_found = []
    for i in range(len(str)):
        found = list()
        for ch in str[i:]:
            if ch in found:                                
                break
            else:
                found.append(ch)
            if len(found) > longest:
                longest = len(found)
                longest_found = found[:]
    print("longest: {}".format("".join(longest_found)))
    return longest


def longest_substring_str(str):
    longest = 0
    start = 0
    end = 0
    longest_str = ""
    for i,ch in enumerate(str):
        ndx = str[start:end].find(ch)
        if ndx != -1:
            start += ndx + 1
        end += 1
        if (end-start) > longest:
            longest = end-start
            longest_str = str[start:end]    
    print("longest: {}".format(longest_str))
    return longest

def longest_substring_table(str):    
    longest = 0
    start = 0
    longest_str = ""
    start = 0
    i = 0
    ASCII = list([-1 for i in range(128)])
    for i, ch in enumerate(str):
        val = ord(ch)
        if ASCII[val] >= start:
            start = ASCII[val]+1
        ASCII[val] = i
        if longest < (i-start+1):
            longest = i-start+1
            longest_str = str[start:i+1]

    print("longest: {}".format(longest_str))
    return longest

def longest_substring_map(str):
    longest = 0
    start = 0
    longest_str = ""
    found = {}
    for i,ch in enumerate(str):
        if ch in found and found[ch] >= start:
            start = found[ch]+1                        
        found[ch] = i        
        if longest < (i-start+1):
            longest = i-start+1
            longest_str = str[start:i+1]
    print("longest: {}".format(longest_str))
    return longest

for str in ["", "abcbda", "abcabcbd", "aaaaaaaaaa", "0123456701234567890", "012345670123456789001234567012345678900123456701234567890" * 50000]:
    print("{:5}: --------------------------------------".format(len(str)))
    '''
    if len(str) > 20:
        continue
    print(str)
    '''
    
    start = datetime.now()
    print("Brute force: {}".format(longest_substring_brute_force(str)))
    print("Brute force seconds: {}".format((datetime.now()-start).total_seconds()))
    
    start = datetime.now()
    print("Search str:  {}".format(longest_substring_str(str)))
    print("Search str seconds:  {}".format((datetime.now()-start).total_seconds()))

    start = datetime.now()
    print("ASCII table: {}".format(longest_substring_table(str)))
    print("ASCII table seconds: {}".format((datetime.now()-start).total_seconds()))

    start = datetime.now()
    print("Index map:   {}".format(longest_substring_map(str)))
    print("Index map seconds:   {}".format((datetime.now()-start).total_seconds()))