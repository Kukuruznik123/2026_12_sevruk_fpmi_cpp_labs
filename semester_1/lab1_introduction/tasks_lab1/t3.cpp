#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if(n / 1000 == n % 10 && (n%1000/100) == (n%100/10)){
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }

    return 0;
}
