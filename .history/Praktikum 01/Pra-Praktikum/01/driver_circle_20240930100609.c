#include <stdio.h>
#include "circle.c"

int main()
{
    CIRCLE C1, C2;
    POINT P;

    printf("Masukkan nilai-nilai untuk membuat sebuah lingkaran 1: ");
    ReadCIRCLE(&C1);
    printf("\n");
    printf("Masukkan nilai-nilai untuk membuat sebuah lingkaran 2: ");
    ReadCIRCLE(&C1);
    printf("\n");
    printf("Lingkaran yang dibuat adalah: ");
    WriteCIRCLE(C1);
    printf("\n");
    printf("Keliling lingkaran yang terhitung adalah: ");
    Circumference(C1);
    printf("\n");
}