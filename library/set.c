#include <stdlib.h>
#include <assert.h>
#include "../include/set.h"
#include "../include/utility.h"

typedef struct set {
  list_t *list;
} set_t;

set_t *set_init(size_t initial_size, free_func_t freer, stringify_func_t stringifyer, compare_func_t comparer) {
    set_t *set = malloc(sizeof(set_t));
    assert(set != NULL);
    set->list = list_init(initial_size, freer, stringifyer, comparer);
    return set;
}

void set_free(set_t *set) {
    list_free(set->list);
    free(set);
}

size_t set_size(set_t *set) {
    return list_size(set->list);
}

void *set_get(set_t *set, size_t index) {
    return list_get(set->list, index);
}

void set_add(set_t *set, void *value) {
    if (set_size(set) == 0) {
        list_add(set->list, value);
        return;
    }
    size_t low = 0;
    size_t high = set_size(set) - 1;
    while (high - low > 1) {
        size_t mid = (low + high) / 2;
        void *mid_element = set_get(set, mid);
        int comparison = list_compare_element(set->list, value, mid_element);
        if (comparison == 0) {
            return;
        } else if (comparison > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    void *low_element = set_get(set, low);
    void *high_element = set_get(set, high);
    int low_comparison = list_compare_element(set->list, value, low_element);
    int high_comparison = list_compare_element(set->list, value, high_element);
    if (low_comparison == 0 || high_comparison == 0) {
        return;
    } else if (low_comparison < 0) {
        list_insert(set->list, value, low);
    } else if (high_comparison < 0) {
        list_insert(set->list, value, high);
    } else {
        list_insert(set->list, value, high + 1);
    }
}

void *set_remove(set_t *set, size_t index) {
    return list_remove(set->list, index);
}

void set_clear(set_t *set) {
    list_clear(set->list);
}

char *set_stringify(set_t *set) {
    return list_stringify(set->list);
}

int set_index_of(set_t *set, void *element) {
    if (set_size(set) == 0) {
        return -1;
    }
    size_t low = 0;
    size_t high = set_size(set) - 1;
    while (low <= high) {
        size_t mid = (low + high) / 2;
        void *mid_element = set_get(set, mid);
        int comparison = list_compare_element(set->list, element, mid_element);
        if (comparison == 0) {
            return mid;
        } else if (comparison > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

bool set_contains(set_t *set, void *element) {
    return set_index_of(set, element) != -1;
}

int set_compare_element(set_t *set, void *element1, void *element2) {
    return list_compare_element(set->list, element1, element2);
}

int set_compare(set_t *set1, set_t *set2) {
    return list_compare(set1->list, set2->list);
}

void *set_max(set_t *set) {
    return list_get(set->list, set_size(set) - 1);
}

void *set_min(set_t *set) {
    return list_get(set->list, 0);
}

set_t *set_copy(set_t *set) {
    set_t *copy = malloc(sizeof(set_t));
    assert(copy != NULL);
    copy->list = list_copy(set->list);
    return copy;
}