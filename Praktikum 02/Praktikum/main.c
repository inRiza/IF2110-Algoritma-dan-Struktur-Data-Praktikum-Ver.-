#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l;
    CreateListStatik(&l); // Inisialisasi list
    readList(&l);         // Baca input list

    int freq[CAPACITY] = {0}; // Menyimpan frekuensi setiap elemen
    int n = listLength(l);    // Mendapatkan panjang list

    // Menghitung frekuensi setiap elemen
    for (int i = 0; i < n; i++)
    {
        int val = ELMT(l, i);
        freq[val]++;
    }

    int firstMax = 0, secondMax = 0;
    int firstMaxVal = MARK, secondMaxVal = MARK;

    for (int i = 0; i < CAPACITY; i++)
    {
        if (freq[i] > firstMax)
        {
            secondMax = firstMax;
            secondMaxVal = firstMaxVal;
            firstMax = freq[i];
            firstMaxVal = i;
        }
        else if (freq[i] > secondMax && freq[i] < firstMax)
        {
            secondMax = freq[i];
            secondMaxVal = i;
        }
    }

    // Output elemen kedua yang paling sering muncul atau pesan khusus
    if (secondMaxVal != MARK)
    {
        printf("%d\n", secondMaxVal);
    }
    else
    {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }

    return 0;
}
