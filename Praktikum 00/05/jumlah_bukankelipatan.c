#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int i = 1;
    int sum = 0;
    for (i; i <= n; i++)
    {
        int num;
        scanf("%d", &num);

        if (num % k != 0)
        {
            sum += num;
        }
    }
    printf("%d\n", sum);
}