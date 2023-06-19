#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./include/utility.h"
#include "./include/list.h"
#include "./include/set.h"

void set_add_int(set_t *set, int value) {
    int *value_ptr = malloc(sizeof(int));
    *value_ptr = value;
    set_add(set, value_ptr);
}

list_t *all_convex_sets(int n_max, set_t *numbers, list_t *memos) {
    if (list_size(memos) >= n_max) {
        return list_get(memos, n_max - 1);
    }
    list_t *sets = list_init(2, free, (stringify_func_t)set_stringify, (compare_func_t)set_compare);
    if (n_max == 1) {
        set_t *empty = set_init(1, NULL, stringify_int, compare_int);
        list_add(sets, empty);
        set_t *one = set_init(1, NULL, stringify_int, compare_int);
        set_add(one, set_get(numbers, 1));
        list_add(sets, one);
    } else {
        list_t *subsets = all_convex_sets(n_max - 1, numbers, memos);
        for (size_t i = 0; i < list_size(subsets); i++) {
            set_t *subset = list_get(subsets, i);
            size_t subset_size = set_size(subset);
            list_add(sets, subset);
            if (set_size(subset) < 2 || n_max + *(int *)set_get(subset, subset_size - 2) > *(int *)set_get(subset, subset_size - 1) * 2) {
                set_t *new_subset = set_copy(subset);
                set_add(new_subset, set_get(numbers, n_max));
                list_add(sets, new_subset);
            }
        }
    }
    list_add(memos, sets);
    return sets;
}

int main(const int argc, const char* argv[]) {
    // FILE *fp = fopen("output.csv", "w");
    int n_max = 6;
    list_t *memos = list_init(n_max, free, (stringify_func_t) list_stringify, (compare_func_t) list_compare);
    set_t *numbers = set_init(n_max + 1, free, stringify_int, compare_int);
    for (size_t i = 0; i < n_max + 1; i++) {
        set_add_int(numbers, i);
    }
    list_t *convex_sets = all_convex_sets(n_max, numbers, memos);
    printf("sets size: %d\n", list_size(convex_sets));
    printf("sets: %s\n", list_stringify(convex_sets));
    // fprintf(fp, "n,convex sets\n");
    // fclose(fp);

    list_free(convex_sets);
    set_free(numbers);
    return 0;
}
