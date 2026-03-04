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