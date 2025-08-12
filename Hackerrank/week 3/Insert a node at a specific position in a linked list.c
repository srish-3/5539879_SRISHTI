SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    newNode->next = NULL;

    
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }

    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {

        return llist;
    }

    newNode->next = current->next;
    current->next = newNode;

    return llist;
}