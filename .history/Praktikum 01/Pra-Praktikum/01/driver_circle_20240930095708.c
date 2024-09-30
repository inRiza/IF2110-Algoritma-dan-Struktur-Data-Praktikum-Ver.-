#include <stdio.h>
#include "circle.c"

int main()
{
    CIRCLE C1, C2;
    POINT P;

    printf("Masukkan nilai-nilai untuk membuat sebuah lingkaran: ");
    ReadCIRCLE(&C1);

    printf("Lingkaran yang dibuat adalah: ");
    WriteCIRCLE(C1);

    printf("Keliling lingkaran yang terhitung adalah: ");
    Circumference();
}