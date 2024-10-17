#include <stdio.h>
#include "liststatik.c"
#include "boolean.h"

int main()
{
    // Deklarasi ListStatik
    ListStatik l1, l2, l3;
    ElType max, min, val;
    IdxType idx;

    // Create list kosong
    CreateListStatik(&l1);
    CreateListStatik(&l2);

    // Input list pertama
    printf("Masukkan elemen untuk l1:\n");
    readList(&l1);

    // Input list kedua
    printf("Masukkan elemen untuk l2:\n");
    readList(&l2);

    // Tampilkan kedua list
    printf("Isi l1: ");
    printList(l1);
    printf("\n");

    printf("Isi l2: ");
    printList(l2);
    printf("\n");

    // Tes panjang list
    printf("Panjang l1: %d\n", listLength(l1));
    printf("Panjang l2: %d\n", listLength(l2));

    // Tes indeks pertama dan terakhir
    if (!isEmpty(l1))
    {
        printf("Indeks pertama l1: %d\n", getFirstIdx(l1));
        printf("Indeks terakhir l1: %d\n", getLastIdx(l1));
    }

    // Tes mencari angka di list
    printf("Masukkan nilai yang ingin dicari di l1: ");
    scanf("%d", &val);
    idx = indexOf(l1, val);
    if (idx != IDX_UNDEF)
    {
        printf("Nilai %d ditemukan pada indeks %d di l1.\n", val, idx);
    }
    else
    {
        printf("Nilai %d tidak ditemukan di l1.\n", val);
    }

    // Tes fungsi insert
    printf("Masukkan elemen untuk insertFirst di l1: ");
    scanf("%d", &val);
    insertFirst(&l1, val);
    printf("Isi l1 setelah insertFirst: ");
    printList(l1);
    printf("\n");

    printf("Masukkan elemen untuk insertLast di l1: ");
    scanf("%d", &val);
    insertLast(&l1, val);
    printf("Isi l1 setelah insertLast: ");
    printList(l1);
    printf("\n");

    printf("Masukkan indeks dan elemen untuk insertAt di l1: ");
    scanf("%d %d", &idx, &val);
    insertAt(&l1, val, idx);
    printf("Isi l1 setelah insertAt: ");
    printList(l1);
    printf("\n");

    // Tes fungsi delete
    deleteFirst(&l1, &val);
    printf("Isi l1 setelah deleteFirst: ");
    printList(l1);
    printf("\n");

    deleteLast(&l1, &val);
    printf("Isi l1 setelah deleteLast: ");
    printList(l1);
    printf("\n");

    printf("Masukkan indeks untuk deleteAt di l1: ");
    scanf("%d", &idx);
    deleteAt(&l1, &val, idx);
    printf("Isi l1 setelah deleteAt: ");
    printList(l1);
    printf("\n");

    // Tes fungsi extremeValues
    if (!isEmpty(l1))
    {
        extremeValues(l1, &max, &min);
        printf("Max value in l1: %d\n", max);
        printf("Min value in l1: %d\n", min);
    }

    // Tes fungsi plusMinusList
    printf("Hasil penjumlahan l1 + l2: ");
    l3 = plusMinusList(l1, l2, true);
    printList(l3);
    printf("\n");

    printf("Hasil pengurangan l1 - l2: ");
    l3 = plusMinusList(l1, l2, false);
    printList(l3);
    printf("\n");

    // Tes fungsi sorting
    printf("Sorting l1 secara ascending:\n");
    sortList(&l1, true);
    printList(l1);
    printf("\n");

    printf("Sorting l2 secara descending:\n");
    sortList(&l2, false);
    printList(l2);
    printf("\n");

    // Tes fungsi isListEqual
    if (isListEqual(l1, l2))
    {
        printf("l1 dan l2 sama.\n");
    }
    else
    {
        printf("l1 dan l2 berbeda.\n");
    }

    return 0;
}
