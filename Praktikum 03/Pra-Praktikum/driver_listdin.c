#include <stdio.h>
#include <stdlib.h>
#include "listdin.c"

int main()
{
    ListDin l1, l2;
    int capacity, val, idx, max, min;
    boolean equal;

    /* Create list */
    printf("Enter capacity for list 1: ");
    scanf("%d", &capacity);
    CreateListDin(&l1, capacity);

    printf("Enter capacity for list 2: ");
    scanf("%d", &capacity);
    CreateListDin(&l2, capacity);

    /* Test readList and printList */
    printf("\nInput elements for list 1:\n");
    readList(&l1);
    printf("List 1: ");
    printList(l1);
    printf("\n");

    printf("Input elements for list 2:\n");
    readList(&l2);
    printf("List 2: ");
    printList(l2);
    printf("\n");

    /* Test listLength */
    printf("Length of list 1: %d\n", listLength(l1));
    printf("Length of list 2: %d\n", listLength(l2));

    /* Test isIdxValid and isIdxEff */
    printf("Enter an index to check validity: ");
    scanf("%d", &idx);
    printf("Is index %d valid for list 1? %s\n", idx, isIdxValid(l1, idx) ? "Yes" : "No");
    printf("Is index %d effective for list 1? %s\n", idx, isIdxEff(l1, idx) ? "Yes" : "No");

    /* Test isEmpty and isFull */
    printf("Is list 1 empty? %s\n", isEmpty(l1) ? "Yes" : "No");
    printf("Is list 1 full? %s\n", isFull(l1) ? "Yes" : "No");

    /* Test insertLast and deleteLast */
    printf("Enter a value to insert at the end of list 1: ");
    scanf("%d", &val);
    insertLast(&l1, val);
    printf("After inserting last, list 1: ");
    printList(l1);
    printf("\n");

    deleteLast(&l1, &val);
    printf("After deleting last, list 1: ");
    printList(l1);
    printf("\nDeleted value: %d\n", val);

    /* Test indexOf */
    printf("Enter a value to search in list 1: ");
    scanf("%d", &val);
    idx = indexOf(l1, val);
    if (idx != IDX_UNDEF)
    {
        printf("Value %d found at index %d\n", val, idx);
    }
    else
    {
        printf("Value %d not found\n", val);
    }

    /* Test extremeValues */
    extremeValues(l1, &max, &min);
    printf("Max value in list 1: %d, Min value in list 1: %d\n", max, min);

    /* Test plusMinusList */
    printf("\nSum of list 1 and list 2: ");
    ListDin Listbaru = plusMinusList(l1, l2, true);
    printList(Listbaru);
    printf("\nDifference of list 1 and list 2: ");
    ListDin diffList = plusMinusList(l1, l2, false);
    printList(diffList);
    printf("\n");

    /* Test isListEqual */
    equal = isListEqual(l1, l2);
    printf("Are list 1 and list 2 equal? %s\n", equal ? "Yes" : "No");

    /* Test sumList and countVal */
    printf("Sum of all elements in list 1: %d\n", sumList(l1));
    printf("Enter a value to count occurrences in list 1: ");
    scanf("%d", &val);
    printf("Value %d occurs %d times in list 1\n", val, countVal(l1, val));

    /* Test sorting */
    printf("List 1 before sorting: ");
    printList(l1);
    printf("\nSorting list 1 in ascending order...\n");
    sort(&l1, true);
    printf("List 1 after sorting ascending: ");
    printList(l1);
    printf("\nSorting list 1 in descending order...\n");
    sort(&l1, false);
    printf("List 1 after sorting descending: ");
    printList(l1);
    printf("\n");

    /* Test expandList, shrinkList, and compressList */
    printf("Expanding list 1 by 5...\n");
    expandList(&l1, 5);
    printf("Capacity after expanding: %d\n", CAPACITY(l1));

    printf("Shrinking list 1 by 3...\n");
    shrinkList(&l1, 3);
    printf("Capacity after shrinking: %d\n", CAPACITY(l1));

    printf("Compressing list 1 to fit its effective elements...\n");
    compressList(&l1);
    printf("Capacity after compressing: %d\n", CAPACITY(l1));

    /* Test copyList */
    ListDin lCopy;
    copyList(l1, &lCopy);
    printf("Copy of list 1: ");
    printList(lCopy);
    printf("\n");

    /* Deallocation */
    dealocateList(&l1);
    dealocateList(&l2);
    dealocateList(&Listbaru);
    dealocateList(&diffList);
    dealocateList(&lCopy);

    return 0;
}
