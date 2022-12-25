#include <vector>
#include <algorithm>
#include <string>
#include <boost/format.hpp>
#include <iostream>
#include "../utility/vectors.hpp"

static int get_number_of_rescue_boats(std::vector<int>& vec, int limit)
{    
    int boats = 0;
    int left = 0;
    int right = vec.size()-1;
    std::sort(begin(vec), end(vec));
    while(left <= right)
    {
        std::string people = "";
        print_vector(begin(vec)+left, begin(vec)+right+1);
        if ((left != right) && (vec[left] + vec[right]) <= limit)
        {            
            people = (boost::format("[%d, %d]") % vec[left] % vec[right]).str();            
            left += 1;
            right -= 1;
            boats += 1;
        }
        else
        {            
            people = (boost::format("[%d]") % vec[right]).str();
            right -= 1;
            boats += 1;
        }
        
        std::cout<<people<<" go with boat "<<boats<<"\n";
    }

    return boats;
}

int main()
{
    std::vector v{1, 2, 3, 3};
    auto boats = get_number_of_rescue_boats(v, 4);
    std::cout<<"Will need "<<boats<<" boats\n";
    return 0;
}