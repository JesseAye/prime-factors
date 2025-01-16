#include <string>

std::string calculate_prime_factors(unsigned int number)
{
    std::string result = "1";
    for (unsigned int i = 2; i <= number; i++)
    {
        unsigned int remainder = number % i;

        if (remainder == 0)
        {
            std::string remainder_str = (", " + std::to_string(i));
            result += remainder_str;
        }
    }
    
    result += "\n";
    return result;
}

int main(int argc, char *argv[])
{
    unsigned int number = 21;
    std::string primes = calculate_prime_factors(number);
    printf(primes.c_str());
    return 0;
}