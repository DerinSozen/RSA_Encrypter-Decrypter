#include "includes/key_handling.h"

bool retrieveKeys(int& e, int& n, int& d){
    std::ifstream public_ifs("public_key.txt");
    std::ifstream private_ifs("private_key.txt");

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
    //TODO
}