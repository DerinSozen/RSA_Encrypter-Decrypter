#include <iostream>
#include "includes/utilities.h"
int main() {
    std::string passphrase;
    std::string publicKeyFile = "";
    std::string message;

    // Get passphrase from user
    std::cout << "Enter passphrase: ";
    std::getline(std::cin, passphrase);

    // Get public key file from user
    std::cout << "Enter public key file name (e.g., public.pem): ";
    std::getline(std::cin, publicKeyFile);

    // Get message to encrypt from user
    std::cout << "Enter message to encrypt: ";
    std::getline(std::cin, message);

    return 0;
}