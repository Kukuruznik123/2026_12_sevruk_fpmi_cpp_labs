#include <iostream>

int main() {
    int a, b, d;
    std::cin >> a >> b >> d;
    while(a <= b){
        if(a % 3 == 0) std::cout << a << ' ';
        a += d;
    }

    return 0;
}
