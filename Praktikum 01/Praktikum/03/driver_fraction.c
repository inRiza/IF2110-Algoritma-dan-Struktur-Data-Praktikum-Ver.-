/* File: driver_fraction.c */
/* Driver program to test fraction operations */

#include <stdio.h>
#include "fraction.c"

int main()
{
    FRACTION f1, f2, result;
    int n;

    /* Test creation of valid fraction */
    printf("Input fraction 1 (numerator/denominator): ");
    ReadFRACTION(&f1);
    printf("Fraction 1: ");
    WriteFRACTION(f1);
    printf("\n");

    printf("Input fraction 2 (numerator/denominator): ");
    ReadFRACTION(&f2);
    printf("Fraction 2: ");
    WriteFRACTION(f2);
    printf("\n");

    /* Test addition */
    result = AddFRACTION(f1, f2);
    printf("Result of addition: ");
    WriteFRACTION(result);
    printf("\n");

    /* Test subtraction */
    result = SubtractFRACTION(f1, f2);
    printf("Result of subtraction: ");
    WriteFRACTION(result);
    printf("\n");

    /* Test multiplication */
    result = MultiplyFRACTION(f1, f2);
    printf("Result of multiplication: ");
    WriteFRACTION(result);
    printf("\n");

    /* Test division */
    result = DivideFRACTION(f1, f2);
    printf("Result of division: ");
    WriteFRACTION(result);
    printf("\n");

    /* Test simplifying fraction */
    printf("Simplified fraction 1: ");
    result = SimplifyFRACTION(f1);
    WriteFRACTION(result);
    printf("\n");

    printf("Simplified fraction 2: ");
    result = SimplifyFRACTION(f2);
    WriteFRACTION(result);
    printf("\n");

    /* Test conversion to decimal */
    printf("Fraction 1 as decimal: %.2f\n", ToDecimal(f1));
    printf("Fraction 2 as decimal: %.2f\n", ToDecimal(f2));

    /* Test multiplying fraction by a number */
    printf("Input integer to multiply with fraction 1: ");
    scanf("%d", &n);
    result = MultiplyNumberFRACTION(n, f1);
    printf("Result of multiplying fraction 1 by %d: ", n);
    WriteFRACTION(result);
    printf("\n");

    return 0;
}
// gcc -o a driver_fraction.c