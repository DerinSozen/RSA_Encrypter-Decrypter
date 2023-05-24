#include <iostream>
#include <string>
#include <stdexcept>
#include <random>
#include <algorithm>

#include "utilities.hpp"
#include "key_handling.hpp"

int main(int argc, char* const argv[]) {
    std::string passphrase, message;
    long long int e, n, d;

    if(argc != 2){
        std::cerr << "invalid usage, refer to documentation" << std::endl;
    }

    if(strcmp(argv[1], "--encrypt") == 0){
        //Check if keys can be found, if not make new values for all keys
        bool keysFound = retrieveKeys(e, n, d);
        if (!keysFound){
            int p = generatePrime();
            int q = generatePrime();

            n = p * q;
            long long int phi_n = (p - 1) * (q - 1);
            
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<long long int> dist(2, phi_n - 1);

            long long int e = dist(gen);
            while (calculateGCD(e, phi_n) != 1) {
                e = dist(gen);
            }

            d = calculateModularInverse(e, phi_n);

            saveKeys(e, n, d);
        }

        // Get passphrase from user
        std::cout << "Enter passphrase: ";
        std::getline(std::cin, passphrase);

        // Get message to encrypt from user
        std::cout << "Enter message to encrypt: ";
        std::getline(std::cin, message);

        // Encrypt the message and display
        std::string encryptedMessage = encryptMessage(message, e, n);
        std::cout << "Encrypted message: " << encryptedMessage << std::endl;
        return 0;
    }
    if(strcmp(argv[1], "--decrypt") == 0){
        bool keysFound = retrieveKeys(e, n, d);
        if (!keysFound){
            int p = generatePrime();
            int q = generatePrime();

            n = p * q;
            long long int phi_n = (p - 1) * (q - 1);
            
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<long long int> dist(2, phi_n - 1);

            long long int e = dist(gen);
            while (calculateGCD(e, phi_n) != 1) {
                e = dist(gen);
            }

            d = calculateModularInverse(e, phi_n);

            saveKeys(e, n, d);
        }
        // Get passphrase from user
        std::cout << "Enter passphrase: ";
        std::getline(std::cin, passphrase);

        // Get message to encrypt from user
        std::cout << "Enter message to encrypt: ";
        std::getline(std::cin, message);

        // Decrypt the message and display
        std::string decryptedMessage = decryptMessage(message, d, n);
        std::cout << "Decrypted message: " << decryptedMessage << std::endl;
        return 0;
    }

    return 0;
}