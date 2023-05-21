#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::vector<bool> SieveOfEratosthenes(int n);
int generatePrime();
int calculateGCD(int a, int b);
int calculateModularInverse(long long int a, long long int m);

#endif