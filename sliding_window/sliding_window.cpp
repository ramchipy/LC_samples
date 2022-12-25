#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>
#include "../utility/measure.hpp"

static int64_t find_max_sum_of_K_brute_force(std::vector<int>& arr, const size_t window_size)
{
    int64_t max_sum = std::numeric_limits<int64_t>::infinity();
    for(size_t i=0; i<arr.size()-window_size; i++)
    {
        int64_t sum = std::accumulate(begin(arr)+i, begin(arr)+i+window_size, 0);
        max_sum = std::max(sum, max_sum);            
    }

    return max_sum;
}

static uint64_t find_max_sum_of_K_sliding_window(std::vector<int>& arr, const size_t window_size)
{
    int64_t sum = std::accumulate(begin(arr), begin(arr)+window_size, 0);
    auto max_sum = sum;
    for(int i=0; i<arr.size()-window_size; i++)
    {
        sum -= arr[i];
        sum += arr[i+window_size];
        max_sum = std::max(sum, max_sum);
    }

    return max_sum;
}

int main(void)
{
    std::vector<int> v(99999);
    constexpr size_t WINDOW_SIZE = 999;
    srand(12314);
    for(auto& e : v)
    {
        e = random() % 10000;        
    }

    perform_print_duration("max_br: ", find_max_sum_of_K_brute_force, v, WINDOW_SIZE);
    perform_print_duration("max_sw: ", find_max_sum_of_K_sliding_window, v, WINDOW_SIZE);

    return 0;
}