#include <stdio.h>
#include "lists.c"

int main()
{
    ListStatik l;
    ElType val;
    int idx;

    // Membuat list kosong
    CreateListStatik(&l);
    printf("List after creation: ");
    printList(l);
    printf("\n");

    // Insert elements
    printf("Inserting elements...\n");
    insertFirst(&l, 10);
    insertLast(&l, 30);
    insertAt(&l, 20, 1); // Insert 20 at index 1
    printList(l);        // Expected output: [10, 20, 30]
    printf("\n");

    // Test length of the list
    printf("Length of the list: %d\n", listLength(l)); // Expected output: 3

    // Test getFirstIdx and getLastIdx
    printf("First index: %d\n", getFirstIdx(l)); // Expected output: 0
    printf("Last index: %d\n", getLastIdx(l));   // Expected output: 2

    // Search for an element
    idx = indexOf(l, 20);
    if (idx != IDX_UNDEF)
    {
        printf("Element 20 found at index: %d\n", idx);
    }
    else
    {
        printf("Element 20 not found\n");
    }

    // Test extreme values
    ElType max, min;
    extremeValues(l, &max, &min);
    printf("Max value: %d, Min value: %d\n", max, min); // Expected output: Max = 30, Min = 10

    // Insert first and last element
    insertFirst(&l, 5);
    insertLast(&l, 35);
    printList(l); // Expected output: [5, 10, 20, 30, 35]
    printf("\n");

    // Delete the first element
    deleteFirst(&l, &val);
    printf("Deleted first element: %d\n", val); // Expected output: 5
    printList(l);                               // Expected output: [10, 20, 30, 35]
    printf("\n");

    // Delete the last element
    deleteLast(&l, &val);
    printf("Deleted last element: %d\n", val); // Expected output: 35
    printList(l);                              // Expected output: [10, 20, 30]
    printf("\n");

    // Delete element at index 1
    deleteAt(&l, &val, 1);
    printf("Deleted element at index 1: %d\n", val); // Expected output: 20
    printList(l);                                    // Expected output: [10, 30]
    printf("\n");

    // Test isEmpty and isFull
    if (isEmpty(l))
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List is not empty\n"); // Expected output: List is not empty
    }

    // Sort list ascending
    printf("Sorting list in ascending order...\n");
    sortList(&l, true);
    printList(l); // Expected output: [10, 30]
    printf("\n");

    // Sort list descending
    printf("Sorting list in descending order...\n");
    sortList(&l, false);
    printList(l); // Expected output: [30, 10]
    printf("\n");

    return 0;
}
