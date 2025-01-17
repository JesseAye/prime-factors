#include <string>
#include <vector>

std::vector<unsigned int> calculate_prime_factors(unsigned int number)
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

int main(int argc, char *argv[])
{
    unsigned int number = 21;
    std::vector<unsigned int> primes = calculate_prime_factors(number);
    printf("%lu", primes.at(0));
    for (std::vector<unsigned int>::iterator it = primes.begin() + 1; it != primes.end(); it++)
    {
        printf(", %lu", *it);
    }

    printf("\n");
    return 0;
}