#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int v1 = 0, v2 = 1, help;
    std::cout << "0 ";
    for(int i = 0; i < n - 1; i++){
        std::cout << v2 << ' ';
        help = v2;
        v2 += v1;
        v1 = help;
    }

    return 0;
}
