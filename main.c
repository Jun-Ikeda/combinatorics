#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "./include/utility.h"
#include "./include/list.h"
#include "./include/set.h"

const int N_MAX_DIGIT = 5;
const int N_MAX_MAX = 1000;
const int CSV_LINE_MAX = 10000;

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

int main(const int argc, const char* argv[]) {
    int n_max = 20;
    set_t *numbers = get_numbers(n_max);
    // FILE *fp = fopen("memo.csv", "r");
    list_t *memos = list_init(n_max, free, (print_func_t) list_print, (stringify_func_t) list_to_string, (compare_func_t) list_compare);
    // char line[CSV_LINE_MAX];
    // fgets(line, CSV_LINE_MAX, fp);
    // while(fgets(line, CSV_LINE_MAX, fp) != NULL) {
    //     printf("\nline: %s", line);
    //     set_t *sets = set_init(n_max, free, (print_func_t) set_print, (stringify_func_t) set_to_string, (compare_func_t) set_compare);
    //     char line_copy[strlen(line) + 1];
    //     strcpy(line_copy, line);
    //     char *cell = strtok(line_copy, "\t");
    //     cell = strtok(NULL, "\t");
    //     cell = strtok(NULL, "\t");
    //     set_t *set_null = set_init(1, NULL, print_int, int_to_string, compare_int);
    //     set_add(sets, set_null);
    //     while (cell != NULL) {
    //         printf("cell: %s\n", cell);
    //         char cell_copy[strlen(cell) + 1];
    //         strcpy(cell_copy, cell);
    //         char *set_text = strtok(cell_copy, ".");
    //         printf("set_text: %s\n", set_text);
    //         while (set_text != NULL) {
    //             printf("set: %s\n", set_text);
    //             set_t *set = set_init(n_max, free, print_int, int_to_string, compare_int);
    //             set_import_int(set, set_text, ",");
    //             set_add(sets, set);
    //             set_text = strtok(NULL, ".");
    //         }
    //         cell = strtok(NULL, "\t");
    //     }
    //     // list_import_int(memo, str, "\t");
    //     // list_add(memos, memo);
	// 	// printf("%s", str);
	// }
    // fclose(fp);

    FILE *fp = fopen("memo.csv", "w");
    set_t *convex_sets = all_convex_sets(n_max, numbers, memos, fp);
    fclose(fp);

    // printf("convex_sets size: %d\n", set_size(convex_sets));
    // list_free(memos);
    // set_free(numbers);

    // set_t *import_test = set_init(5, free, print_int, int_to_string, compare_int);
    // set_import_int(import_test, "1,2,3,4,5,6,7,8,9,10", ",");
    // set_print(import_test);
    // printf("%s\n", set_to_string(import_test));

    // fprintf(fp, "size\\n_max\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\n");
    // fprintf(fp, "0\t%s", set_to_string(import_test));
    // fclose(fp);
    
    // set_free(import_test);


    return 0;
}
