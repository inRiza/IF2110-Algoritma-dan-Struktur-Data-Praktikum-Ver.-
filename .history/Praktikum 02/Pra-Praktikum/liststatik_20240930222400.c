/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "boolean.h"
#include "liststatik.h"

/*  Kamus Umum */
// #define CAPACITY 100
/* Kapasitas penyimpanan */
// #define IDX_MIN 0
/* Indeks minimum list */
// #define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
// #define MARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
// typedef int ElType; /* type elemen List */
// typedef int IdxType;
// typedef struct
//{
// ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
//} ListStatik;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
// #define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
    int i;
    for (i = 0; i < CAPACITY; i++)
    {
        ELMT(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l)
{
    int count = 0;
    int i;
    for (i = 0; i < CAPACITY; i++)
    {
        if (ELMT(l, i) != MARK)
        {
            count++;
        }
        else
        {
            break; /*Ada elemen yg kosong pada list */
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l)
{
    if (listLength(l) != 0)
    {
        return IDX_MIN;
    }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l)
{
    if (listLength(l) != 0)
    {
        int i;
        int idx;
        for (i = 0; i < CAPACITY; i++)
        {
            if (ELMT(l, i) == MARK)
            {
                idx = i - 1;
                break;
            }
        }
        return idx;
    }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i)
{
    return (i >= IDX_MIN && i < CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i)
{
    return (i >= IDX_MIN && i < listLength(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l)
{
    return listLength(l) == 0;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l)
{
    return listLength(l) == CAPACITY;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
{
    int n, i;
    scanf("%d", &n);

    do
    {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY);

    for (i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        ELMT(*l, i) = num;
    }
    CreateListStatik(*l);
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l)
{
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        int i;
        printf("[");
        for (i = 0; i < listLength(l); i++)
        {
            printf("%d", ELMT(l, i));
            if (i < listLength(l) - 1)
            {
                printf(",");
            }
        }
        printf("]\n");
    }
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
{
    ListStatik lhasil;
    int i;
    CreateListStatik(&lhasil);
    if (listLength(l1) == listLength(l2) && !isEmpty(l1) && !isEmpty(l2))
    {
        for (i = 0; i < listLength(l1); i++)
        {
            if (plus)
            {
                ELMT(lhasil, i) = ELMT(l1, i) + ELMT(l2, i);
            }
            else
            {
                ELMT(lhasil, i) = ELMT(l1, i) - ELMT(l2, i);
            }
        }
    }
    return lhasil;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
{
    if (listLength(l1) == listLength(l2))
    {
        int i;
        for (i = 0; i < listLength(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                return false;
                break;
            }
            return true;
        }
    }
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val)
{
    int i;
    int idx = IDX_UNDEF;
    for (i = 0; i < listLength(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            idx = i;
            break;
        }
        else if (isEmpty(l))
        {
            break;
        }
    }
    return idx;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min)
{
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (int i = 1; i < listLength(l); i++)
    {
        if (ELMT(l, i) > *max)
            *max = ELMT(l, i);
        if (ELMT(l, i) < *min)
            *min = ELMT(l, i);
    }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val)
{
    int i;
    for (i = listLength(*l); i > 0; i--)
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }
    ELMT(*l, 0) = val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx)
{
    int i;
    if (!isEmpty(*l) && !isFull(*l) && isIdxEff(*l, idx))
    {
        for (i = listLength(*l); i > idx; i--)
        {
            ELMT(*l, i) = ELMT(*l, i - 1);
        }
        ELMT(*l, idx) = val;
    }
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val)
{
    ELMT(*l, listLength(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val)
{
    if (!isEmpty(*l))
    {
        *val = ELMT(*l, 0);
        for (int i = 0; i < listLength(*l) - 1; i++)
        {
            ELMT(*l, i) = ELMT(*l, i + 1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx)
{
    if (!isEmpty(*l))
    {
        *val = ELMT(*l, idx);
        for (int i = idx; i < listLength(*l) - 1; i++)
        {
            ELMT(*l, i) = ELMT(*l, i + 1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val)
{
    if (!isEmpty(*l))
    {
        *val = ELMT(*l, listLength(*l) - 1);
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc)
{
    for (int i = 0; i < listLength(*l) - 1; i++)
    {
        for (int j = i + 1; j < listLength(*l); j++)
        {
            if ((asc && ELMT(*l, i) > ELMT(*l, j)) || (!asc && ELMT(*l, i) < ELMT(*l, j)))
            {
                ElType temp = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, j);
                ELMT(*l, j) = temp;
            }
        }
    }
}

/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
