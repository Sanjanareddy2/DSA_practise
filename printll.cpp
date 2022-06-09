//print a linked list
//leetcode
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
//gfg
void printList(NodeList* node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}