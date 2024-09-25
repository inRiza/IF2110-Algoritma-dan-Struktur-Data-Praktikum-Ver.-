#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", a);

    int sum = a;
    while (sum < b)
    {
        if (sum % 2 == 0)
        {
            sum = sum * 2;
        }
        else if (sum % 2 == 1)
        {
            sum += 1;
        }
        if (sum < b)
        {
            printf(" %d", sum);
        }
    }
    printf("\n");
    return 0;
}