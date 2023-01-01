#include <unordered_map>
#include <unordered_set>
#include <span>
#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/format.hpp>
#include "../utility/vectors.hpp"

bool contains_duplicate_brute_force(std::span<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            if(v[i] == v[j])
            {
                return true;
            }
        }
    }

    return false;
}

bool contains_duplicate_sort(std::span<int> v)
{
    std::sort(begin(v), end(v));
    for(int i=0; i<v.size()-1; i++)
    {
        if(v[i] == v[i+1])
        {
            return true;
        }
    }

    return false;
}

bool contains_duplicate_set(std::span<int> v)
{
    std::unordered_set<int> num_set;
    for(int i = 0; i<v.size(); i++)
    {
        if(num_set.contains(v[i]))
        {
            return true;
        }
        num_set.insert(v[i]);
    }

    return false;
}

int main()
{
    for(auto& v: std::vector<std::vector<int>>{{1,2,3,1}, {3,2,4,5}})
    {
        std::cout<<(boost::format("%s contains duplicate: %b\n") % join(v, ",") % contains_duplicate_brute_force(v)).str();
        std::cout<<(boost::format("%s contains duplicate: %b\n") % join(v, ",") % contains_duplicate_sort(v)).str();        
        std::cout<<(boost::format("%s contains duplicate: %b\n") % join(v, ",") % contains_duplicate_set(v)).str();
        std::cout<<("==============================================\n");
    }
}