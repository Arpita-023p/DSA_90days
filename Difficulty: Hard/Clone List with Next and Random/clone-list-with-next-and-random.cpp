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
        if (head == NULL) return NULL;

        // Step 1: Create a clone linked list (Standard Copy)
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // Step 2: Interweave: originalNode -> cloneNode -> originalNode->next
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL) {
            Node* nextOriginal = originalNode->next;
            originalNode->next = cloneNode;
            
            Node* nextClone = cloneNode->next;
            cloneNode->next = nextOriginal;
            
            originalNode = nextOriginal;
            cloneNode = nextClone;
        }

        // Step 3: Copy the random pointers
        temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                // temp->next is the clone node, temp->random->next is its clone counterpart
                temp->next->random = (temp->random != NULL) ? temp->random->next : NULL;
            }
            // Move two steps because of interweaving
            temp = temp->next->next;
        }

        // Step 4: Revert changes (Detach the lists)
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if (originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        // Step 5: Return the cloned head
        return cloneHead;
    }
};