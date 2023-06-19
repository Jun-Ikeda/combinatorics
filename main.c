#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "./include/utility.h"
#include "./include/list.h"
#include "./include/set.h"
#include "./include/combinatorics.h"

int main(const int argc, const char* argv[]) {
    int n_max = 10000;
    set_t *numbers = get_numbers(n_max);
    // list_t *memos = list_init(n_max, free, (print_func_t) list_print, (stringify_func_t) list_to_string, (compare_func_t) list_compare);

    // FILE *fp = fopen("memo.csv", "w");
    // set_t *convex_sets = all_convex_sets(n_max, numbers, memos, fp);
    // fclose(fp);

    // printf("convex_sets size: %d\n", set_size(convex_sets));
    // set_print(convex_sets);
    // list_free(memos);
    // set_free(numbers);

    set_t *convex_set = get_random_convex_set(n_max, numbers, 15);
    set_print(convex_set);
    set_free(convex_set);

    return 0;
}
