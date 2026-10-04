//var12
#include <iostream>
#include <clocale>
#include <random>

void tryRead(int& a){
    if(!(std::cin >> a)){
        std::cout << "При вводе произошла ошибка";
        exit(-1);
    }
}
void arrCin(int *arr, int n){
    std::cout << "Введите массив:\n";
    for(int i = 0; i < n; i++) tryRead(arr[i]);
}
void arrGen(int *arr, int n){
    std::mt19937 gen(45218965);
    int x, y;
    std::cout << "Какие хотите ограничения у значений?\n";
    tryRead(x);
    tryRead(y);
    std::uniform_int_distribution<int> dist(x, y);
    for(int i = 0; i < n; i++) arr[i] = dist(gen);
}
void arrCout(int* arr, int n){
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
void solve(int* arr, int n){
    int kol = n + 1, ans = -2147483648;
    for(int i = 0; i < n; i++){
        if(arr[i] != arr[0] || i == 0){
            int cnt = 1;
            for(int j = i + 1; j < n; j++){
                if(arr[j] == arr[i]){
                    cnt++;
                    arr[j] = arr[0];
                }
            }
            if(cnt < kol){
                kol = cnt;
                ans = arr[i];
            } else if(cnt == kol && arr[i] > ans) ans = arr[i];
        }
    }
    std::cout << "Число " << ans << " встречается в массиве " << kol << " раз(а)";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество элементов массива:\n";
    int n;
    tryRead(n);
    std::cout << "Введите 0, чтобы ввести массив вручную, или любое другое целое число, чтобы сгенерировать его случайно:\n";
    int check;
    int *arr = new int[n];
    tryRead(check);
    if(check){
        arrGen(arr, n);
        std::cout << "Принято! Вот наш массив:\n";
        arrCout(arr, n);
    } else{
        arrCin(arr, n);
    }

    std::cout << "Записано! А вот и ответ:\n";
    solve(arr, n);

    delete[] arr;

    return 0;
}
