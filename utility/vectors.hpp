#include <iostream>
#include <vector>

static auto get_vector(size_t size = 9999, int modulo = 1000)
{    
    std::vector<int> vec(size);
    srand(12314);
    for(auto& e : vec)
    {
        e = random() % modulo;        
    }

    return vec;
}

static void print_vector(const std::vector<int>& vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        std::cout<<vec[i]<<" ";
        if((i % 16) == 15)
        {
            std::cout<<"\n";
        }
    }
    std::cout<<"\n";
}