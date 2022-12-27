#include <vector>
#include <iostream>

static bool isBadVersion(int version)
{
    std::cout<<__func__<<"("<<version<<")\n";
    return version >= 13;
}

static int get_first_bad_version(int n)
{
    int left = 1;
    int right = n;
    while(left < right)
    {
        auto mid = (left + right) / 2;
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}


int main(void)
{
    for(auto n: std::vector{128, 64, 32, 16, 28, 24, 26})
    {
        auto bad = get_first_bad_version(n);
        std::cout<<"Bad version of "<<n<<": "<<bad<<"\n";
        std::cout<<"=========================================\n";
    }
}