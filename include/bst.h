#include <stddef.h>

#define SUCCESS 1
#define FAILURE 0

#define EMPTY 1
#define NOT_EMPTY 0

typedef struct {
    void* data;
    Node* left;
    Node* right;
} Node;

typedef struct {
    Node* root;
    int (*compare) (void*, void*);
} BST;

BST* initialize_bst(void);
int add_bst(BST*, void*);
int add_bst_r(Node*, void*, int (*compare) (void*, void*));
Node* remove_bst(BST*, void*);