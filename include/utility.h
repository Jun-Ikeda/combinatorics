#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <stdio.h>

/** 
 * stringifys a character
 * 
 * @param c Character to stringify
 */
char *stringify_char(void *c);

/** 
 * stringifys a string
 * 
 * @param s String to stringify
 */
char *stringify_string(void *s);

/** 
 * stringifys an integer
 * 
 * @param i Integer to stringify
 */
char *stringify_int(void *i);

/** 
 * stringifys a float
 * 
 * @param f Float to stringify
 */
char *stringify_float(void *f);

/** 
 * stringifys a double
 * 
 * @param d Double to stringify
 */
char *stringify_double(void *d);

/** 
 * stringifys a long
 * 
 * @param l Long to stringify
 */
char *stringify_long(void *l);

/** 
 * stringifys a long long
 * 
 * @param ll Long long to stringify
 */
char *stringify_long_long(void *ll);

/** 
 * stringifys a long double
 * 
 * @param ld Long double to stringify
 */
char *stringify_long_double(void *ld);

/** 
 * stringifys a pointer
 * 
 * @param p Pointer to stringify
 */
char *stringify_pointer(void *p);

/** 
 * stringifys a boolean
 * 
 * @param b Boolean to stringify
 */
char *stringify_bool(void *b);

/** 
 * Compares two characters and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First character to compare
 * @param b Second character to compare
 */
int compare_char(void *a, void *b);

/** 
 * Compares two strings and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First string to compare
 * @param b Second string to compare
 */
int compare_string(void *a, void *b);

/** 
 * Compares two integers and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First integer to compare
 * @param b Second integer to compare
 */
int compare_int(void *a, void *b);

/** 
 * Compares two floats and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First float to compare
 * @param b Second float to compare
 */
int compare_float(void *a, void *b);

/** 
 * Compares two doubles and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First double to compare
 * @param b Second double to compare
 */
int compare_double(void *a, void *b);

/** 
 * Compares two longs and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First long to compare
 * @param b Second long to compare
 */
int compare_long(void *a, void *b);

/** 
 * Compares two long longs and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First long long to compare
 * @param b Second long long to compare
 */
int compare_long_long(void *a, void *b);

/** 
 * Compares two long doubles and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First long double to compare
 * @param b Second long double to compare
 */
int compare_long_double(void *a, void *b);

/** 
 * Compares two pointers and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First pointer to compare
 * @param b Second pointer to compare
 */
int compare_pointer(void *a, void *b);

/** 
 * Compares two booleans and returns 
 * a positive value if a > b, 
 * a negative value if a < b, and 0 otherwise
 * 
 * @param a First boolean to compare
 * @param b Second boolean to compare
 */
int compare_bool(void *a, void *b);

#endif // #ifndef __UTILITY_H__
