#include <vector>
#include <cmath>
#include <iostream>
#include "../utility/measure.hpp"

static int number_of_primes_less_than_brute_force(int n)
{
    int count = 0;
    for(int i=2; i< n; i++)
    {
        bool is_prime = true;
        for(int j=2; j<(i/2)+1; j++)
        {
            if ((i %j) == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            count += 1;
        }
    }

    return count;
}

static int number_of_primes_less_than_1(int n)
{
    std::vector<int> primes;
    primes.reserve(n);
    int count = 0;
    for(int i=2; i<n;i++)
    {
        bool is_prime = true;
        for(const auto& p: primes)
        {
            if ((i%p) == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            primes.push_back(i);
            count += 1;
        }
    }

    return count;
}

static int number_of_primes_less_than_2(int n)
{
    std::vector<bool> isPrime(n, true);
    int count = n-2;
    const int limit = std::ceil(std::sqrt(n));
    for(int i=2; i<limit;i++)
    {
        for(int j=i*i; j<n; j+=i)
        {
            if(isPrime[j])
            {
                count -= 1;
                isPrime[j] = false;
            }            
        }
    }

    return count;
}

int main(void)
{
    for(auto n: std::vector<int>{2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144})
    {
        std::cout<<"Prime count less than: "<<n<<"\n";
        
        auto count = perform_print_duration("Brute force: ", number_of_primes_less_than_brute_force, n);
        std::cout<<"count: "<<count<<"\n";

        count = perform_print_duration("Optimal1   : ", number_of_primes_less_than_1, n);
        std::cout<<"count: "<<count<<"\n";

        count = perform_print_duration("Optimal2   : ", number_of_primes_less_than_2, n);
        std::cout<<"count: "<<count<<"\n";
        std::cout<<"==============================================\n";
    }

    return 0;
}