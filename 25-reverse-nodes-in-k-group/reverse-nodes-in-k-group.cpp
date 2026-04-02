class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      //base case
    ListNode* check=head;
    for(int i=0;i<k;i++){
        if(check==NULL) return head;
        check=check->next;
    }
       
      //revese first k-node
      ListNode* next=NULL;
      ListNode* curr=head;
      ListNode* prev=NULL;
      int count=0;
      while(curr !=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
      }
      //handle recursion rest
      if(next!=NULL){
        head->next=reverseKGroup(next,k);
      }
      //return the head of linked list
      return prev;
    }
};