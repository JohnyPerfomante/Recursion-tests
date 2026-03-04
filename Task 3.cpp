#include <iostream>
#include <string>

using namespace std;

// Головна рекурсія
int fibonacciMain(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacciMain(n - 1) + fibonacciMain(n - 2);
}

// Хвостова рекурсія
int fibonacciTail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;

    return fibonacciTail(n - 1, b, a + b);
}

int main() {

    cout << "===== ТЕСТ ФІБОНАЧЧІ =====\n";

    cout << "F(0) Головна: " << fibonacciMain(0) << "\n";
    cout << "F(0) Хвостова: " << fibonacciTail(0) << "\n\n";

    cout << "F(1) Головна: " << fibonacciMain(1) << "\n";
    cout << "F(1) Хвостова: " << fibonacciTail(1) << "\n\n";

    cout << "F(6) Головна: " << fibonacciMain(6) << "\n";
    cout << "F(6) Хвостова: " << fibonacciTail(6) << "\n\n";

    cout << "F(10) Тільки хвістова (ефективний): " << fibonacciTail(10) << "\n";

    return 0;
}