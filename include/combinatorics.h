#ifndef __COMBINATORICS_H__
#define __COMBINATORICS_H__

#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "set.h"

void set_add_int(set_t *set, int value);

char *int_to_string(void *value);

set_t *get_numbers(int n_max);

set_t *all_convex_sets(int n_max, set_t *numbers, list_t *memos, FILE *fp);

void list_import_int(list_t *list, char *data, char *separator);

void set_import_int(set_t *set, char *data, char *separator);

set_t *get_random_convex_set(int n_max, set_t *numbers, size_t size);

#endif // #ifndef __COMBINATORICS_H__
