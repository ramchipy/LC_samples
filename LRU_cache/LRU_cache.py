from collections import deque

class LRU_cache():
    def __init__(self, capacity) -> None:
        self.capacity = capacity 
        self.cache = deque()
        self.keyToValue = {}

    def get(self, key):
        if key not in self.keyToValue.keys():
            return -1

        self.cache.remove(key)
        self.cache.append(key)
        return self.keyToValue[key]
        
    def put(self, key, val):
        if key not in self.keyToValue.keys():
            if len(self.cache) == self.capacity:
                oldest = self.cache.popleft()
                self.keyToValue.pop(oldest)
        else:
            self.cache.remove(key)
        
        self.cache.append(key)
        self.keyToValue[key] = val

    def print(self):
        print( ",".join(["[{},{}]".format(k, self.keyToValue[k]) for k in self.cache ]) )

    
lru = LRU_cache(4)
lru.put(1, 100)
lru.put(2, 200)
lru.get(1)
lru.put(3, 300)
lru.get(2)
lru.print()
lru.put(4, 400)
lru.put(4, 400)
lru.put(4, 400)
lru.print()
lru.get(7)
lru.get(3)
lru.put(5, 500)
lru.print()
lru.put(6, 600)
lru.print()
lru.get(3)
lru.print()