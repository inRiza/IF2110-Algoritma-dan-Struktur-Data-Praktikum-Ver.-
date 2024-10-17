
#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l, lsimpan, lbaru;
    int i, j;

    CreateListStatik(&l);
    CreateListStatik(&lsimpan);
    CreateListStatik(&lbaru);

    // Baca input
    readList(&l);

    // Simpan list awal ke lsimpan untuk menghitung jumlah kemunculan
    for (i = 0; i < listLength(l); i++)
    {
        ELMT(lsimpan, i) = ELMT(l, i);
    }

    // Hapus duplikat
    for (i = 0; i < listLength(l); i++)
    {
        boolean found = false;
        for (j = 0; j < listLength(lbaru); j++)
        {
            if (ELMT(l, i) == ELMT(lbaru, j))
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            insertLast(&lbaru, ELMT(l, i));
        }
    }

    // Cetak list tanpa duplikat
    printList(lbaru);
    printf("\n");

    // Hitung jumlah kemunculan elemen di lsimpan dan cetak
    for (i = 0; i < listLength(lbaru); i++)
    {
        int count = 0;
        for (j = 0; j < listLength(lsimpan); j++)
        {
            if (ELMT(lbaru, i) == ELMT(lsimpan, j))
            {
                count++;
            }
        }
        printf("%d %d\n", ELMT(lbaru, i), count);
    }

    return 0;
}
