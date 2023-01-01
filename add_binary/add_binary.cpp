#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <boost/format.hpp>

std::string add_binary(std::string_view bin1, std::string_view bin2)
{
    int carry = 0;
    std::string result = "";
    int i = 0;
    int max_len = std::max(bin1.size(), bin2.size());

    while(i < max_len || carry != 0)
    {
        int sum = carry;
        if (i<bin1.size())
        {
            sum += static_cast<int>(bin1[bin1.size()-1-i])-0x30;
        }
        if (i<bin2.size())
        {
            sum += static_cast<int>(bin2[bin2.size()-1-i])-0x30;
        }
        carry = sum/2;
        result = std::to_string(sum%2) + result;
        i += 1;
    }

    return result;
}

int main(void)
{
    for(auto& [bin1, bin2]: std::vector<std::pair<std::string_view, std::string_view>>{{"01", "01"}, {"110", "010"}, {"01", "0000100"}})
    {
        std::cout<<(boost::format("%s + %s = %s\n") % bin1 % bin2 % add_binary(bin1, bin2)).str();
    }
}