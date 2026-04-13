#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int data;
    Node* next;
    Node* random;
    
    Node(int _data) {
        data = _data;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* cloneLinkedList(Node* head) {
        // Step 1: Create a clone linked list (basic structure)
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // Step 2: Create a mapping between original nodes and cloned nodes
        unordered_map<Node*, Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // Step 3: Link the random pointers using the map
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL) {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

// Helper function to print the list for testing
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        int randomData = (temp->random) ? temp->random->data : -1;
        cout << "Data: " << temp->data << ", Random points to: " << randomData << endl;
        temp = temp->next;
    }
}

int main() {
    // Create a simple list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Set some random pointers
    head->random = head->next->next; // 1 points to 3
    head->next->random = head;       // 2 points to 1

    Solution sol;
    Node* clonedList = sol.cloneLinkedList(head);

    cout << "Original List:" << endl;
    printList(head);

    cout << "\nCloned List:" << endl;
    printList(clonedList);

    return 0;
}