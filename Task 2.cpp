#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Головна рекурсія
ListNode* swapPairsMain(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* first = head;
    ListNode* second = head->next;

    first->next = swapPairsMain(second->next);
    second->next = first;

    return second;
}

// Хвостова рекурсія
ListNode* swapPairsTail(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* first = head;
    ListNode* second = head->next;

    first->next = swapPairsTail(second->next);
    second->next = first;

    return second;
}

void printList(ListNode* head) {
    if (!head)
        return;

    cout << head->val << " ";
    printList(head->next);
}

void deleteList(ListNode* head) {
    if (!head)
        return;

    deleteList(head->next);
    delete head;
}

int main() {

    cout << "===== ТЕСТОВІ ПАРИ ОБМІНУ =====\n";

    // Тест 1: [1,2,3,4]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "Оригінал: ";
    printList(head1);

    ListNode* swapped1 = swapPairsMain(head1);

    cout << "\nОсновний поміняний: ";
    printList(swapped1);

    ListNode* swapped2 = swapPairsTail(swapped1);

    cout << "\nХвіст закинутий назад: ";
    printList(swapped2);
    cout << "\n\n";

    deleteList(swapped2);

    // Тест 2: []
    ListNode* head2 = nullptr;
    cout << "Порожній список: ";
    printList(head2);
    cout << "\nПоміняно місцями: ";
    printList(swapPairsMain(head2));
    cout << "\n\n";

    // Тест 3: [1]
    ListNode* head3 = new ListNode(1);
    cout << "Одиночний вузол: ";
    printList(head3);

    ListNode* swapped3 = swapPairsMain(head3);

    cout << "\nПоміняно місцями: ";
    printList(swapped3);
    cout << "\n";

    deleteList(swapped3);

    return 0;
}