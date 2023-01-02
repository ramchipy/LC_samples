#include <span>
#include <iostream>
#include <vector>
#include <unordered_map>

int sums_brute_force(const std::vector<int>& nums1, const std::vector<int>& nums2, const std::vector<int>& nums3, const std::vector<int>& nums4)
{
    int count = 0;
    for(auto n1: nums1)
    {
        for(auto n2: nums2)
        {
            for(auto n3: nums3)
            {
                for(auto n4: nums4)
                {
                    if((n1+n2+n3+n4) == 0)
                    {
                        count += 1;
                    }
                }
            }
        }    
    }

    return count;
}

int sums_optimal(const std::vector<int>& nums1, const std::vector<int>& nums2, const std::vector<int>& nums3, const std::vector<int>& nums4)
{
    std::unordered_map<int, int> first;
    for(auto n1: nums1)
    {
        for(auto n2: nums2)
        {
            first[n1+n2] += 1;
        }
    }

    int count = 0;
    for(auto n3: nums3)
    {
        for(auto n4: nums4)
        {
            int negate = -(n3+n4);
            if (auto it=first.find(negate); it != first.end())
            {
                count += it->second;
            }
        }
    }

    return count;
}

int main(void)
{
    auto count = sums_brute_force(std::vector{1,2}, std::vector{-2, -1}, std::vector{-1, 2}, std::vector{0, 2});
    std::cout<<count<<"\n";

    count = sums_optimal(std::vector{1,2}, std::vector{-2, -1}, std::vector{-1, 2}, std::vector{0, 2});
    std::cout<<count<<"\n";
    return 0;
}