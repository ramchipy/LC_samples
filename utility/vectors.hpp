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

template<typename IT>
static void print_vector(IT first, IT last)
{
    int i = 0;
    std::cout<<'[';
    for(auto it = first; it<last; it++)
    {
        std::cout<<*it<<" ";
        i++;
        if((i % 16) == 15)
        {
            std::cout<<"\n";
        }
    }
    std::cout<<"]\n";
}