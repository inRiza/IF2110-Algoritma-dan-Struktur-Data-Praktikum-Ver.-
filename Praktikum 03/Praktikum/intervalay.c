#include <stdio.h>
#include "listdin.h"

// Fungsi untuk memasukkan newInterval ke dalam intervalay tanpa irisan
void insertAndMergeInterval(ListDin *intervals, ElType start, ElType stop)
{
    ListDin merged;
    CreateListDin(&merged, CAPACITY(*intervals) + 2); // Tambah kapasitas untuk newInterval

    int i = 0;

    // Masukkan interval yang tidak bertumpang tindih sebelum newInterval
    while (i < NEFF(*intervals) && ELMT(*intervals, i + 1) < start)
    {
        insertLast(&merged, ELMT(*intervals, i));     // start
        insertLast(&merged, ELMT(*intervals, i + 1)); // stop
        i += 2;
    }

    // Gabungkan newInterval dengan interval yang bertumpang tindih
    while (i < NEFF(*intervals) && ELMT(*intervals, i) <= stop)
    {
        start = (start < ELMT(*intervals, i)) ? start : ELMT(*intervals, i);      // Ambil start terawal
        stop = (stop > ELMT(*intervals, i + 1)) ? stop : ELMT(*intervals, i + 1); // Ambil stop terakhir
        i += 2;
    }

    // Masukkan interval yang sudah digabung
    insertLast(&merged, start);
    insertLast(&merged, stop);

    // Masukkan sisa interval setelah newInterval
    while (i < NEFF(*intervals))
    {
        insertLast(&merged, ELMT(*intervals, i));
        insertLast(&merged, ELMT(*intervals, i + 1));
        i += 2;
    }

    // Tampilkan hasil penggabungan interval
    for (int j = 0; j < NEFF(merged); j++)
    {
        printf("%d", ELMT(merged, j));
        if (j < NEFF(merged) - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    // Dealokasi memori
    dealocateList(&merged);
}

int main()
{
    ListDin intervals;
    int n;
    ElType newStart, newStop;

    // Input panjang intervalay (n harus genap)
    scanf("%d", &n);

    // Membuat list intervalay
    CreateListDin(&intervals, n);

    // Input intervalay
    for (int i = 0; i < n; i++)
    {
        ElType val;
        scanf("%d", &val);
        insertLast(&intervals, val);
    }

    // Input newInterval
    scanf("%d %d", &newStart, &newStop);

    // Masukkan newInterval ke dalam intervalay
    insertAndMergeInterval(&intervals, newStart, newStop);

    // Dealokasi memori
    dealocateList(&intervals);

    return 0;
}
