#include <stdio.h>
#include "listdin.h"

#define MAX_N 100000

int main()
{
    ListDin l;
    int i;

    // Inisialisasi list dan membaca input
    CreateListDin(&l, MAX_N);
    readList(&l);

    int N = listLength(l);

    // Array untuk menyimpan nilai maksimum di kiri dan minimum di kanan
    int maxLeft[MAX_N], minRight[MAX_N];

    // Hitung maxLeft: maksimum dari kiri hingga elemen ke-i
    maxLeft[0] = ELMT(l, 0);
    for (i = 1; i < N; i++)
    {
        maxLeft[i] = (ELMT(l, i - 1) > maxLeft[i - 1]) ? ELMT(l, i - 1) : maxLeft[i - 1];
    }

    // Hitung minRight: minimum dari elemen ke-i hingga kanan
    minRight[N - 1] = ELMT(l, N - 1);
    for (i = N - 2; i >= 0; i--)
    {
        minRight[i] = (ELMT(l, i + 1) < minRight[i + 1]) ? ELMT(l, i + 1) : minRight[i + 1];
    }

    // Hitung berapa elemen yang bisa menjadi pivot
    int count = 0;
    for (i = 0; i < N; i++)
    {
        if ((i == 0 || maxLeft[i] <= ELMT(l, i)) && (i == N - 1 || minRight[i] > ELMT(l, i)))
        {
            count++;
        }
    }

    // Hasil output
    printf("%d\n", count);

    // Dealokasi list dinamis
    dealocateList(&l);

    return 0;
}
