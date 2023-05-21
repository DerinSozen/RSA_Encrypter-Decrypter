#include <iostream>
#include <string>
#include <stdexcept>

#include "includes/utilities.h"

int main(int argc, char* const argv[]) {
    std::string passphrase;
    std::string message;

    if(argc != 2){
        std::cout << "invalid usage, refer to documentation" << std::endl;
        return 1;
    }

    if(strcmp(argv[1], "--encrypt") == 0){
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

        // Encrypt the message and display
        std::string encryptedMessage = "test";
        std::cout << "Encrypted message: " << encryptedMessage << std::endl;
        return 0;
    }

    return 0;
}