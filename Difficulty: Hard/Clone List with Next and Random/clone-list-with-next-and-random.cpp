class Solution {
    private:
    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
         head=newNode;
         tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
  public:
    Node* cloneLinkedList(Node* head) {
       //create a clone linked list
       Node* cloneHead=NULL;
       Node* cloneTail=NULL;
       Node* temp=head;
       while(temp!=NULL){
           insertAtTail(cloneHead,cloneTail,temp->data);
           temp=temp->next;
       }
       //step2: create a mapping 
       unordered_map<Node*,Node*> oldToNewNode;
       Node* originalNode=head;
       Node* cloneNode=cloneHead;
       while(originalNode!=NULL && cloneNode!=NULL){
           oldToNewNode[originalNode]=cloneNode;
           originalNode=originalNode->next;
           cloneNode=cloneNode->next;
       }
       originalNode=head;
       cloneNode=cloneHead;
       while(originalNode!=NULL){
           cloneNode->random=oldToNewNode[originalNode->random];
           originalNode=originalNode->next;
           cloneNode=cloneNode->next;
       }
       return cloneHead;
    }
    
};