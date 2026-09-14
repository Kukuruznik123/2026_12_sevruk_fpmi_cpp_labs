#include <iostream>
#include <clocale>
int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b;
    std::cout << "Привет, пользователь!\nМоя программа выводит все числа Мерсенна на заданном тобой отрезке.\nВведи 2 числа, границы отрезка:\n";
    if(!(std::cin >> a >> b)){
        std::cout << "Введённые значения не подходят под мою программу!";
        std::exit(-1);
    }
    if(b < a || b < 1){
        std::cout << "Границы отрезка не имеют смысла!";
        std::exit(-1);
    }
    std::cout << "Отлично! Вот все числа вида 2^n-1 на отрезке [" << a << "; " << b << "]:\n";
    int x = 2;
    bool flag = true;
    while(x - 1 <= b){
        if(x - 1 >= a){
            std::cout << x - 1 << ' ';
            flag = false;
        }
        x *= 2;
    }
    if(flag) std::cout << "Подходящие числа не найдены";

    return 0;
}
