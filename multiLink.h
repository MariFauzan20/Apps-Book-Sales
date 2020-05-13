#ifndef MULTILINK_H_INCLUDED
#define MULTILINK_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

struct buku
{
    string judul;
    string pengarang;
    string penerbit;
    string tahun;
    string ISBN;
    int stok;
    int harga;
};

struct pembeli
{
    string nama;
    string noTelepon;
    int jumlah;
};

typedef buku infotypeBaris;
typedef pembeli infotypeKolom;
typedef struct eKolom *addressK;
typedef struct eBaris *addressB;

struct eKolom
{
    infotypeKolom info;
    addressK next;
    addressK prev;
};

struct eBaris
{
    infotypeBaris info;
    addressK nextK;
    addressK prev;
    addressB nextB;
};

struct List
{
    addressB first;
};

void createList(List &L);
int countElementB(List L);
int countElementK(addressB L);

void addFirstB(string judul, string pengarang, string penerbit, string tahun, string ISBN, int stok, int harga, List &L);
void addAfterB(addressB &prev, string judul, string pengarang, string penerbit, string tahun, string ISBN, int stok, int harga);
void addLastB(string judul, string pengarang, string penerbit, string tahun, string ISBN, int stok, int harga, List &L);

void addFirstK(string nama, string noTelepon, int jumlah, addressB &L);
void addAfterK(addressK &prev, string nama, string noTelepon, int jumlah);
void addLastK(string nama, string noTelepon, int jumlah, addressB &L);

void delFirstK(addressB &L);
void delAfterK(addressK &prev);
void delLastK(addressB &L);
void delAllK(addressB &L);

void delFirstB(List &L);
void delAfterB(addressB &prev);
void delLastB(List &L);
void delAllB(List &L);

void printElement(List L);

void delay(unsigned int mseconds);

void menu();
void tambahBuku();
void cari();
void editBuku();
void hapusBuku();
void pembelian();
void dataPembeli();
void dataPenjualan();
void cariPembeli();

#endif // MULTILINK_H_INCLUDED
