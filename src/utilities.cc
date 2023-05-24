#include "utilities.hpp"

//Recursive implementation of sieve of Erathosthenes
std::vector<bool> SieveOfEratosthenes(int n) {
    std::vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    return prime;
}

int generatePrime() {
    const int limit = 1000; //arbitrary
    std::vector<bool> prime = SieveOfEratosthenes(limit);

    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }

    const int numPrimes = primes.size();
    if (numPrimes == 0) {
        std::cerr << "No prime numbers found." << std::endl;
        return -1;
    }

    std::srand(std::time(nullptr));
    int index = std::rand() % numPrimes;

    return primes[index];
}

//Calculating GCD using the Euclidean algorithm
int calculateGCD(int a, int b){
    if(b == 0){
        return a;
    }

    return calculateGCD(b, a % b);
}

int calculateModularInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
// Function to calculate the modular exponentiation (base^exp % mod)
int modularExponentiation(int base, unsigned int exp, int mod)
{
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

std::string encryptMessage(const std::string& message, int e, int n)
{
    std::string encryptedMessage = "";
    for (char c : message) {
        int charValue = static_cast<  int>(c);
        int encryptedValue = modularExponentiation(charValue, e, n);
        encryptedMessage += std::to_string(encryptedValue) + " ";
    }
    return encryptedMessage;
}

