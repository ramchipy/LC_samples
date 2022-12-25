#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "../utility/measure.hpp"
#include "../utility/vectors.hpp"

static int binary_search(std::vector<int>& vec, int val)
{
    int left = 0;
    int right = vec.size()-1;
    int mid = 0;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if (vec[mid] == val)
        {
            return mid;
        }
        if (vec[mid] < val)
        {
            left = mid + 1;            
        }
        else if (vec[mid] > val)
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    int size = 1000;    
    if (argc == 2)
    {
        size = std::strtoul(argv[1], nullptr, 10);
    }
    std::vector<int> v = get_vector(size, 100);    
    std::sort(begin(v), end(v));
    
    int val = random() % 1000;
    perform_print_duration(std::string("Index of ")+std::to_string(val)+" :", binary_search, v, val);        
    
    return 0;       
}