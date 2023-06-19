#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <stdio.h>

// double rand_double();

/** 
 * Prints a character
 * 
 * @param c Character to print
 */
void print_char(void *c);

/** 
 * Prints a string
 * 
 * @param s String to print
 */
void print_string(void *s);

/** 
 * Prints an integer
 * 
 * @param i Integer to print
 */
void print_int(void *i);

/** 
 * Prints a float
 * 
 * @param f Float to print
 */
void print_float(void *f);

/** 
 * Prints a double
 * 
 * @param d Double to print
 */
void print_double(void *d);

/** 
 * Prints a long
 * 
 * @param l Long to print
 */
void print_long(void *l);

/** 
 * Prints a long long
 * 
 * @param ll Long long to print
 */
void print_long_long(void *ll);

/** 
 * Prints a long double
 * 
 * @param ld Long double to print
 */
void print_long_double(void *ld);

/** 
 * Prints a pointer
 * 
 * @param p Pointer to print
 */
void print_pointer(void *p);

/** 
 * Prints a boolean
 * 
 * @param b Boolean to print
 */
void print_bool(void *b);

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
