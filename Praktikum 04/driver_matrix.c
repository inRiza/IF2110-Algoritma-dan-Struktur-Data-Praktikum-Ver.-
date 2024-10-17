#include <stdio.h>
#include "matrix.c"

int main()
{
    Matrix m1, m2, result;
    int nRow, nCol, scalar;

    // Membaca ukuran matriks pertama
    printf("Masukkan jumlah baris dan kolom matriks pertama (dipisah spasi): ");
    scanf("%d %d", &nRow, &nCol);

    // Membaca elemen matriks pertama
    printf("Masukkan elemen-elemen matriks pertama:\n");
    readMatrix(&m1, nRow, nCol);

    // Menampilkan matriks pertama
    printf("Matriks pertama:\n");
    displayMatrix(m1);
    printf("\n");

    // Membaca ukuran matriks kedua (harus sama dengan matriks pertama untuk operasi aritmatika)
    printf("Masukkan jumlah baris dan kolom matriks kedua (dipisah spasi): ");
    scanf("%d %d", &nRow, &nCol);

    // Membaca elemen matriks kedua
    printf("Masukkan elemen-elemen matriks kedua:\n");
    readMatrix(&m2, nRow, nCol);

    // Menampilkan matriks kedua
    printf("Matriks kedua:\n");
    displayMatrix(m2);
    printf("\n");

    // Penjumlahan matriks
    if (isMatrixSizeEqual(m1, m2))
    {
        result = addMatrix(m1, m2);
        printf("Hasil penjumlahan matriks:\n");
        displayMatrix(result);
    }
    else
    {
        printf("Penjumlahan tidak dapat dilakukan, ukuran matriks tidak sama.\n");
    }
    printf("\n");

    // Pengurangan matriks
    if (isMatrixSizeEqual(m1, m2))
    {
        result = subtractMatrix(m1, m2);
        printf("Hasil pengurangan matriks:\n");
        displayMatrix(result);
    }
    else
    {
        printf("Pengurangan tidak dapat dilakukan, ukuran matriks tidak sama.\n");
    }
    printf("\n");

    // Perkalian matriks
    if (COL_EFF(m1) == ROW_EFF(m2))
    {
        result = multiplyMatrix(m1, m2);
        printf("Hasil perkalian matriks:\n");
        displayMatrix(result);
    }
    else
    {
        printf("Perkalian tidak dapat dilakukan, ukuran kolom matriks pertama tidak sama dengan baris matriks kedua.\n");
    }
    printf("\n");

    // Transpose matriks pertama
    result = transpose(m1);
    printf("Hasil transpose matriks pertama:\n");
    displayMatrix(result);
    printf("\n");

    // Negasi matriks pertama
    result = negation(m1);
    printf("Hasil negasi matriks pertama:\n");
    displayMatrix(result);
    printf("\n");

    // Perkalian dengan konstanta
    printf("Masukkan konstanta untuk dikalikan dengan matriks pertama: ");
    scanf("%d", &scalar);
    result = multiplyByConst(m1, scalar);
    printf("Hasil perkalian matriks pertama dengan %d:\n", scalar);
    displayMatrix(result);
    printf("\n");

    // Menghitung determinan (hanya untuk matriks bujur sangkar)
    if (isSquare(m1))
    {
        float det = determinant(m1);
        printf("Determinan matriks pertama: %.2f\n", det);
    }
    else
    {
        printf("Tidak dapat menghitung determinan, matriks pertama bukan bujur sangkar.\n");
    }

    return 0;
}
