#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if((n / 100000 + n / 10000 % 10 + n / 1000 % 10) == (n/100 % 10 + n / 10 % 10 + n % 10)){
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }

    return 0;
}
