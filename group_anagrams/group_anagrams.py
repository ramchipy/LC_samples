from collections import defaultdict

def group_anagrams(words):
    anagrams = defaultdict(list)
    for word in words:        
        lst = tuple(sorted(word))
        anagrams[lst].append(word)
    
    return [val for item, val in anagrams.items()]

for words in [["eat","tea","tan","ate","nat","bat"], ["arc", "car", "inch", "chin", "dog"]]:
    print("Anagrams for {}: {}".format(words, group_anagrams(words)))


