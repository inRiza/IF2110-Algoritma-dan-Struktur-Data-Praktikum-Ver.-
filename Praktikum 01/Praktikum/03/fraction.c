/* File: fraction.c */
/* Tanggal: 21 September 2024 */
/* Implementasi ADT FRACTION */

#include "fraction.h"
#include <stdio.h>

/* *** Definisi fungsi pembantu *** */
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

boolean IsFRACTIONValid(int N, int D)
{
    return D != 0; // Penyebut tidak boleh nol
}

void CreateFRACTION(FRACTION *F, int N, int D)
{
    if (IsFRACTIONValid(N, D))
    {
        F->N = N;
        F->D = D;
    }
}

void ReadFRACTION(FRACTION *F)
{
    int N, D;
    do
    {
        scanf("%d %d", &N, &D);
        if (!IsFRACTIONValid(N, D))
        {
            printf("FRACTION tidak valid\n");
        }
    } while (!IsFRACTIONValid(N, D));
    CreateFRACTION(F, N, D);
}

void WriteFRACTION(FRACTION F)
{
    F = SimplifyFRACTION(F);
    if (F.N == 0)
    {
        printf("0/1");
    }
    else
    {
        printf("%d/%d", F.N, F.D);
    }
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2)
{
    FRACTION result;
    result.N = F1.N * F2.D + F2.N * F1.D;
    result.D = F1.D * F2.D;
    return SimplifyFRACTION(result);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2)
{
    FRACTION result;
    result.N = F1.N * F2.D - F2.N * F1.D;
    result.D = F1.D * F2.D;
    return SimplifyFRACTION(result);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2)
{
    FRACTION result;
    result.N = F1.N * F2.N;
    result.D = F1.D * F2.D;
    return SimplifyFRACTION(result);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2)
{
    FRACTION result;
    if (F2.N != 0)
    {
        result.N = F1.N * F2.D;
        result.D = F1.D * F2.N;
        return SimplifyFRACTION(result);
    }
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1)
{
    FRACTION result;
    result.N = n * F1.N;
    result.D = F1.D;
    return SimplifyFRACTION(result);
}

FRACTION SimplifyFRACTION(FRACTION F)
{
    int gcd = GCD(F.N, F.D);
    F.N /= gcd;
    F.D /= gcd;

    if (F.D < 0)
    {
        F.N = -F.N;
        F.D = -F.D;
    }

    return F;
}

float ToDecimal(FRACTION F)
{
    return (float)F.N / F.D;
}
