#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l;

    CreateListStatik(&l);
    readList(&l);

    int i;
    int angka = 1;

    for (i = listLength(l) - 1; i >= 0 && angka > 0; i--)
    {
        if (ELMT(l, i) == 9)
        {
            ELMT(l, i) = 0;
        }
        else
        {
            ELMT(l, i) += 1;
            angka = 0;
        }
    }

    if (angka == 1)
    {

        insertAt(&l, 1, 0);
    }

    for (i = 0; i < listLength(l); i++)
    {
        if (i == listLength(l) - 1)
        {
            printf("%d", ELMT(l, i));
        }
        else
        {
            printf("%d ", ELMT(l, i));
        }
    }
    printf("\n");
}
