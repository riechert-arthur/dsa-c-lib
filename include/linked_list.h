#include <stddef.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct {
    void* data;
    Node* next;
    size_t size;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

LinkedList* initialize_linkedlist(void);
int insert(LinkedList*, void*, int);
int insert_to_front(LinkedList*, void*);
int insert_to_back(LinkedList*, void*);
Node* remove(LinkedList*, Node*, int (*equals)(void*, void*));
Node* remove_at_index(LinkedList*, int);
Node* remove_from_front(LinkedList*);
Node* remove_from_back(LinkedList*);
Node* get(LinkedList*, void*, int (*equals)(void*, void*));
Node* get_at_index(LinkedList*, int);
int dealloc_node(Node*);