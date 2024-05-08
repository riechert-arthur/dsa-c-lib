#include "../include/bst.h"

BST* initialize_bst() {

    BST* bst;

    if (!(bst = (BST*) malloc(sizeof(BST)))) {
        return NULL;
    }

    return bst;
}

int add_bst(BST* bst, void* data) {

    if (bst == NULL || data == NULL) {
        return FAILURE;
    }

    return add_bst_r(bst->root, data, bst->compare);
}

int add_bst_r(Node* root, void* data, int (*compare)(void*, void*)) {

    if (root == NULL) {
        Node* node;
        if (!(node = alloc_node(data))) return FAILURE;
        
        *root = *node;
        return SUCCESS;
    }

    int result = compare(data, root->data);

    if (result < 0) return add_bst_r(root->left, data, compare);
    else if (result > 0) return add_bst_r(root->right, data, compare);
    else return FAILURE;
}

Node* alloc_node(void* data) {

    if (data == NULL) {
        return NULL;
    }

    Node* node;

    if (!(node = (Node*) malloc(sizeof(Node)))) {
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;
    node->data = data;

    return node;
}