DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* temp = NULL;
    DoublyLinkedListNode* current = llist;

    while (current != NULL) {
        
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        llist = current;
        current = current->prev;
    }

    return llist;
}