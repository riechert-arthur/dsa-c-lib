#include "../include/stack.h"

    
Stack* initialize_arraylist_st() {

    Stack* stack;

    if (!(stack = (Stack*) malloc(sizeof(Stack)))) {
        return NULL;
    }

    ArrayList* temp;

    if (!(temp = initialize_default_arraylist())) {
        free(stack);
        return NULL;
    }

    stack->add = &insert_to_back_al;
    stack->initialize_backing_structure = &initialize_default_al;
    stack->is_empty = &is_empty_al;
    stack->peek = &get_back_al;
    stack->pop = &remove_from_back_al;
    stack->teardown_backing_structure = &teardown_al;
    stack->backing_structure = temp;

    return stack;
}

Stack* initialize_linkedlist_st() {

    Stack* stack;

    if (!(stack = (Stack*) malloc(sizeof(Stack)))) {
        return NULL;
    }

    LinkedList* temp;

    if (!(temp = initialize_linkedlist())) {
        free(stack);
        return NULL;
    }

    stack->add = &insert_to_front_ll;
    stack->initialize_backing_structure = &initialize_ll;
    stack->is_empty = &is_empty_ll;
    stack->peek = &get_front_ll;
    stack->pop = &remove_from_front_ll;
    stack->teardown_backing_structure = &teardown_ll;
    stack->backing_structure = temp;

    return stack;
}

void* pop_st(Stack* stack) {

    if (!stack) return NULL;

    return stack->pop(stack->backing_structure);
}

int add_st(Stack* stack, void* data) {

    if (!stack) return FAILURE;

    return stack->add(stack->backing_structure, data);
}

void* peek_st(Stack* stack) {

    if (!stack) return NULL;

    return stack->peek(stack->backing_structure);
}