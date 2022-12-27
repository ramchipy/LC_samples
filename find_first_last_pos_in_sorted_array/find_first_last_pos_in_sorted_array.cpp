#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <boost/format.hpp>
#include "../utility/measure.hpp"

static std::pair<int, int> find_first_last_brute_force(std::vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size()-1;
    while(left <= right)
    {
        auto mid = (left + right) / 2;
        if (vec[mid] == target)
        {
            auto mid_left = mid;
            while((mid_left > 0) && (vec[mid_left-1] == target))
            {
                mid_left -= 1;
            }
            auto mid_right = mid;
            while((mid_right < (vec.size()-1)) && (vec[mid_right+1] == target))
            {
                mid_right += 1;
            }

            return std::make_pair(mid_left, mid_right);
        }
        else if (vec[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return std::make_pair<int, int>(-1, -1);
}

static int first_optimal(std::vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size()-1;
    while(left <= right)
    {
        auto mid = (left + right)/2;
        if (vec[mid] == target)
        {
            if (mid == 0 || vec[mid-1] != target)
            {
                return mid;
            }
            right = mid - 1;
        }
        else if(vec[mid]>target)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return -1;
}

static int last_optimal(std::vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size()-1;
    while(left <= right)
    {
        auto mid = (left + right)/2;
        if (vec[mid] == target)
        {
            if ((mid == (vec.size()-1)) || (vec[mid+1] != target))
            {
                return mid;
            }
            left = mid + 1;
        }
        else if(vec[mid]>target)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return -1;
}

static std::pair<int, int> find_first_last_optimal(std::vector<int>& vec, int target)
{
    return std::make_pair(first_optimal(vec, target), last_optimal(vec, target));
}


int main(void)
{
    
    std::vector<std::pair<std::vector<int>, int>> vecs{ {{1,2,3,4}, 2}, {{1,2,2,3,4}, 2}, {{1,2,2,2,3,4}, 2}, {{1,2,2,2,3,4}, 6}, {{2,2,2,2,2}, 2}, {{2,2,2,2,3}, 2}};
    
    std::vector<int> v(200000);
    std::generate(begin(v), begin(v)+50000, [n=0]()mutable{return n++;});
    size_t len = 100000;
    std::generate(begin(v)+50000, begin(v)+50000+len, []()mutable{return 50000;});
    std::generate(begin(v)+50000+len, end(v), [n=50001]()mutable{return n++;});
    vecs.emplace_back(v, 50000);

    for(auto& [vec, target]: vecs)
    {
        {
            auto [left, right] = perform_print_duration("Brute force: ", find_first_last_brute_force, vec, target);
            std::cout<<(boost::format("[%d, %d]\n") % left % right).str();
        }
        {
            auto [left, right] = perform_print_duration("Brute force: ", find_first_last_optimal, vec, target);
            std::cout<<(boost::format("[%d, %d]\n") % left % right).str();
        }             
    }    
    return 0;
}
