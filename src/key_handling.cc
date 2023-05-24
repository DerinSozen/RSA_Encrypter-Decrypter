#include "key_handling.hpp"


bool retrieveKeys(long long int& e, long long int& n, long long int& d){
    std::ifstream public_ifs("src/private_key.txt");
    std::ifstream private_ifs("src/public_key.txt");

    if (public_ifs.is_open() && private_ifs.is_open()) {
        public_ifs >> e;
        public_ifs >> n;
        private_ifs >> d;
        private_ifs >> n;

        public_ifs.close();
        private_ifs.close();
        return true;
    } else {
        return false;
    }
}

void saveKeys(int e, int n, int d){
    std::ofstream public_ofs("src/public_key.txt");
    if (public_ofs.is_open()) {
        public_ofs << e << std::endl;
        public_ofs << n << std::endl;
        public_ofs.close();
        std::cout << "Public key saved to public_key.txt" << std::endl;
    } else {
        std::cerr << "Unable to open public_key.txt" << std::endl;
    }

    std::ofstream private_ofs("src/private_key.txt");
    if (private_ofs.is_open()) {
        private_ofs << d << std::endl;
        private_ofs << n << std::endl;
        private_ofs.close();
        std::cout << "Private key saved to private_key.txt" << std::endl;
    } else {
        std::cerr << "Unable to open private_key.txt" << std::endl;
    }
}