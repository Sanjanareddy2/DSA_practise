//Merge sort for linked list
class Solution {
public:
    void printList(ListNode* node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}
    void divide(ListNode* head,ListNode** a,ListNode** b){
        ListNode*slow=head,*fast=head->next;
        while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
        *a=head;
        *b = slow->next;
        slow->next=NULL;
        
    }
    ListNode* merge(ListNode*a,ListNode*b){
        
        ListNode*sol=NULL;
        if(a==NULL) return b;
        if(b==NULL) return a;
        if(a->val<b->val){
            sol = a;
            sol->next = merge(a->next,b);
        }
        else{
            sol = b;
            sol->next = merge(a,b->next);
        }
        return sol;
    }
    void mergesort(ListNode** head){
        //cout << "lst: ";printList(*head);
        ListNode *h = *head;
        ListNode *a,*b;
        if(h==NULL ||h->next==NULL) return ;
        divide(h,&a,&b);
        
        mergesort(&a);
        mergesort(&b);
        *head = merge(a,b);
    }
    ListNode* sortList(ListNode* head) {
        mergesort(&head);
        return head;
    }
};