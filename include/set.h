#ifndef __SET_H__
#define __SET_H__

#include "list.h"

typedef struct set set_t;

set_t *set_init(size_t initial_size, free_func_t freer, print_func_t printer, compare_func_t comparer);

void set_free(set_t *set);

size_t set_size(set_t *set);

void *set_get(set_t *set, size_t index);

void set_add(set_t *set, void *value);

void *set_remove(set_t *set, size_t index);

void set_clear(set_t *set);

void set_print(set_t *set);

int set_index_of(set_t *set, void *element);

bool set_contains(set_t *set, void *element);

int set_compare_element(set_t *set, void *element1, void *element2);

int set_compare(set_t *set1, set_t *set2);

void *set_max(set_t *set);

void *set_min(set_t *set);

set_t *set_copy(set_t *set);

#endif // #ifndef __SET_H__
