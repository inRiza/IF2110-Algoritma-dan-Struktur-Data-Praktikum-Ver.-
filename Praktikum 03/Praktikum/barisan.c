#include <stdio.h>
#include "listdin.h"

int main()
{
    ListDin l;

    CreateListDin(&l, CAPACITY(l));
    readList(&l);
    int i, j;
    int count = 0;

    for (i = 0; i < listLength(l); i++)
    {
        for (j = i + 1; j < listLength(l); j++)
        {
            if (ELMT(l, i) > ELMT(l, j))
            {
                ElType temp = ELMT(l, j);
                ELMT(l, j) = ELMT(l, i);
                ELMT(l, i) = temp;
                count++;
            }
        }
    }
    printf("%d\n", count);
}