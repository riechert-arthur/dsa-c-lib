#include "../include/linked_list.h"

LinkedList* initialize_linkedlist() {

    LinkedList* list;

    if (!(list = (LinkedList*) malloc(sizeof(LinkedList)))) {
        return NULL;
    }

    Node* head;

    if (!(head = (Node*) malloc(sizeof(Node)))) {
        free(list);
        return NULL;
    }

    list->head = head;
    list->size = 0;
    
    return list;
}

int insert(LinkedList* list, void* data, int index) {

    if (list == NULL || data == NULL || index < 0 || index > list->size) {
        return FAILURE;
    }

    Node* curr = list->head;

    Node* new = alloc_node(data);
    new->size = sizeof(*data);

    if (index == 0) {
        new->next = list->head;
        list->head = new;
        ++list->size;
        return SUCCESS;
    }

    for (int i = 0; i < index - 1; ++i) {
        curr = curr->next;
    }

    new->next = curr->next->next;
    curr->next = new;
    ++list->size;

    return SUCCESS;
}

int insert_to_front(LinkedList* list, void* data) {
    return insert(list, data, 0);
}

int insert_to_back(LinkedList* list, void* data) {
    return insert(list, data, list->size);
}

Node* remove(LinkedList* list, Node* node, int (*equals)(void*, void*)) {

    if (list == NULL || node == NULL) {
        return NULL;
    }

    if (equals == NULL) {
        equals = &default_equals;
    }

    Node* curr = list->head;

    while(curr->next != NULL) {
        if (equals(curr->next->data, node->data)) {
            Node* removed = curr->next;
            curr->next = curr->next->next;
            --list->size;
            return removed;
        }
        curr = curr->next;
    }

    return NULL;
}

Node* remove_at_index(LinkedList* list, int index) {

    if (list == NULL || index < 0 || index >= list->size) {
        return NULL;
    }

    Node* curr = list->head;

    if (index == 0) {
        Node* removed = curr;
        list->head = curr->next;
        dealloc_node(curr);
        return curr;
    }

    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }

    Node* removed = curr->next;
    curr->next = curr->next->next;
    dealloc_node(curr->next);
    --list->size;

    return removed;
}

Node* remove_from_front(LinkedList* list) {
    return remove_at_index(list, 0);
}

Node* remove_from_back(LinkedList* list) {
    return remove_at_index(list, list->size);
}

Node* get(LinkedList* list, void* data, int (*equals)(void*, void*)) {

    if (list == NULL || data == NULL) {
        return NULL;
    }

    if (equals == NULL) {
        equals = &default_equals;
    }

    Node* curr = list->head;

    while (curr != NULL) {
        if (equals(curr->data, data)) return curr;
        curr = curr->next;
    }

    return NULL;
}

Node* get_at_index(LinkedList* list, int index) {

    if (list == NULL || index < 0 || index >= list->size) {
        return NULL;
    }

    Node* curr = list->head;

    for (int i = 0; i <= index; ++i) {
        curr = curr->next;
    }

    return curr;
}

Node* alloc_node(void* data) {
    
    if (data == NULL) return NULL;

    Node* new;

    if (!(new = (Node*) malloc(sizeof(Node)))) {
        return NULL;
    }

    return new;
}

int dealloc_node(Node* node) {

    if (node) {
        if (node->data) free(node->data);
        free(node);
    }

    return SUCCESS;
}

int default_equals(void* node1, void* node2) {
    return node1 == node2;
}