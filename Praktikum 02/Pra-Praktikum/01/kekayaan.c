#include <stdio.h>
#include "liststatik.c"

int main()
{
    ListStatik l;
    readList(&l);

    int i;
    if (listLength(l) > 0)
        for (i = getLastIdx(l); i > 0; i--)
        {
            if (ELMT(l, i) == 9)
            {
                ELMT(l, i) = 0;
                ELMT(l, i - 1) += 1;
            }
        }
    
}