#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../include/list.h"

typedef struct list {
    void **elements;
    size_t size;
    size_t capacity;
    free_func_t freer;
    stringify_func_t stringifyer;
    compare_func_t comparer;
} list_t;

list_t *list_init(size_t initial_size, free_func_t freer, stringify_func_t stringifyer, compare_func_t comparer) {
  assert(initial_size > 0);
  list_t *list = malloc(sizeof(list_t));
  assert(list != NULL);
  list->size = 0;
  list->capacity = initial_size;
  list->elements = malloc(sizeof(void *) * initial_size);
  assert(list->elements != NULL);
  list->freer = freer;
  list->stringifyer = stringifyer;
  list->comparer = comparer;
  return list;
}

void list_free(list_t *list) {
  free_func_t freer = list->freer;
  if (freer != NULL) {
    for (size_t i = 0; i < list->size; i++) {
      freer(list->elements[i]);
    }
  }
  free(list->elements);
  free(list);
}

size_t list_size(list_t *list) { return list->size; }

void *list_get(list_t *list, size_t index) {
  assert(index < list->size);
  return list->elements[index];
}

void list_add(list_t *list, void *value) {
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->elements = realloc(list->elements, sizeof(void *) * list->capacity);
    assert(list->elements != NULL);
  }
  list->elements[list->size] = value;
  list->size++;
}

void *list_remove(list_t *list, size_t index) {
  assert(list->size > 0);
  assert(index < list->size && index >= 0);
  void *temp = list->elements[index];
  list->size--;
  for (size_t i = index; i < list->size; i++) {
    list->elements[i] = list->elements[i + 1];
  }
  return temp;
}

void list_clear(list_t *list) {
  list->size = 0;
}

char *list_stringify(list_t *list) {
  char *output = "";
  strcat(output, "{ ");
  for (size_t i = 0; i < list->size; i++) {
    strcat(output, list->stringifyer(list->elements[i]));
    if (i < list->size - 1) {
      strcat(output, ", ");
    }
  }
  strcat(output, " }\n");
  return output;
}

int list_index_of(list_t *list, void *element) {
  for (size_t i = 0; i < list->size; i++) {
    if (list->comparer(list->elements[i], element) == 0) {
      return i;
    }
  }
  return -1;
}

bool list_contains(list_t *list, void *element) {
  return list_index_of(list, element) != -1;
}

int list_compare_element(list_t *list, void *element1, void *element2) {
  return list->comparer(element1, element2);
}

int list_compare(list_t *list1, list_t *list2) {
  if (list1->size < list2->size) {
    return -1;
  } else if (list1->size > list2->size) {
    return 1;
  } else {
    for (size_t i = 0; i < list1->size; i++) {
      int comparison = list1->comparer(list1->elements[i], list2->elements[i]);
      if (comparison != 0) {
        return comparison;
      }
    }
    return 0;
  }
}

void list_insert(list_t *list, void *element, size_t index) {
  assert(index >= 0 && index <= list->size);
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->elements = realloc(list->elements, sizeof(void *) * list->capacity);
    assert(list->elements != NULL);
  }
  for (size_t i = list->size; i > index; i--) {
    list->elements[i] = list->elements[i - 1];
  }
  list->elements[index] = element;
  list->size++;
}

list_t *list_copy(list_t *list) {
  list_t *copy = list_init(list->capacity, list->freer, list->stringifyer, list->comparer);
  for (size_t i = 0; i < list->size; i++) {
    list_add(copy, list->elements[i]);
  }
  return copy;
}
