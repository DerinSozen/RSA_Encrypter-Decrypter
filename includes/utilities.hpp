#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::vector<bool> SieveOfEratosthenes(long long int n);
long long int generatePrime();
long long int calculateGCD(long long int a, long long int b);
long long int calculateModularInverse(long long int a, long long int m);
long long int modularExponentiation(long long int base, unsigned int exp, long long int mod);
std::string encryptMessage(const std::string& message, long long int e, long long int n);
std::string decryptMessage(const std::string& encryptedMessage, long long int d, long long int n);

#endif