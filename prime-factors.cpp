#include <string>
#include <vector>
#include <map>

std::vector<unsigned int> calculate_factors(unsigned int number)
{
    std::vector<unsigned int> results;
    results.push_back(1);
    for (unsigned int i = 2; i <= (number / 2); i++)
    {
        unsigned int remainder = number % i;

        if (remainder == 0)
        {
            results.push_back(i);
        }
    }
    
    results.push_back(number);
    return results;
}

std::map<unsigned int, unsigned int> calculate_prime_factors(unsigned int number)
{
    std::map<unsigned int, unsigned int> results;
    unsigned int curr_factor = 2;
    while (curr_factor <= number && curr_factor > 1)
    {
        unsigned int remainder = number % curr_factor;

        if (remainder == 0)
        {
            results[curr_factor]++;
            number = number / curr_factor;
        }
        else
        {
            curr_factor++;
        }
    }

    return results;
}

int main(int argc, char *argv[])
{
    unsigned int number = 25;
    std::map<unsigned int, unsigned int> prime_factors = calculate_prime_factors(number);
    
    std::map<unsigned int, unsigned int>::iterator it = prime_factors.begin();
    printf("%lu^%lu", it->first, it->second);
    it++;
    while(it != prime_factors.end())
    {
        printf(" * %lu^%lu", it->first, it->second);
        it++;
    }
    printf("\n");

    std::vector<unsigned int> primes = calculate_factors(number);
    printf("%lu", primes.at(0));
    for (std::vector<unsigned int>::iterator it = primes.begin() + 1; it != primes.end(); it++)
    {
        printf(", %lu", *it);
    }

    printf("\n");
    return 0;
}