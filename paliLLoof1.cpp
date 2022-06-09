//https://leetcode.com/problems/palindrome-linked-list/
bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next) {//split into two halves while the first half can be one-node longer;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode newHead(0); //reverse the second half;
    ListNode *next = NULL, *p = fast;
    while(p) {
        next = p->next;
        p->next = newHead.next;
        newHead.next = p;
        p = next;
    }
    fast = newHead.next; //compare the two lists;
    while(fast) {
        if(fast->val != head->val) return false;
        fast = fast->next;
        head = head->next;
    }
    return fast == NULL;
}