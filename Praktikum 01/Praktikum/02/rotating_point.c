#include <stdio.h>
#include "rotating_point.h"

COMPLEX PowerCOMPLEX(COMPLEX C, int p)
{
    COMPLEX hasil = {1, 0};
    int i;
    for (i = 1; i <= p; i++)
    {
        hasil = MultiplyCOMPLEX(hasil, C);
    }
    return hasil;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n)
{
    float x, y;
    int i;
    if ((P)->X * (P)->X + (P)->Y * (P)->Y > 1)
    {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            COMPLEX pC = PowerCOMPLEX(C, i);
            x = (*P).X * (pC).Re - (*P).Y * (pC).Im;
            y = (*P).X * (pC).Im + (*P).Y * (pC).Re;

            if (x * x + y * y > 1)
            {
                printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
                break;
            }
            else
            {
                (*P).X = x;
                (*P).Y = y;
            }
        }
        if (i == n + 1)
        {
            printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
        }
    }
}