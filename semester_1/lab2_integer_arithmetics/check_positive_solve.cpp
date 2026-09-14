#include <iostream>

void TryRead(int& number) {
    if (!(std::cin >> number)) {
        std::cout << "Fail on reading the number." << std::endl;
        std::exit(0);
    }
}

bool IsNotNegative(int number) {
    return abs(number) == number;
}

int main() {
    int number;

    std::cout << "Enter the number: ";
    TryRead(number);

    //bool std_non_negative_check = (number >= 0); Зачем это?

    if (IsNotNegative(number)) {
        std::cout << "The number is not negative" << std::endl;
    } else {
        std::cout << "The number is negative" << std::endl;
    }

    return 0;
}
