#include "../include/queue.h"

Queue* initialize_q() {

    Queue* queue;

    if (!(queue = (Queue*) malloc(sizeof(Queue)))) {
        return NULL;
    }

    size_t initialize_size = INITIAL_CAPACITY * sizeof(Data);

    if (!(queue->arr = (Data*) malloc(initialize_size))) {
        free(queue);
        return NULL;
    }

    queue->first = 0;
    queue->last = 0;
    queue->capacity = INITIAL_CAPACITY;
    queue->size = 0;

    return queue;
}

Data* peek_q(Queue* queue) {

    if (!queue) return NULL;

    return queue->arr[queue->first];
}