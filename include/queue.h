#include <stddef.h>

#define INITIAL_CAPACITY 19
#define RESIZE_FACTOR 2

#define SUCCESS 1
#define FAILURE 0

#define EMPTY 1
#define NOT_EMPTY 0

typedef struct {
    void* data;
    size_t size;
} Data;

typedef struct {
    Data* arr;
    int size;
    int capacity;
    int first;
    int last;
} Queue;

Queue* intialize_q(void);
Data* dequeue_q(Queue*);
Data* peek_q(Queue*);
void enqueue_q(Queue*, void*);