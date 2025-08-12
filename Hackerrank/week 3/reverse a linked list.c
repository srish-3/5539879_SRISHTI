SinglyLinkedListNode* reverse(SinglyLinkedListNode * head) {
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}