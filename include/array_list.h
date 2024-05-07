#include <stddef.h>

#define INITIAL_CAPACITY 19
#define RESIZE_FACTOR 2

#define SUCCESS 1
#define FAILURE 0

typedef struct {
    void* data;
    size_t size;
} Data;

typedef struct {
    Data* array;
    int size;
    int capacity;
} ArrayList;

ArrayList* initialize_custom_arraylist(size_t);
ArrayList* initialize_default_arraylist(void);
int teardown_arraylist(ArrayList*);
ArrayList* merge_arraylists(ArrayList*, ArrayList*);
int add(ArrayList*, Data*);
int insert(ArrayList*, Data*, int);
int insert_to_front(ArrayList*, Data*);
int insert_to_back(ArrayList*, Data*);
Data* remove(ArrayList*, int);
Data* remove_from_front(ArrayList*);
Data* remove_from_back(ArrayList*);
Data* get(ArrayList*, int);
int increase_size(ArrayList*);
int decrease_size(ArrayList*);