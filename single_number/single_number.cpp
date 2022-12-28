#include <vector>
#include <iostream>
#include <set>
#include <numeric>
#include "../utility/measure.hpp"

static int get_single_number_brute_force(std::vector<int>& vec)
{
    for(auto n1: vec)
    {
        auto count = 0;
        for(auto n2: vec)
        {
            if (n1 == n2)
            {
                count += 1;
            }
        }
        if (count == 1)
        {
            return n1;
        }
    }

    return 0;
}

static int get_single_number_set(std::vector<int>& vec)
{
    std::set uniq(begin(vec), end(vec));
    return std::accumulate(begin(uniq), end(uniq), 0)*2-std::accumulate(begin(vec), end(vec), 0);    
}

static int get_single_number_xor(std::vector<int>& vec)
{
    int final = 0;
    for(auto v: vec)
    {
        final = final ^ v;        
    }

    return final;
}

int main(void)
{
    std::vector<std::vector<int>> vecs{ {1,2,3,3,2}, {5}, {1,2,3,3,2,1,5,5,10}};
    
    int half = 10000;
    std::vector<int> v(half*2+1);    
    std::generate(begin(v), begin(v)+half, [n=0]()mutable{return n++;});
    std::generate(begin(v)+half, begin(v)+2*half, [n=0]()mutable{return n++;});
    v[2*half] = 33333;
    vecs.push_back(v);

    for(auto& vec: vecs)
    {
        auto single = perform_print_duration("XOR: ", get_single_number_xor, vec);
        std::cout<<"1-single: "<<single<<"\n";

        single = perform_print_duration("SET: ", get_single_number_set, vec);
        std::cout<<"2-single: "<<single<<"\n";

        single = perform_print_duration("BF : ", get_single_number_brute_force, vec);
        std::cout<<"3-single: "<<single<<"\n";

        std::cout<<"===================================\n";
    }
}