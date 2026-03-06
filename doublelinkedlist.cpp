#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for the node data will be " << val << endl;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getlen(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    return len;
}
void insertAthead(Node *&head, int data)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAttail(Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void inserttposition(Node *&head, Node *&tail, int position, int data)
{
    // starting at 1st
    if (position == 1)
    {
        insertAthead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt <= position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // insert at last position
    if (temp->next == NULL)
    {
        insertAttail(head, data);
        return;
    }
    // creating node for data
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
    temp->next->prev = NULL; 
    head = temp->next;      
    temp->next = NULL;       
    delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAthead(head, 11);
    print(head);
    insertAthead(head, 45);
    print(head);
    insertAttail(tail, 89);
    print(head);
    inserttposition(head, tail, 2, 13);
    print(head);
    inserttposition(head, tail, 3, 46);
    print(head);
    deleteNode(1,head);
    print(head);
    cout<<"Head is "<<head->data<<endl;
    cout<<"Tail is "<<tail->data<<endl;
}