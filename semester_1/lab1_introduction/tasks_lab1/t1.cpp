#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    for(int i = 1; i <= std::min(a, b); i++){
        if(a % i == 0 && b % i == 0){
            std::cout << i << ' ';
        }
    }

    return 0;
}
