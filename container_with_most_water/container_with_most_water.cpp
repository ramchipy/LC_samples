#include <stdint.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../utility/vectors.hpp"
#include "../utility/measure.hpp"

uint64_t with_most_water_brute_force(std::vector<size_t>& vec)
{
    uint64_t max_area = 0;
    for(size_t i=0; i<vec.size(); i++)
    {
        for(size_t j=i;j<vec.size(); j++)
        {
            auto width = j-i;
            auto height = std::min(vec[i], vec[j]);
            max_area = std::max(max_area, height*width);
        }
    }

    return max_area;
}

uint64_t with_most_water_two_pointers(std::vector<size_t>& vec)
{
    uint64_t max_area = 0;
    size_t left = 0;
    size_t right = vec.size()-1;
    
    while(left<right)
    {
        auto width = right-left;
        auto height = std::min(vec[left], vec[right]);
        max_area = std::max(max_area, width*height);

        if (vec[left] < vec[right])
        {
            left += 1;
        }
        else
        {
            right -= 1;
        }
    }

    return max_area;
}

int main(void)
{
    for(auto &vec: std::vector<std::vector<size_t>>{{1,8,6,2,5,4,8,3,7}, {1,1}, {5,3,2,1,4}, {5,9,2,1,4}, {5,9,2,4}})
    {
        std::cout<<"with_most_water_brute_force : "<<with_most_water_brute_force(vec)<<"\n";
        std::cout<<"with_most_water_two_pointers: "<<with_most_water_two_pointers(vec)<<"\n";
        
    }    
    auto vec = get_vector<size_t>(4000, 100);
    perform_print_duration("with_most_water_two_pointers: ", with_most_water_two_pointers, vec);
    perform_print_duration("with_most_water_brute_force : ", with_most_water_brute_force, vec);

    return 0;
}
