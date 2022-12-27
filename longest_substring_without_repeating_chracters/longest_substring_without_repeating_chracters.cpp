#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include "../utility/measure.hpp"

static size_t longest_substring_brute_force(const std::string& str)
{
    size_t longest = 0;
    size_t len = str.length();
    std::string longest_str = "";
    for(size_t i=0; i<len; i++)
    {
        std::set<char> seen;
        for(size_t j=i; j<len;j++)
        {
            auto ch = str.c_str()[j];                        
            //std::cout<<"Testing: "<<i<<"-"<<j<<": "<<ch<<" ,longest: "<<longest<<"\n";
            if(seen.contains(ch))
            {
                //std::cout<<ch<<" is already in seen\n";                
                break;                
            }
            else
            {
                seen.insert(ch);
            }
            if(longest < seen.size())
            {
                longest = seen.size();
                longest_str = str.substr(i, longest);
            }
        }
    }
    std::cout<<"longest_sub_str: "<<longest_str<<"\n";
    return longest;
}

static size_t longest_substring_str(const std::string& str)
{
    size_t longest = 0;
    size_t len = str.length();
    size_t start = 0;    
    std::string longest_str = "";
    for(size_t i=0; i<len; i++)
    {
        auto ch = str.c_str()[i];
        auto ndx = str.substr(start, i-start).find(ch);
        if (ndx != std::string::npos)
        {
            start += ndx + 1;
        }
        if (longest < (i+1-start))
        {
            longest = (i+1-start);
            longest_str = str.substr(start, i+1-start);
        }        
    }
    std::cout<<"longest_sub_str: "<<longest_str<<"\n";
    return longest;
}

static size_t longest_substring_table(const std::string& str)
{
    size_t longest = 0;
    size_t len = str.length();
    int start = 0;    
    std::string longest_str = "";
    std::array<int, 128> ASCII;
    std::fill(begin(ASCII), end(ASCII), -1);
    
    for(size_t i=0; i<len; i++)
    {
        auto ch = str.c_str()[i];
        int val = static_cast<int>(ch);
        if (ASCII[val] >= start)
        {
            start = ASCII[val] + 1;
        }
        ASCII[val] = i;
        if (longest < (i+1-start))
        {
            longest = (i+1-start);
            longest_str = str.substr(start, i+1-start);
        }        
    }
    std::cout<<"longest_sub_str: "<<longest_str<<"\n";
    return longest;
}

std::string operator*(std::string s, size_t count)
{
    std::string ret(s.size()*count, '*');
    for(size_t i = 0; i < count; ++i)
    {
        memcpy(&(ret.data()[i*s.size()]), s.c_str(), s.size());
    }
    return ret;
}

static size_t longest_substring_map(const std::string& str)
{
    size_t longest = 0;
    size_t len = str.length();
    int start = 0;    
    std::string longest_str = "";
    std::map<char, int> found = {};
    
    for(size_t i=0; i<len; i++)
    {
        auto ch = str.c_str()[i];
        
        auto it = found.find(ch);
        if (it != found.end() && it->second >= start)
        {
            start = it->second + 1;
        }
        found[ch] = i;
        if (longest < (i+1-start))
        {
            longest = (i+1-start);
            longest_str = str.substr(start, i+1-start);
        }        
    }
    std::cout<<"longest_sub_str: "<<longest_str<<"\n";
    return longest;
}

int main()
{
    std::vector<std::string> vec{"", "abcbda", "abcabcbd", "0123456701234567890", std::string("012345670123456789001234567012345678900123456701234567890") * 50000 + "0123456789a"}; 
    for(auto& str: vec)
    {
        //std::cout<<str<<"\n";
        std::cout<<str.size()<<"************************************************\n";        
        perform_print_duration("Brute force :", longest_substring_brute_force, str);
        std::cout<<"-----------------------------------------------\n";
        perform_print_duration("Search str  :", longest_substring_str, str);
        std::cout<<"-----------------------------------------------\n";
        perform_print_duration("ASCII table :", longest_substring_table, str);
        std::cout<<"-----------------------------------------------\n";
        perform_print_duration("Index map   :", longest_substring_map, str);
    }
    return 0;
}