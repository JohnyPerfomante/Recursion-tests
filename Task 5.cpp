#include <iostream>
#include <string>

using namespace std;

// Головна рекурсія
double myPowMain(double x, int n) {
    if (n == 0)
        return 1;

    if (n < 0)
        return 1 / myPowMain(x, -n);

    double half = myPowMain(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

// Хвостова рекурсія
double myPowTail(double x, int n, double result = 1.0) {
    if (n == 0)
        return result;

    if (n < 0)
        return myPowTail(1 / x, -n, result);

    if (n % 2 == 1)
        result *= x;

    return myPowTail(x * x, n / 2, result);
}

int main() {

    cout << "===== ТЕСТ ФУНКЦІЇ(x,n) =====\n";

    cout << "2^10 Головна: " << myPowMain(2.0, 10) << "\n";
    cout << "2^10 Хвостова: " << myPowTail(2.0, 10) << "\n\n";

    cout << "2.1^3 Головна: " << myPowMain(2.1, 3) << "\n";
    cout << "2.1^3 Хвостова: " << myPowTail(2.1, 3) << "\n\n";

    cout << "2^-2 Головна: " << myPowMain(2.0, -2) << "\n";
    cout << "2^-2 Хвостова: " << myPowTail(2.0, -2) << "\n\n";

    cout << "5^0 Головна: " << myPowMain(5.0, 0) << "\n";
    cout << "5^0 Хвостова: " << myPowTail(5.0, 0) << "\n";

    return 0;
}