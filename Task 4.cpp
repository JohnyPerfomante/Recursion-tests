#include <iostream>
#include <string>

using namespace std;

// Головна рекурсія
int climbMain(int n) {
    if (n <= 2)
        return n;

    return climbMain(n - 1) + climbMain(n - 2);
}

// Хвостова рекурсія
int climbTail(int n, int a = 1, int b = 2) {
    if (n == 1)
        return a;
    if (n == 2)
        return b;

    return climbTail(n - 1, b, a + b);
}

int main() {

    cout << "===== ТЕСТ ПІДЙОМ СХОДАМИ =====\n";

    cout << "n = 1\n";
    cout << "Головна: " << climbMain(1) << "\n";
    cout << "Хвостова: " << climbTail(1) << "\n\n";

    cout << "n = 2\n";
    cout << "Головна: " << climbMain(2) << "\n";
    cout << "Хвостова: " << climbTail(2) << "\n\n";

    cout << "n = 5\n";
    cout << "Головна: " << climbMain(5) << "\n";
    cout << "Хвостова: " << climbTail(5) << "\n\n";

    cout << "n = 10 (Xвoстова (ефективний)): ";
    cout << climbTail(10) << "\n";

    return 0;
}