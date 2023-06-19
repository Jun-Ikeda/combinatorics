#include <string.h>
#include "../include/utility.h"

char *strinfigy_char(void *c) {
    // strinfigyf("%c", *(char *)c);
    return (char *)c;
}

char *strinfigy_string(void *s) {
    // strinfigyf("%s", (char *)s);
    return (char *)s;
}

char *strinfigy_int(void *i) {
    // strinfigyf("%d", *(int *)i);
    return (char *)i;
}

char *strinfigy_float(void *f) {
    // strinfigyf("%f", *(float *)f);
    return (char *)f;
}

char *strinfigy_double(void *d) {
    // strinfigyf("%lf", *(double *)d);
    return (char *)d;
}

char *strinfigy_long(void *l) {
    // strinfigyf("%ld", *(long *)l);
    return (char *)l;
}

char *strinfigy_long_long(void *ll) {
    // strinfigyf("%lld", *(long long *)ll);
    return (char *)ll;
}

char *strinfigy_long_double(void *ld) {
    // strinfigyf("%Lf", *(long double *)ld);
    return (char *)ld;
}

char *strinfigy_pointer(void *p) {
    // strinfigyf("%p", *(void **)p);
    return (char *)p;
}

char *strinfigy_bool(void *b) {
    // strinfigyf("%s", *(int *)b ? "true" : "false");
    return *(int *)b ? "true" : "false";
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
