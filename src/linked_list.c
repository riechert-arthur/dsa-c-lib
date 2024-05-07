#include "../include/linked_list.h"

LinkedList* initialize_ll() {

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

int teardown_ll(LinkedList* list) {

    if (list == NULL) {
        return FAILURE;
    }

    Node* curr = list->head;

    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        if (!dealloc_node_ll(temp)) return FAILURE;
    }

    list->head = NULL;
    free(list);

    return SUCCESS;
}

LinkedList* merge_lls(LinkedList* list1, LinkedList* list2) {

    if (list1 == NULL || list2 == NULL) {
        return FAILURE;
    }

    Node* curr = list1->head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = list2->head;

    return curr;
}

int insert_ll(LinkedList* list, void* data, int index) {

    if (list == NULL || data == NULL || index < 0 || index > list->size) {
        return FAILURE;
    }

    Node* curr = list->head;

    Node* new = alloc_node_ll(data);
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

int insert_to_front_ll(LinkedList* list, void* data) {
    return insert_ll(list, data, 0);
}

int insert_to_back_ll(LinkedList* list, void* data) {
    return insert_ll(list, data, list->size);
}

Node* remove_ll(LinkedList* list, Node* node, int (*equals)(void*, void*)) {

    if (list == NULL || node == NULL) {
        return NULL;
    }

    if (equals == NULL) {
        equals = &default_equals_ll;
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

Node* remove_at_index_ll(LinkedList* list, int index) {

    if (list == NULL || index < 0 || index >= list->size) {
        return NULL;
    }

    Node* curr = list->head;

    if (index == 0) {
        Node* removed = curr;
        list->head = curr->next;
        dealloc_node_ll(curr);
        return curr;
    }

    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }

    Node* removed = curr->next;
    curr->next = curr->next->next;
    dealloc_node_ll(curr->next);
    --list->size;

    return removed;
}

Node* remove_from_front_ll(LinkedList* list) {
    return remove_at_index_ll(list, 0);
}

Node* remove_from_back_ll(LinkedList* list) {
    return remove_at_index_ll(list, list->size);
}

Node* get_ll(LinkedList* list, void* data, int (*equals)(void*, void*)) {

    if (list == NULL || data == NULL) {
        return NULL;
    }

    if (equals == NULL) {
        equals = &default_equals_ll;
    }

    Node* curr = list->head;

    while (curr != NULL) {
        if (equals(curr->data, data)) return curr;
        curr = curr->next;
    }

    return NULL;
}

Node* get_at_index_ll(LinkedList* list, int index) {

    if (list == NULL || index < 0 || index >= list->size) {
        return NULL;
    }

    Node* curr = list->head;

    for (int i = 0; i <= index; ++i) {
        curr = curr->next;
    }

    return curr;
}

Node* get_back_ll(LinkedList* list) {
    return get_at_index_ll(list, list->size);
}

Node* get_front_ll(LinkedList* list) {
    return get_at_index_ll(list, 0);
}

int is_empty_ll(LinkedList* list) {

    if (list == NULL) {
        return EMPTY;
    }

    if (list->size == 0) {
        return EMPTY;
    } else {
        return NOT_EMPTY;
    }
}

Node* alloc_node_ll(void* data) {
    
    if (data == NULL) return NULL;

    Node* new;

    if (!(new = (Node*) malloc(sizeof(Node)))) {
        return NULL;
    }

    return new;
}

int dealloc_node_ll(Node* node) {

    if (node) {
        if (node->data) free(node->data);
        free(node);
    }

    return SUCCESS;
}

int default_equals_ll(void* node1, void* node2) {
    return node1 == node2;
}