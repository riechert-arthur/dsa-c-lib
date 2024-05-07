#include "../include/array_list.h"

ArrayList* initialize_custom_arraylist(size_t capacity) {
    
    ArrayList* arr;

    if (!(arr = (ArrayList*) malloc(sizeof(ArrayList)))) {
        return NULL;
    }

    Data* temp;
    int initial_size = capacity * sizeof(Data);

    if (!(temp = (Data*) malloc(initial_size))) {
        free(arr);
        return NULL;
    }

    arr->array = temp;
    arr->capacity = capacity;
    arr->size = 0;

    return arr;
}

ArrayList* initialize_default_arraylist() {
    return initialize_custom_arraylist(INITIAL_CAPACITY);
}

int teardown_arraylist(ArrayList* arr) {

    if (arr == NULL) {
        return FAILURE;
    }

    if (arr->array != NULL) {
        free(arr->array);
    }

    free(arr);
    return SUCCESS;
}

ArrayList* merge_arraylists(ArrayList* arr1, ArrayList* arr2) {

    if(arr1 == NULL || arr2 == NULL) {
        return FAILURE;
    }

    size_t new_size = ((size_t) (arr1->capacity + arr2->capacity)) * sizeof(Data);

    ArrayList* arr3;
    
    if (!(arr3 = initialize_custom_arraylist(new_size))) {
        return FAILURE;
    }

    for (int i = 0; i < arr1->size; ++i) {
        arr3[i] = arr1[i];
    }

    for (int j = 0; j < arr2->size; ++j) {
        arr3[arr1->size + j] = arr2[j];
    }

    arr3->size = arr1->size + arr2->size;

    return arr3;
}

int add(ArrayList* arr, Data* data) {

    if (arr == NULL || data == NULL) return FAILURE;

    if (arr->size >= arr->capacity) {
        if(!increase_size(arr)) return FAILURE;
    }

    arr->array[arr->size] = *data;
    ++arr->size;

    return SUCCESS;
}

int insert(ArrayList* arr, Data* data, int index) {

    if (arr == NULL || data == NULL || index < 0 || index > arr->size) {
        return FAILURE;
    }

    if (arr->size >= arr->capacity) {
        if(!increase_size(arr)) return FAILURE;
    }

    for (int i = arr->size; i > index; --i) {
        arr->array[i] = arr->array[i - 1];
    }

    arr->array[index] = *data;
    ++arr->size;

    return SUCCESS;
}

int insert_to_front(ArrayList* arr, Data* data) {
    return insert(arr, data, 0);
}

int insert_to_back(ArrayList* arr, Data* data) {
    return insert(arr, data, arr->size);
}

Data* remove(ArrayList* arr, int index) {

    if (arr == NULL || arr->size == 0) {
        return NULL;
    }

    if (arr->size < arr->capacity / RESIZE_FACTOR - 1) {
        if(!decrease_size(arr)) return NULL;
    }

    Data* removed = &arr->array[index];

    for (int i = index; i < arr->size; ++i) {
        arr->array[i] = arr->array[i + 1];
    }

    --arr->size;

    return removed;
}

Data* remove_from_front(ArrayList* arr) {
    return remove(arr, 0);
}

Data* remove_from_back(ArrayList* arr) {
    return remove(arr, arr->size - 1);
}

Data* get(ArrayList* arr, int index) {

    if (arr == NULL || index < 0 || index >= arr->size) {
        return NULL;
    }

    return &arr->array[index];
}

int increase_size(ArrayList* arr) {

    if (arr == NULL) return FAILURE;

    size_t new_size = (RESIZE_FACTOR * ((size_t) arr->capacity)) * sizeof(Data);

    Data* temp;

    if (!(temp = (Data*) realloc(arr->array, new_size))) {
        return FAILURE;
    }

    arr->array = temp;
    arr->capacity *= RESIZE_FACTOR;

    return SUCCESS;
}

int decrease_size(ArrayList* arr) {

    if (arr == NULL) return FAILURE;

    size_t new_size = (((size_t) arr->capacity) / RESIZE_FACTOR) * sizeof(Data);

    Data* temp;

    if (!(temp = (Data*) realloc(arr->array, new_size))) {
        return FAILURE;
    }

    arr->array = temp;
    arr->capacity /= RESIZE_FACTOR;

    return SUCCESS;
}