// Kelompok 8
// Jeremy Pardede 13321031
// Benni Sibarani 13321035
// Brian Napitupulu 13321036
// Joe Manurung 13321041
// Risda Malau 13321051

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeaderLibray.h"

int main()
{
    dbuku *B1 = (dbuku *)malloc(sizeof(dbuku) * 1);
    dbuku *B2 = (dbuku *)malloc(sizeof(dbuku) * 1);
    ddosen *D1 = (ddosen *)malloc(sizeof(ddosen) * 1);
    ddosen *D2 = (ddosen *)malloc(sizeof(ddosen) * 1);
    int opsi, pilih_dosen, batas, i;
    char NIDN[20];

    strcpy(B1->ISBN, "M212221");
    strcpy(B1->judul_buku, "Programing");
    strcpy(B1->jenis_buku, "Ilmu Pengetahuan");
    strcpy(B1->author, "Niel");
    strcpy(B1->NIDN, "C213212");
    B1->jumlah = 2;
    B1->alamat = B2;

    strcpy(B2->ISBN, "M198982");
    strcpy(B2->judul_buku, "Dedek Dari Gua Hantu");
    strcpy(B2->jenis_buku, "Dongeng");
    strcpy(B2->author, "Jaultop");
    strcpy(B1->NIDN, "C43243");
    B2->jumlah = 2;
    B2->alamat = NULL;

    strcpy(D1->NIDN, "M1232132");
    strcpy(D1->nama, "SiPanorop");
    strcpy(D1->no_telp, "0526281622321");
    D1->alamat = D2;

    strcpy(D2->NIDN, "M214124");
    strcpy(D2->nama, "Sipanyodok");
    strcpy(D2->no_telp, "01234567890");
    D2->alamat = NULL;

    printf("SELAMAT DATANG DI PERPUSTAKAAN IT DEL\n");
    printf("\tMenu\n");
    printf("1. Tampilkan Semua Buku\n");
    printf("2. Tampilkan Data Dosen\n");
    printf("3. Cari Buku Berdasarkan ISBN\n");
    printf("4. Cari Buku Berdasarkan NIDN\n");
    printf("5. Tambahkan Buku\n");
    printf("6. Keluar\n");

    do
    {
        printf("\nPILIH MENU\t: ");
        scanf("%d", &opsi);

        switch (opsi)
        {
        case 1:
            printf("\n\tData Buku\n");
            cetakDataBuku(B1);
            printf("\n");
            break;
        case 2:
            printf("\n\tData Dosen\n");
            cetakDataDosen(D1);
            printf("\n");
            break;
        case 3:
            printf("\n\tCari Buku Berdasarkan ISBN\n");
            char cari[100];
            printf("Masukkan ISBN\t: ");
            scanf("%s", &cari);
            searchBuku(B1, cari);
            printf("\n");
            break;
        case 4:
            printf("\nCari Jumlah Buku Hibanan Dosen\n");
            char search[100];
            printf("Masukkan NIDN\t: ");
            scanf("%s", &search);
            searchNIDN(D1, B1, search);
            printf("\n");
            break;
        case 5:
            printf("\n\tTambah Data Buku\n");
            printf("Data Dosen\n");
            cetakDataDosen(D1);
            if (D1 == NULL)
            {
                printf("Data Dosen masih kosong!\n");
                break;
            }
            else
            {
                printf("Pilih dosen yang ingin donasi buku: ");
                scanf("%d", &pilih_dosen);
                if (getNIDN(D1, pilih_dosen) == NULL)
                {
                    break;
                }
                else
                {
                    strcpy(NIDN, getNIDN(D1, pilih_dosen));
                }
            }
            printf("Masukkan Jumlah Data Buku(Sesuai Jumlah data buku realnya):");
            scanf(" %d", &batas);

            for (i = 1; i <= batas; i++)
            {
                dbuku *DataBuku = malloc(sizeof(dbuku) * 1);
                printf("Masukkan ISBN %d\t: ", i);
                scanf("%[^\n]s", DataBuku->ISBN);

                printf("Masukkan Judul Buku %d\t: ", i);
                scanf("%[^\n]s", DataBuku->judul_buku);
                printf("Masukkan Jenis Buku %d\t: ", i);
                scanf("%[^\n]s", DataBuku->jenis_buku);
                printf("Masukkan Author %d\t: ", i);
                scanf("%[^\n]s", DataBuku->author);
                strcpy(DataBuku->NIDN, NIDN);
                printf("Masukkan Jumlah %d\t: ", i);
                scanf("%[^\n]s", &DataBuku->jumlah);

                if (B1 == NULL)
                {
                    AddNewDataBuku(&B1, DataBuku);
                }
                else
                {
                    AddNextDataBuku(&B1, DataBuku);
                }
            }
            printf("\n");
            cetakDataBuku(B1);
            break;
        case 6:
            printf("Terimakasih Telah Mengunjungi Apkliasi Kami :)");
            printf("\n\t\tKelompok 8");
            exit(0);
            break;
        }

    } while (opsi != 0);

    return 1;
}
