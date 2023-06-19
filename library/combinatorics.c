#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "../include/combinatorics.h"
#include "../include/utility.h"

const int N_MAX_DIGIT = 5;
const int N_MAX_MAX = 1000;

double random_double() {
    return (double)rand() / RAND_MAX;
}

void set_add_int(set_t *set, int value) {
    int *value_ptr = malloc(sizeof(int));
    *value_ptr = value;
    set_add(set, value_ptr);
}

char *int_to_string(void *value) {
    int *value_ptr = value;
    char string[sizeof(char) * (N_MAX_DIGIT + 1)];
    sprintf(string, "%d", *value_ptr);
    return strdup(string);
}

set_t *get_numbers(int n_max) {
    set_t *numbers = set_init(n_max + 1, free,  print_int, int_to_string, compare_int);
    for (size_t i = 0; i < n_max + 1; i++) {
        set_add_int(numbers, i);
    }
    return numbers;
}

set_t *all_convex_sets(int n_max, set_t *numbers, list_t *memos, FILE *fp) {
    if (list_size(memos) >= n_max) {
        return list_get(memos, n_max - 1);
    }
    set_t *sets = set_init(2, free, (print_func_t)set_print, (stringify_func_t) set_to_string, (compare_func_t)set_compare);
    if (n_max == 1) {
        set_t *empty = set_init(1, NULL, print_int, int_to_string, compare_int);
        set_add(sets, empty);
        set_t *one = set_init(1, NULL, print_int, int_to_string, compare_int);
        set_add(one, set_get(numbers, 1));
        set_add(sets, one);
        fprintf(fp, "size\\n_max");
        for (size_t i = 0; i < N_MAX_MAX + 1; i++) {
            fprintf(fp, "\t%d", i);
        }
        fprintf(fp, "\n");
    } else {
        set_t *subsets = all_convex_sets(n_max - 1, numbers, memos, fp);
        for (size_t i = 0; i < set_size(subsets); i++) {
            set_t *subset = set_get(subsets, i);
            size_t subset_size = set_size(subset);
            set_add(sets, subset);
            if (set_size(subset) < 2 || n_max + *(int *)set_get(subset, subset_size - 2) > *(int *)set_get(subset, subset_size - 1) * 2) {
                set_t *new_subset = set_copy(subset);
                set_add(new_subset, set_get(numbers, n_max));
                set_add(sets, new_subset);
            }
        }
    }
    list_add(memos, sets);
    fprintf(fp, "%d\t", n_max);
    for (size_t i = 0; i < set_size(sets); i++) {
        fprintf(fp, "%s.", set_to_string(set_get(sets, i)));
        if (i < set_size(sets) - 1) {
            if (set_size(set_get(sets, i + 1)) > set_size(set_get(sets, i))) {
                fprintf(fp, "\t");
            }          
        }
    }
    fprintf(fp, "\n");
    return sets;
}

void list_import_int(list_t *list, char *data, char *separator) {
  char data_copy[strlen(data) + 1];
  strcpy(data_copy, data);
  assert(data_copy != NULL);
  char *token = strtok(data_copy, ",");
  while (token != NULL) {
    int *value = malloc(sizeof(int));
    *value = atoi(token);
    list_add(list, value);
    token = strtok(NULL, separator);
  }
}

void set_import_int(set_t *set, char *data, char *separator) {
  char data_copy[strlen(data) + 1];
  strcpy(data_copy, data);
  assert(data_copy != NULL);
  char *token = strtok(data_copy, ",");
  while (token != NULL) {
    int *value = malloc(sizeof(int));
    *value = atoi(token);
    set_add(set, value);
    token = strtok(NULL, separator);
  }
}

set_t *get_random_convex_set(int n_max, set_t *numbers, size_t size) {
    srand((unsigned)time(NULL));
    set_t *convex_set = set_init(size, free, print_int, int_to_string, compare_int);
    while (true) {
        set_clear(convex_set);
        while (set_size(convex_set) < 2) {
            set_add(convex_set, set_get(numbers, random_double() * (n_max + 1) / 10));
        }
        while (set_size(convex_set) < size) {
            int pre_dif = *(int *)set_get(convex_set, set_size(convex_set) - 1) - *(int *)set_get(convex_set, set_size(convex_set) - 2);
            int next_min = *(int *)set_get(convex_set, set_size(convex_set) - 1) + pre_dif + 1;

            if (next_min > n_max) {
                break;
            }
            // get random number between next_min and next_min + (n_max + 1) / 10
            int random = random_double() * (n_max + 1) / 10 + next_min;

            set_add(convex_set, set_get(numbers, random < n_max ? random : n_max));
            if (set_size(convex_set) == size) {
                return convex_set;
            }
        }
    }
    return convex_set;
}
