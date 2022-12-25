#include <vector>
#include <iostream>
#include <algorithm>
#include "../utility/measure.hpp"
#include "../utility/vectors.hpp"

void move_zeros_space1(std::vector<int>& vec)
{
    auto zero_it = std::remove(begin(vec), end(vec), 0);
    auto zero_cnt = end(vec) - zero_it;
    
    std::for_each(zero_it, end(vec), [](int &n){
        n = 0;
    });
}

void move_zeros_space2(std::vector<int>& vec)
{
    auto zero_it = std::remove(begin(vec), end(vec), 0);
    auto zero_cnt = end(vec) - zero_it;
    
    vec.erase(zero_it, end(vec));    
    vec.insert(vec.end(), zero_cnt, 0);
}

void move_zeros_brute_force(std::vector<int>& vec)
{
    auto next_zero = vec.size()-1;
    for(int i=0; i<=next_zero; i++)
    {
        if(vec[i] == 0)
        {
            for(int j=i; j<next_zero; j++)
            {
                vec[j] = vec[j+1];
            }
            vec[next_zero] = 0;
            next_zero -= 1;
            i -= 1;
        }                
    }
}

void move_zeros_efficient(std::vector<int>& vec)
{
    size_t j = 0;    
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] != 0)
        {
            vec[j] = vec[i];
            j++;
        }                
    }
    for(int i=j; i<vec.size(); i++)
    {
        vec[i] = 0;
    }
}

int main()
{
    std::vector<int> vec;
    constexpr int SIZE = 99999;  
    constexpr int MODULO = 100;  
    std::cout<<"=======================================================\n";
    vec = get_vector(SIZE, MODULO);
    perform_measure("space2", move_zeros_space2, vec);
    //print_vector(vec);
    std::cout<<"=======================================================\n";
    vec = get_vector(SIZE, MODULO);
    perform_measure("space1", move_zeros_space1, vec);
    //print_vector(vec);
    std::cout<<"=======================================================\n";
    vec = get_vector(SIZE, MODULO);
    perform_measure("brute ", move_zeros_brute_force, vec);
    //print_vector(vec);
    std::cout<<"=======================================================\n";
    vec = get_vector(SIZE, MODULO);
    //print_vector(vec);
    perform_measure("effic ", move_zeros_efficient, vec);    
    //print_vector(vec);
}