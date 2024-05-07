#include "linked_list.h"
#include "array_list.h"

typedef struct {
    int (*add) (void*, void*);
    void* (*pop) (void*);
    void* (*peek) (void*);
    void* (*initialize_backing_structure) (void);
    int (*teardown_backing_structure) (void*);
    int (*is_empty) (void*);
    void* backing_structure;
} Stack;

Stack* initialize_arraylist_st(void);
Stack* initialize_linkedlist_st(void);
void* pop_st(Stack*);
void* peek_st(Stack*);
void add_st(Stack*, void*);