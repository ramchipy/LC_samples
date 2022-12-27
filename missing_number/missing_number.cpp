#include <vector>
#include <numeric>
#include <iostream>
#include <boost/format.hpp>
#include "../utility/vectors.hpp"

int missing_number(std::vector<int>& vec)
{
    return ((vec.size() * (vec.size()+1)/2)) - std::accumulate(begin(vec), end(vec), 0);
}



int main(void)
{
    for(auto& vec: std::vector<std::vector<int>>{ {3,0,1}, {0,1}, {9,6,4,2,3,5,7,0,1}})
    {
        std::cout<<(boost::format("%d is missing in [%s]\n") % missing_number(vec) % join(vec, ",")).str();
    }
}