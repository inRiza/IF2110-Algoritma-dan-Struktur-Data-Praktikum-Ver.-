#include <stdio.h>
#include "listdin.c"

int main()
{
    ListDin l;
    int i, j, k;

    CreateListDin(&l, CAPACITY(l));
    readList(&l);
    int count = 0;
    boolean isPivot;
    for (i = 0; i < listLength(l); i++)
    {
        isPivot = true;
        for (j = 0; j < i; j++)
        {
            if (ELMT(l, i) < ELMT(l, j))
            {
                isPivot = false;
            }
        }
        for (k = i + 1; k < listLength(l); k++)
        {
            if (ELMT(l, i) > ELMT(l, k))
            {
                isPivot = false;
            }
        }
        if (isPivot)
        {
            count++;
        }
    }
    printf("%d\n", count);
}