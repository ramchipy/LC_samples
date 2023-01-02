#include <vector>
#include <span>
#include <unordered_map>
#include <iostream>
#include <boost/format.hpp>
#include "../utility/vectors.hpp"

int majority_element_map(std::span<int> v)
{
    std::unordered_map<int, int> num_seen;
    for(int i=0; i<v.size(); i++)
    {
        num_seen[v[i]] += 1;        
        if (num_seen[v[i]] > (v.size()/2))
        {
            return v[i];
        }        
    }

    return -1;
}

int majority_element_optimal(std::span<int> v)
{
    int candidate = 0;
    int counter = 0;
    for(int i=0; i<v.size(); i++)
    {
        if (counter == 0)
        {
            candidate = v[i];
        }
        if (v[i] == candidate)
        {
            counter += 1;
        }
        else
        {
            counter -= 1;
        }
    }

    return candidate;
}

int main(void)
{
    for(auto& v: std::vector<std::vector<int>>{{2,2,1,1,1,2,2}, {3,1,3}})
    {
        std::cout<<(boost::format("%d is the majority in %s\n") % majority_element_map(v) %join(v, ",")).str();        
        std::cout<<(boost::format("%d is the majority in %s\n") % majority_element_optimal(v) %join(v, ",")).str();
        std::cout<<"=====================================\n";
    }
    return 0;
}