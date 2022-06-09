//reverse a linked list
void reverse(Node** head){
    Node* cur = *head,prev=NULL,nxt = NULL;
    while(cur!=NULL){
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur=nxt;
    }
    *head = prev;
}