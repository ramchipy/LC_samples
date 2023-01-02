#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <span>
#include "../utility/vectors.hpp"

static std::vector<std::vector<std::string>> group_anagrams(std::span<std::string> words)
{
    std::unordered_map<std::string, std::vector<std::string>> anagrams;
    for(auto& word: words)
    {
        std::string sorted(word);
        std::sort(begin(sorted), end(sorted));
        anagrams[sorted].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    for(auto& [word, list]: anagrams)
    {
        result.push_back(list);
    }

    return result;
}

int main(void)
{
    for(auto& words: std::vector<std::vector<std::string>>{{"eat","tea","tan","ate","nat","bat" }, {"arc", "car", "inch", "chin", "dog"}})
    {
        std::cout<<join(words, ",")<<": \n";
        auto anagrams = group_anagrams(words);
        for(auto& list: anagrams)
        {
            std::cout<<join(list, ",")<<"\n";
        }
        std::cout<<"===================================\n";
    }

    return 0;
}
