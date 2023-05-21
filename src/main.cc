#include <iostream>
#include <string>
#include <stdexcept>

#include "utilities.hpp"
#include "key_handling.hpp"

int main(int argc, char* const argv[]) {
    std::string passphrase, message;
    int e, n, d;

    if(argc != 2){
        std::cout << "invalid usage, refer to documentation" << std::endl;
        return 1;
    }

    if(strcmp(argv[1], "--encrypt") == 0){
        //Check if keys can be found, if not make new values for all keys
        bool keysFound = retrieveKeys(e, n, d);
        if (!keysFound){
            int p = generatePrime();
            int q = generatePrime();

            n = p * q;
            int phi_n = (p - 1) * (q - 1);
            
            do {
            e = rand() % (phi_n - 2) + 2;
            }  while (calculateGCD(e, phi_n) != 1);

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
        std::string encryptedMessage = "test";
        std::cout << "Encrypted message: " << encryptedMessage << std::endl;
        return 0;
    }
    if(strcmp(argv[1], "--decrypt") == 0){
        // Get passphrase from user
        std::cout << "Enter passphrase: ";
        std::getline(std::cin, passphrase);

        // Get message to encrypt from user
        std::cout << "Enter message to encrypt: ";
        std::getline(std::cin, message);

        // Decrypt the message and display
        std::string decryptedMessage = "test";
        std::cout << "Decrypted message: " << decryptedMessage << std::endl;
        return 0;
    }

    return 0;
}