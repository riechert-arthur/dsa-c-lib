#include <stddef.h>

#define SUCCESS 1
#define FAILURE 0

#define EMPTY 1
#define NOT_EMPTY 0

typedef struct {
    void* data;
    Node* next;
    size_t size;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

LinkedList* initialize_ll(void);
int teardown_ll(LinkedList*);
int insert_ll(LinkedList*, void*, int);
int insert_to_front_ll(LinkedList*, void*);
int insert_to_back_ll(LinkedList*, void*);
Node* remove_ll(LinkedList*, Node*, int (*equals)(void*, void*));
Node* remove_at_index_ll(LinkedList*, int);
Node* remove_from_front_ll(LinkedList*);
Node* remove_from_back_ll(LinkedList*);
Node* get_ll(LinkedList*, void*, int (*equals)(void*, void*));
Node* get_at_index_ll(LinkedList*, int);
Node* get_front_ll(LinkedList*);
Node* get_back_ll(LinkedList*);
int is_empty_ll(LinkedList*);
int dealloc_node_ll(Node*);