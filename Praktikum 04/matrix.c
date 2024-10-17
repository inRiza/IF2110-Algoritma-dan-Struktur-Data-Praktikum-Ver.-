/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include "boolean.h"
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
/* #define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)] */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
    return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
    return ROW_EFF(m) - 1;
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m)
{
    return COL_EFF(m) - 1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    return (i >= 0 && i < ROW_EFF(m)) && (j >= 0 && j < COL_EFF(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i)
{
    return ELMT(m, i, i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    int i, j;
    for (i = 0; i < ROW_EFF(mIn); i++)
    {
        for (j = 0; j < COL_EFF(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/

void displayMatrix(Matrix m)
{
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (j == COL_EFF(m) - 1)
            {
                printf("%d", ELMT(m, i, j));
            }
            else
            {
                printf("%d ", ELMT(m, i, j));
            }
        }
        if (i < ROW_EFF(m) - 1)
        {
            printf("\n");
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
    if (!isMatrixSizeEqual(m1, m2))
    {
        Matrix hasil;
        createMatrix(0, 0, &hasil); // Create empty matrix if sizes are not equal
        return hasil;
    }
    Matrix hasil;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &hasil);
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(hasil, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return hasil;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */

Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    if (!isMatrixSizeEqual(m1, m2))
    {
        Matrix hasil;
        createMatrix(0, 0, &hasil); // Create empty matrix if sizes are not equal
        return hasil;
    }
    Matrix hasil;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &hasil);
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(hasil, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return hasil;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */

Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    if (COL_EFF(m1) != ROW_EFF(m2))
    {
        Matrix hasil;
        createMatrix(0, 0, &hasil); // Create empty matrix if sizes are not compatible
        return hasil;
    }

    Matrix hasil;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &hasil);

    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m2); j++)
        {
            ELMT(hasil, i, j) = 0; // Set nilai awal elemen menjadi 0
            for (k = 0; k < COL_EFF(m1); k++)
            {
                ELMT(hasil, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j); // Perkalian baris x kolom
            }
        }
    }
    return hasil;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */

Matrix multiplyByConst(Matrix m, ElType x)
{
    Matrix hasil;
    createMatrix(ROW_EFF(m), COL_EFF(m), &hasil); // Inisialisasi matriks hasil

    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(hasil, i, j) = ELMT(m, i, j) * x; // Perkalian elemen dengan konstanta
        }
    }
    return hasil;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */

void pMultiplyByConst(Matrix *m, ElType k)
{
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) *= k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    if (!isMatrixSizeEqual(m1, m2))
    {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                return false;
            }
        }
    }
    return true;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return !isMatrixEqual(m1, m2);
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
    return ROW_EFF(m) * COL_EFF(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    return ROW_EFF(m) == COL_EFF(m);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m)
{
    int i, j;
    if (!isSquare(m))
    {
        return false;
    }
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != ELMT(m, j, i))
            {
                return false;
            }
        }
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m)
{
    int i, j;
    if (!isSquare(m))
    {
        return false;
    }
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if ((i == j && ELMT(m, i, j) != 1) || (i != j && ELMT(m, i, j) != 0))
            {
                return false;
            }
        }
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m)
{
    int manyElmt = countElmt(m);
    int count = 0;
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count += 1;
            }
        }
    }

    float persen = (float)count / manyElmt * 100;

    if (persen > 5)
    {
        return false;
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m)
{
    Matrix hasil;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &hasil);

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(hasil, i, j) = -1 * ELMT(m, i, j);
        }
    }
    return hasil;
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m)
{
    int i, j;

    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) = -1 * ELMT(*m, i, j);
        }
    }
}
/* ********** DETERMINAN ********** */
float determinant(Matrix m)
{
    if (ROW_EFF(m) != COL_EFF(m))
    {
        return 0; // Atau penanganan kesalahan
    }
    if (ROW_EFF(m) == 1)
    {
        return ELMT(m, 0, 0); // Kasus 1x1
    }
    else if (ROW_EFF(m) == 2)
    {
        return (ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 0, 1) * ELMT(m, 1, 0)); // Kasus 2x2
    }

    // Kasus untuk n > 2, gunakan rumus ekspansi kofaktor
    float det = 0;
    for (int j = 0; j < COL_EFF(m); j++)
    {
        Matrix subMatrix;
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &subMatrix);

        for (int sub_i = 1; sub_i < ROW_EFF(m); sub_i++)
        {
            for (int sub_j = 0; sub_j < COL_EFF(m) - 1; sub_j++)
            {
                subMatrix.mem[sub_i - 1][sub_j] = ELMT(m, sub_i, sub_j >= j ? sub_j + 1 : sub_j);
            }
        }
        det += (j % 2 == 0 ? 1 : -1) * ELMT(m, 0, j) * determinant(subMatrix); // Penambahan hasil kofaktor
    }
    return det;
}

/* ********** TRANSPOSE ********** */
Matrix transpose(Matrix m)
{
    Matrix hasil;
    createMatrix(COL_EFF(m), ROW_EFF(m), &hasil); // Transpose matriks
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            ELMT(hasil, j, i) = ELMT(m, i, j); // Penukaran baris dan kolom
        }
    }
    return hasil;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

void pTranspose(Matrix *m)
{
    if (!isSquare(*m))
        return; // Cek apakah matriks persegi
    for (int i = 0; i < ROW_EFF(*m); i++)
    {
        for (int j = i + 1; j < COL_EFF(*m); j++) // Hanya pertukaran setengah bagian
        {
            ElType temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

