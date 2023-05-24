#include "utilities.hpp"

//Recursive implementation of sieve of Erathosthenes
std::vector<bool> SieveOfEratosthenes(long long int n) {
    std::vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (long long int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (long long int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    return prime;
}

long long int generatePrime() {
    const long long int limit = 1000; //arbitrary
    std::vector<bool> prime = SieveOfEratosthenes(limit);

    std::vector<long long int> primes;
    for (long long int i = 2; i <= limit; ++i) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }

    const long long int numPrimes = primes.size();
    if (numPrimes == 0) {
        std::cerr << "No prime numbers found." << std::endl;
        return -1;
    }

    std::srand(std::time(nullptr));
    long long int index = std::rand() % numPrimes;

    return primes[index];
}

//Calculating GCD using the Euclidean algorithm
long long int calculateGCD(long long int a, long long int b){
    if(b == 0){
        return a;
    }

    return calculateGCD(b, a % b);
}

long long int calculateModularInverse(long long int a, long long int m){
    long long int m0 = m;
    long long int y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        long long int q = a / m;
        long long int t = m;

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
long long int modularExponentiation(long long int base, unsigned int exp, long long int mod){
    long long int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

std::string encryptMessage(const std::string& message, long long int e, long long int n){
    std::string encryptedMessage = "";
    for (char c : message) {
        long long int charValue = static_cast<long long int>(c);
        long long int encryptedValue = modularExponentiation(charValue, e, n);
        encryptedMessage += std::to_string(encryptedValue) + " ";
    }
    return encryptedMessage;
}

std::string decryptMessage(const std::string& encryptedMessage, long long int d, long long int n){
    std::string decryptedMessage = "";
    std::string encryptedValue = "";
    for (char c : encryptedMessage) {
        if (c != ' ') {
            encryptedValue += c;
        } else {
            long long int encryptedNum = std::stoll(encryptedValue);
            long long int decryptedNum = modularExponentiation(encryptedNum, d, n);
            decryptedMessage += static_cast<char>(decryptedNum);
            encryptedValue = "";
        }
    }
    return decryptedMessage;
}

