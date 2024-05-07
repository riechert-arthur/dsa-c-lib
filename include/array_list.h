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
    Data* array;
    int size;
    int capacity;
} ArrayList;

ArrayList* initialize_custom_al(size_t);
ArrayList* initialize_default_al(void);
int teardown_al(ArrayList*);
ArrayList* merge_als(ArrayList*, ArrayList*);
int add_al(ArrayList*, Data*);
int insert_al(ArrayList*, Data*, int);
int insert_to_front_al(ArrayList*, Data*);
int insert_to_back_al(ArrayList*, Data*);
Data* remove_al(ArrayList*, int);
Data* remove_from_front_al(ArrayList*);
Data* remove_from_back_al(ArrayList*);
Data* get_al(ArrayList*, int);
Data* get_front_al(ArrayList*);
Data* get_back_al(ArrayList*);
int is_empty_al(ArrayList*);
int increase_size_al(ArrayList*);
int decrease_size_al(ArrayList*);