#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

// Головна рекурсія
void reverseMain(const string& s, int index) {
    if (index < 0)
        return;

    cout << s[index];
    reverseMain(s, index - 1);
}

void printReverseMain(const string& s) {
    reverseMain(s, s.length() - 1);
}

// Хвостова рекурсія
void reverseTail(const string& s, int index) {
    if (index == s.length())
        return;

    reverseTail(s, index + 1);
    cout << s[index];
}

void printReverseTail(const string& s) {
    reverseTail(s, 0);
}

int main() {

    cout << "===== ТЕСТ ЗВОРОТНЬОГО РЯДКА =====\n";

    string test1 = "тигр";
    string test2 = "";
    string test3 = "A";
    string test4 = "рекурсія";

    cout << "Вхід: тигр\nMain: ";
    printReverseMain(test1);
    cout << "\nXвіст: ";
    printReverseTail(test1);
    cout << "\n\n";

    cout << "Вхід: порожній рядок\nMain: ";
    printReverseMain(test2);
    cout << "\nXвіст: ";
    printReverseTail(test2);
    cout << "\n\n";

    cout << "Вхід: A\nMain: ";
    printReverseMain(test3);
    cout << "\nXвіст: ";
    printReverseTail(test3);
    cout << "\n\n";

    cout << "Вхід: рекурсія\nMain: ";
    printReverseMain(test4);
    cout << "\nXвіст: ";
    printReverseTail(test4);
    cout << "\n";

    return 0;
}