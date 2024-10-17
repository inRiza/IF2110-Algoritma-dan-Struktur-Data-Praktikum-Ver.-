#include <stdio.h>
#include "rotating_point.c"
#include "complex.c"

/* Main program to test TransformPointByComplexPower */
int main()
{
    /* Test case 1 */
    POINT P1;
    P1.X = 0.5;
    P1.Y = 0.5;
    COMPLEX C1;
    C1.Re = 3;
    C1.Im = 2;
    int n1 = 2;

    printf("Test Case 1:\n");
    TransformPointByComplexPower(&P1, C1, n1);
    printf("\n");

    /* Test case 2 */
    POINT P2;
    P2.X = 0.5;
    P2.Y = 0.5;
    COMPLEX C2;
    C2.Re = 1;
    C2.Im = 1;
    int n2 = 2;

    printf("Test Case 2:\n");
    TransformPointByComplexPower(&P2, C2, n2);
    printf("\n");

    return 0;
}
