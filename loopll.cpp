/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null. Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?*/
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;   
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow != fast) return NULL;
    fast = head;
    while(fast && fast->next) {
        if(slow == fast) return slow;
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
}