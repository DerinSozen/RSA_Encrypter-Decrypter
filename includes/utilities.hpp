#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::vector<bool> SieveOfEratosthenes(int n);
int generatePrime();
int calculateGCD(int a, int b);
int calculateModularInverse(int a, int m);
int modularExponentiation(int base, unsigned int exp, int mod);
std::string encryptMessage(const std::string& message, int e, int n);

#endif