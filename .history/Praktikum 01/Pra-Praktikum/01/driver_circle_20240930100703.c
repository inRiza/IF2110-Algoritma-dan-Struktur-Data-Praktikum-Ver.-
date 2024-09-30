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
    ReadCIRCLE(&C2);
    printf("\n");
    printf("Lingkaran yang dibuat adalah: ");
    WriteCIRCLE(C1);
    WriteCIRCLE(C2);
    printf("\n");
    printf("Keliling lingkaran yang terhitung adalah: %.02f", Circumference(C1));
    printf("\n");
    printf("Luas lingkaran yang terhitung adalah: %.02f", Circumference(C1));
    printf("\n");

}