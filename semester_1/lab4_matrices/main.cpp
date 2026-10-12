#include <iostream>
#include <clocale>
#include <iomanip>

void tryRead(int &a){
    if(!(std::cin >> a)){
        std::cout << "Ошибка ввода данных";
        exit(-1);
    }
}

void makeMa(int **&a, int n){
    a = new int *[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[n];
        for(int j = 0; j < n; j++){
            a[i][j] = std::abs(i - j);
        }
    }
}

void showMa(int **a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << std::setw(3) << a[i][j] << ' ';
        }
        std::cout << std::endl << std::endl;
    }
}

void destroyMa(int **a, int n){
    for(int i = 0; i < n; i++){
        delete[] a[i];
    }
    delete[] a;
}

void solve(int **a, int n){
    int *ans = new int[4]{};
    if(n < 3){
        std::cout << "Нужные области пусты :(";
    } else {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Вообще, в этой задаче все нужные суммы равны, но я сделал так, чтоб в любом случае работало
                if(j > i && j < n - i - 1) ans[0] += a[i][j];
                else if(j < i && j > n - i - 1) ans[3]+= a[i][j];
                else if(i > j && i < n - j - 1) ans[1] += a[i][j];
                else if(i < j && i > n - j - 1) ans[2] += a[i][j];
            }
        }
        std::cout << "   " << ans[0] << std::endl << ans[1] << "     " << ans[2] << std::endl << "   " << ans[3];
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите размер стороны квадратной матрицы:\n";
    tryRead(n);
    if(n < 1){
        std::cout << "Такое число не подойдёт";
        exit(-1);
    }
    int **a;
    makeMa(a, n);
    showMa(a, n);
    std::cout << "------------------------------------------\n";
    solve(a, n);
    destroyMa(a, n);

    return 0;
}
