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
    //TODO
    return a * m;
}