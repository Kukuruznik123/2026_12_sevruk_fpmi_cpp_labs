//var10
#include <iostream>
#include <clocale>
#include <random>

void tryRead(int& a){
    if(!(std::cin >> a)){
        std::cout << "При вводе произошла ошибка";
        exit(-1);
    }
}
void arrCout(int* arr, int n){
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
void solve(int* arr, int n){
    for(int i = 0; i < n; i++){
        int ch = arr[i];
        int cnt = 0;
        do{
            if(ch % 2 == 1) cnt++;
            ch >>=1;
        } while(ch > 0);
        if(cnt % 2 == 1){
            for(int j = i; j < n - 1; j++){
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = 0;
            i--;
            n--;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество элементов массива:\n";
    int n, MAX = 10000;
    tryRead(n);
    std::cout << "Введите 0, чтобы ввести массив вручную, или любое другое целое число, чтобы сгенерировать его случайно:\n";
    int check, arr[MAX];
    tryRead(check);
    if(check){
        std::mt19937 gen(45218965);
        int x, y;
        std::cout << "Какие хотите ограничения у значений?\n";
        tryRead(x);
        tryRead(y);
        std::uniform_int_distribution<int> dist(x, y);
        for(int i = 0; i < n; i++) arr[i] = dist(gen);
        std::cout << "Принято! Вот наш массив:\n";
        arrCout(arr, n);
    } else{
        std::cout << "Введите массив:\n";
        for(int i = 0; i < n; i++) tryRead(arr[i]);
    }
    solve(arr, n);

    std::cout << "Записано! А вот и ответ:\n";
    arrCout(arr, n);

    return 0;
}
