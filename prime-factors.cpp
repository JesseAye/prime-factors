#include <string>
#include <vector>
#include <map>

std::vector<uint> calculate_factors(uint number)
{
    std::vector<uint> results;
    results.push_back(1);
    for (uint i = 2; i <= (number / 2); i++)
    {
        uint remainder = number % i;

        if (remainder == 0)
        {
            results.push_back(i);
        }
    }
    
    results.push_back(number);
    return results;
}

std::map<uint, uint> calculate_prime_factors(uint number)
{
    std::map<uint, uint> results;
    uint curr_factor = 2;
    while (curr_factor <= number && curr_factor > 1)
    {
        uint remainder = number % curr_factor;

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
    uint number = 25;
    std::map<uint, uint> prime_factors = calculate_prime_factors(number);
    
    std::map<uint, uint>::iterator it = prime_factors.begin();
    printf("%lu^%lu", it->first, it->second);
    it++;
    while(it != prime_factors.end())
    {
        printf(" * %lu^%lu", it->first, it->second);
        it++;
    }
    printf("\n");

    std::vector<uint> factors = calculate_factors(number);
    printf("%lu", factors.at(0));
    for (std::vector<uint>::iterator it = factors.begin() + 1; it != factors.end(); it++)
    {
        printf(", %lu", *it);
    }

    printf("\n");
    return 0;
}