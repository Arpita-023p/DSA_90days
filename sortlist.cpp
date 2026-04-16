#include <iostream>
using namespace std;

// Class structure for the Node
class Node {
public:
    int data;
    Node *next;
    
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data; 
        this->next = NULL;
    }
};

// Function to sort the list of 0s, 1s, and 2s
Node* sortList(Node *head) {
    if (head == NULL) return NULL;

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    Node* temp = head;
    
    // Phase 1: Count occurrences
    while (temp != NULL) {
        if (temp->data == 0) zeroCount++;
        else if (temp->data == 1) oneCount++;
        else if (temp->data == 2) twoCount++;
        temp = temp->next;
    }

    // Phase 2: Update data based on counts
    temp = head;
    while (temp != NULL) {
        if (zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        } 
        else if (oneCount > 0) {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount > 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next; // Move to next node
    }
    
    return head; // Return head AFTER the loop finishes
}

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a dummy list: 1 -> 2 -> 0 -> 1 -> 0
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}