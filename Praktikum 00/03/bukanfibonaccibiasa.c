#include <stdio.h>

int main()
{
    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);

    int arr[n];
    arr[0] = a;
    arr[1] = b;

    int i = 2;
    for (i; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%d\n", arr[n - 1]);
    return 0;
}
