/* File: complex.h */
/* Tanggal: 20 September 2024 */
/* Definisi ADT COMPLEX */
/* Catatan: Gunakan %.2f pada printf serta %f untuk scanf untuk mengeluarkan dan membaca float */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
#include "boolean.h"
#include <math.h>

/* *** Definisi TYPE COMPLEX *** */
typedef struct
{
    float Re;
    float Im;
} COMPLEX;

/* *** Notasi Akses: selektor COMPLEX *** */
#define Real(C) (C).Re
#define Imag(C) (C).Im

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCOMPLEXValid(float Re, float Im)
{
    return Re, Im;
}
/* Mengirim true jika Re dan Im valid untuk membentuk COMPLEX */
/* Dalam konteks kompleks, semua bilangan real adalah valid */

/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im)
{
    Real(*C) == Re;
    Imag(*C) == Im;
}
/* Membentuk sebuah COMPLEX dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaCOMPLEX(COMPLEX *C)
{
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}
/* I.S. : C tidak terdefinisi */
/* F.S. : C terdefinisi */
/* Proses : Membaca komponen Re dan Im dari pengguna */

void TulisCOMPLEX(COMPLEX C)
{
    if (Imag(C) < 0)
    {
        printf("%f-%fi", Real(C), -Imag(C));
    }
    else
    {
        printf("%f+%fi", Real(C), Imag(C));
    }
}
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */

/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    COMPLEX hasil;
    CreateComplex(&hasil, Real(C1) + Real(C2), Imag(C1) + Imag(C2));
    return hasil;
}
/* Mengirim hasil penjumlahan C1 + C2 */

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    COMPLEX hasil;
    CreateComplex(&hasil, Real(C1) - Real(C2), Imag(C1) - Imag(C2));
    return hasil;
}
/* Mengirim hasil pengurangan C1 - C2 */

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    COMPLEX hasil;
    float hasilReal = (Real(C1) * Real(C2)) - (Imag(C1) * Imag(C2));
    float hasilImag = (Real(C1) * Imag(C2)) + (Imag(C1) * Real(C2));
    CreateComplex(&hasil, hasilReal, hasilImag);
    return hasil;
}
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    COMPLEX hasil;
    float denominator = Real(C2) * Real(C2) + Imag(C1) * Imag(C1);
    if (denominator == 0)
    {
        CreateComplex(&hasil, 0, 0);
        return hasil;
    }
    else
    {
        CreateComplex(&hasil, )
    }
}
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float AbsCOMPLEX(COMPLEX C);
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */

COMPLEX ConjugateCOMPLEX(COMPLEX C);
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2);
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */

boolean CNEQ(COMPLEX C1, COMPLEX C2);
/* Mengirimkan true jika C1 tidak sama dengan C2 */

/* ***************************************************************** */

#endif