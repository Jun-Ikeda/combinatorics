#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdbool.h>

typedef struct list list_t;

typedef void (*free_func_t)(void *);

typedef void (*print_func_t)(void *);

typedef char* (*stringify_func_t)(void *);

typedef int (*compare_func_t)(void *, void *);

list_t *list_init(size_t initial_size, free_func_t freer, print_func_t printer, stringify_func_t stringifier, compare_func_t comparer);

void list_free(list_t *list);

size_t list_size(list_t *list);

void *list_get(list_t *list, size_t index);

void list_add(list_t *list, void *value);

void *list_remove(list_t *list, size_t index);

void list_clear(list_t *list);

void list_print(list_t *list);

int list_index_of(list_t *list, void *element);

bool list_contains(list_t *list, void *element);

int list_compare_element(list_t *list, void *element1, void *element2);

int list_compare(list_t *list1, list_t *list2);

void list_insert(list_t *list, void *element, size_t index);

list_t *list_copy(list_t *list);

char *list_to_string(list_t *list);

#endif // #ifndef __LIST_H__
