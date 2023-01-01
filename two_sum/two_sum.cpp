#include <unordered_map>
#include <span>
#include <utility>
#include <vector>
#include <boost/format.hpp>
#include <iostream>
#include "../utility/vectors.hpp"

std::pair<int, int> two_sums_brute_force(std::span<int> v, int target)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            if(v[i]+v[j] == target)
            {
                return std::make_pair(i, j);
            }
        }
    }

    return std::make_pair(-1, -1);
}

std::pair<int, int> two_sums(std::span<int> v, int target)
{
    std::unordered_map<int, int> num_dict;
    for(int i=0; i<v.size(); i++)
    {
        int remaining = target - v[i];
        if(auto it = num_dict.find(remaining); it != num_dict.end())
        {
            return std::make_pair(it->second, i);
        }
        num_dict[v[i]] = i;
    }

    return std::make_pair(-1, -1);
}

int main()
{
    for(auto& [arr, target]: std::vector<std::pair<std::vector<int>, int>>{ {{1,2,3},3}, {{2, 7, 3, 5}, 9}, {{3, 2, 4}, 6}, {{3, 3}, 6}, {{2, 11, 7, 15}, 26} })
    {
        auto res = two_sums_brute_force(arr, target);
        std::cout<<(boost::format("[%d, %d] in [%12s] adds up to %d\n") % res.first % res.second % join(arr, ",") % target).str();
        res = two_sums(arr, target);
        std::cout<<(boost::format("[%d, %d] in [%12s] adds up to %d\n") % res.first % res.second % join(arr, ",") % target).str();
        std::cout<<"===============================================\n";
    }
    return 0;
}