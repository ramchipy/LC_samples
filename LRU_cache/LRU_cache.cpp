#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <iostream>

class LRU_cache{
public:
    explicit LRU_cache(int capacity): m_capacity(capacity){}
    int get(int key)
    {
        auto it = cache.find(key);
        if(it != cache.end())
        {
            int val = it->second;
            deq.erase(std::remove(begin(deq), end(deq), key), end(deq));
            deq.push_back(key);
            return val;
        }
        else
        {
            return  -1;
        }
    }

    void put(int key, int val)
    {
        auto it = cache.find(key);
        if(it != cache.end())
        {
            deq.erase(std::remove(begin(deq), end(deq), key), end(deq));
            deq.push_back(key);
            it->second = val;
        }
        else
        {
            if(deq.size() == m_capacity)
            {
                auto oldest = deq.front();
                deq.pop_front();
                cache.erase(oldest);
                
            }
            deq.push_back(key);
            cache[key] = val;
        }
    }
    
    void print(void)const
    {
        for(auto key: deq)
        {
            std::cout<<"["<<key<<","<<cache.at(key)<<"],";
        }
        std::cout<<"\n";
    }
private:
    std::deque<int> deq;
    std::unordered_map<int, int> cache;
    int m_capacity = 0;
};

int main(void)
{
    auto lru = LRU_cache(4);
    lru.put(1, 100);
    lru.put(2, 200);
    lru.get(1);
    lru.put(3, 300);
    lru.get(2);
    lru.print();
    lru.put(4, 400);
    lru.put(4, 400);
    lru.put(4, 400);
    lru.print();
    lru.get(7);
    lru.get(3);
    lru.put(5, 500);
    lru.print();
    lru.put(6, 600);
    lru.print();
    lru.get(3);
    lru.print();
}