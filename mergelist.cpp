#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// The Node class must be defined or included for VS Code to compile
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

void solve(Node<int>* first, Node<int>* second) {
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = NULL;

    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            // Stitching the node from second list into first list
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL) {
                curr1->next = curr2;
                return;
            }
        }
    }
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data <= second->data) {
        solve(first, second);
        return first;
    } else {
        solve(second, first);
        return second;
    }
}
int main() {
    // 1. Create List 1: 1 -> 3 -> 5
    Node<int>* first = new Node<int>(1);
    first->next = new Node<int>(3);
    first->next->next = new Node<int>(5);

    // 2. Create List 2: 2 -> 4 -> 6
    Node<int>* second = new Node<int>(2);
    second->next = new Node<int>(4);
    second->next->next = new Node<int>(6);

    // 3. Merge them
    Node<int>* mergedHead = sortTwoLists(first, second);

    // 4. Print result
    Node<int>* temp = mergedHead;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}