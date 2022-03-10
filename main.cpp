#include <iostream>
#include <string.h>

using namespace std;

// Percobaan 1: Fungsi Membentuk Double Linked List
struct DoubleLinkedNode
{
    int bil;
    struct DoubleLinkedNode *prev;
    struct DoubleLinkedNode *next;
};

struct DoubleLinkedNode *head, *tail;

void bentuk_awal()
{
    struct DoubleLinkedNode *temp;
    int j = 0;
    char jawab[2];
    while (1)
    {
        temp = (struct DoubleLinkedNode *)malloc(sizeof(struct DoubleLinkedNode));

        printf("Masukkan bilangan :");
        scanf("%d", &temp->bil);
        if (j == 0)
        {
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }

        printf("Ada data lagi? (y):");
        scanf("%s", &jawab);
        if ((strcmp(jawab, "Y") == 0) || (strcmp(jawab, "y") == 0))
        {
            j++;
            continue;
        }
        else
            break;
    }
}

// Percobaan 2: Fungsi untuk Menampilkan Double Linked list dengan Metode LIFO
void tampil_list_lifo()
{
    printf("--- Tampil List LIFO ---\n");
    struct DoubleLinkedNode *lifo;
    printf("Data Bilangan yang Telah Diinputkan secara LIFO :\n");
    lifo = tail;
    
    while (lifo != NULL)
    {
        printf("%d\t", lifo->bil);
        lifo = lifo->prev;
    }
    printf("\n");
}

// Percobaan 3: Fungsi untuk Menampilkan Double Linked list dengan Metode FIFO
void tampil_list_fifo()
{
    printf("--- Tampil List FIFO ---\n");
    struct DoubleLinkedNode *fifo;
    printf("Data Bilangan yang Telah Diinputkan secara FIFO :\n");
    fifo = head;
    
    while (fifo != NULL)
    {
        printf("%d\t", fifo->bil);
        fifo = fifo->next;
    }
    printf("\n");
}

// Percobaan 4: Fungsi untuk Menyisipkan Simpul di Tengah
void sisip_simpul_tengah()
{
    printf("--- Sisip Simpul Tengah ---\n");
    int num;
    struct DoubleLinkedNode *sisip, *stl, *sbl;
    sisip = (struct DoubleLinkedNode *)malloc(sizeof(struct DoubleLinkedNode));
    printf("Tuliskan bilangan yang akan disisipkan : ");
    scanf("%d", &sisip->bil);
    sisip->next = NULL;
    sisip->prev = NULL;
    printf("Bilangan disisipkan sebelum data : ");
    scanf("%d", &num);
    stl = head;
    do
    {
        sbl = stl;
        stl = stl->next;
    } while (stl->bil != num);
    sisip->next = stl;
    sisip->prev = sbl;
    sbl->next = sisip;
    stl->prev = sisip;
}

// Percobaan 5: Fungsi untuk Menghapus Simpul Tertentu
void hapus_simpul()
{
    printf("--- Hapus Simpul ---\n");
    int num;
    struct DoubleLinkedNode *sbl, *hapus, *stl;
    printf("Masukkan data yang akan dihapus : ");
    scanf("%d", &num);
    hapus = head;
    // Menghapus Simpul Awal
    if (hapus->bil == num)
    {
        head = head->next;
        head->prev = NULL;
        free(hapus);
    }
    else
    {
        do
        {
            sbl = hapus;
            hapus = hapus->next;
        } while (hapus->bil != num);
        // Menghapus Simpul Terakhir
        if (hapus->next == NULL)
        {
            sbl->next = NULL;
            tail = sbl;
            free(hapus);
        }
        // Menghapus Simpul di Tengah
        else
        {
            stl = hapus->next;
            sbl->next = stl;
            stl->prev = sbl;
            free(hapus);
        }
    }
}

// ===== Fungsi main =====
int main()
{
    printf(">>> Silahkan input data doubly linked list:\n");
    bentuk_awal();
    system("cls");

    while (1)
    {
        printf(">>> Apakah aksi yang ingin dilakukan?\n");
        printf("1. Tampilkan list menggunakan metode LIFO\n");
        printf("2. Tampilkan list menggunakan metode FIFO\n");
        printf("3. Sisip simpul tengah\n");
        printf("4. Hapus simpul\n");
        printf("5. Keluar dari program\n");
        printf("Pilihan: ");
        string pilihan;
        cin >> pilihan;

        if (pilihan == "1")
        {
            system("cls");
            tampil_list_lifo();
            system("pause");
            system("cls");
        }
        else if (pilihan == "2")
        {
            system("cls");
            tampil_list_fifo();
            system("pause");
            system("cls");
        }
        else if (pilihan == "3")
        {
            system("cls");
            sisip_simpul_tengah();
            system("cls");
        }
        else if (pilihan == "4")
        {
            system("cls");
            hapus_simpul();
            system("cls");
        }
        else if (pilihan == "5")
        {
            printf("Terima kasih telah menggunakan program ini :)");
            break;
        }
        else
        {
            printf("Silahkan pilih antara 1-5\n");
            system("pause");
            system("cls");
        }
    }
}
