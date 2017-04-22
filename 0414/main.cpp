#include "fraction.h"

void print(const bool & f) {
    if (f)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

int main() {
    fraction f1, f2;
    int T = 3;
    while (T--)
    {

    std::cin >> f1 >> f2;
    print(f1 < f2);
        
    }

    return 0;
}

