#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    for(int i = 1; i < n + k; i++){
        if(i - n + 1 < 1) std::cout << "   ";
        else{
            if(i - n + 1 < 10) std::cout << ' ';
            std::cout << i - n + 1 << ' ';
        }
        if(i % 7 == 0) std::cout << std::endl;
    }

    return 0;
}
