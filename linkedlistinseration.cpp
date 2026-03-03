#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertATHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // insert at start
    if (position == 1)
    {
        insertATHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    // creating a node for data
    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    
    // head pointing tonode
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertATHead(head, 12);
    print(head);
    insertAtTail(tail, 23);
    print(head);
    insertAtPosition(head, tail, 4, 26);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
}