#include <string.h>
#include <stdlib.h>
#include "../include/utility.h"

// double random_double() {
//     return (double)rand() / RAND_MAX;
// }

void print_char(void *c) {
    printf("%c", *(char *)c);
}

void print_string(void *s) {
    printf("%s", (char *)s);
}

void print_int(void *i) {
    printf("%d", *(int *)i);
}

void print_float(void *f) {
    printf("%f", *(float *)f);
}

void print_double(void *d) {
    printf("%lf", *(double *)d);
}

void print_long(void *l) {
    printf("%ld", *(long *)l);
}

void print_long_long(void *ll) {
    printf("%lld", *(long long *)ll);
}

void print_long_double(void *ld) {
    printf("%Lf", *(long double *)ld);
}

void print_pointer(void *p) {
    printf("%p", *(void **)p);
}

void print_bool(void *b) {
    printf("%s", *(int *)b ? "true" : "false");
}

int compare_char(void *c1, void *c2) {
    return *(char *)c1 - *(char *)c2;
}

int compare_string(void *s1, void *s2) {
    char *str1 = *(char **)s1;
    char *str2 = *(char **)s2;
    if (strlen(str1) != strlen(str2)) {
        return strlen(str1) - strlen(str2);
    }
    
    for (size_t i = 0; i < strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

int compare_int(void *i1, void *i2) {
    return *(int *)i1 - *(int *)i2;
}

int compare_float(void *f1, void *f2) {
    return *(float *)f1 - *(float *)f2;
}

int compare_double(void *d1, void *d2) {
    return *(double *)d1 - *(double *)d2;
}

int compare_long(void *l1, void *l2) {
    return *(long *)l1 - *(long *)l2;
}

int compare_long_long(void *ll1, void *ll2) {
    return *(long long *)ll1 - *(long long *)ll2;
}

int compare_long_double(void *ld1, void *ld2) {
    return *(long double *)ld1 - *(long double *)ld2;
}

int compare_pointer(void *p1, void *p2) {
    return *(void **)p1 - *(void **)p2;
}

int compare_bool(void *b1, void *b2) {
    return *(int *)b1 - *(int *)b2;
}
