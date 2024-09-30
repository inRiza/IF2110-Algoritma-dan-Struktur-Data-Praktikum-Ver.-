#include <stdio.h>
#include "circle.c"
#include "point.c"

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
    printf("Keliling lingkaran 1 yang terhitung adalah: %.02f", Circumference(C1));
    printf("\n");
    printf("Keliling lingkaran 2 yang terhitung adalah: %.02f", Circumference(C2));
    printf("\n");
    printf("Luas lingkaran 1 yang terhitung adalah: %.02f", Area(C1));
    printf("\n");
    printf("Luas lingkaran 2 yang terhitung adalah: %.02f", Area(C2));
    printf("\n");

    printf("Masukkan point: ");
    BacaPOINT(P);

    if (IsPOINTInsideCIRCLE(C1, P))
    {
        printf("Titik point berada di dalam lingkaran.");
    }
    else if (IsPOINTInEdgeCIRCLE(C1, P))
    {
        printf("Titik point berada di ujung lingkaran");
    }

    if (IsCIRCLEInsideCIRCLE(C1, C2))
    {
        printf("Lingkaran 1 berada di dalam lingkaran 2");
    }
    else if (IsCIRCLESIntersects(C1, C2))
    {
        printf("Lingkaran 1 berpotongan di 2 titik dengan Lingkaran 2");
    }
    else if (IsCIRCLESTangents(C1, C2))
    {
        printf('Lingkaran 1 bersinggungan dengan lingkaran 2');
    }

    
}