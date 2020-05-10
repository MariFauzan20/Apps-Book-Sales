#include "multiLink.h"

List L;
bool listFull = false;

void createList(List &L){
    L.first = NULL;
}

int countElementB(List L){
    int hasil = 0;

    if(L.first != NULL){
        addressB adrHelp = L.first;
        while(adrHelp != NULL){
            hasil = hasil + 1;
            adrHelp = adrHelp -> nextB;
        }
    }
    return hasil;
}

int countElementK(addressB L){
    int hasil = 0;

    if(L -> nextK != NULL){
        addressK adrHelp = L -> nextK;
        while(adrHelp != NULL){
            hasil = hasil + 1;
            adrHelp = adrHelp -> next;
        }
    }
    return hasil;
}

void addFirstB(string judul, string pengarang, string penerbit, string tahun, string ISBN, List &L){
    addressB newValue = new eBaris;
    newValue -> info.judul = judul;
    newValue -> info.pengarang = pengarang;
    newValue -> info.penerbit = penerbit;
    newValue -> info.tahun = tahun;
    newValue -> info.ISBN = ISBN;
    newValue -> nextK = NULL;

    if(L.first == NULL){
        newValue -> nextB = NULL;
    } else {
        newValue -> nextB = L.first;
    }
    L.first = newValue;
    newValue = NULL;
}

void addAfterB(addressB &prev, string judul, string pengarang, string penerbit, string tahun, string ISBN){
    if(prev != NULL){
        addressB newValue = new eBaris;
        newValue -> info.judul = judul;
        newValue -> info.pengarang = pengarang;
        newValue -> info.penerbit = penerbit;
        newValue -> info.tahun = tahun;
        newValue -> info.ISBN = ISBN;

        if(prev -> nextB == NULL){
            newValue -> nextB = NULL;
        } else {
            newValue -> nextB = prev -> nextB;
        }
        prev -> nextB = newValue;
        newValue = NULL;
    }
}

void addLastB(string judul, string pengarang, string penerbit, string tahun, string ISBN, List &L){
    if(L.first == NULL) {
        addFirstB(judul, pengarang, penerbit, tahun, ISBN, L);
    } else {
        addressB last = L.first;
        while(last -> nextB != NULL) {
            last = last -> nextB;
        }
        addAfterB(last, judul, pengarang, penerbit, tahun, ISBN);
    }
}

void addFirstK(string nama, string noTelepon, addressB &L){
    addressK newValue = new eKolom;
    newValue -> info.nama = nama;
    newValue -> info.noTelepon = noTelepon;

    if(L -> nextB == NULL) {
        newValue -> next = NULL;
    } else {
        newValue -> next = L -> nextK;
    }
    L -> nextK = newValue;
    newValue = NULL;
}

void addAfterK(addressK &prev, string nama, string noTelepon){
    if(prev != NULL) {
        addressK newValue = new eKolom;
        newValue -> info.nama = nama;
        newValue -> info.noTelepon = noTelepon;

        if(prev -> next == NULL) {
            newValue -> next = NULL;
        } else {
            newValue -> next = prev -> next;
        }
        prev -> next = newValue;
        newValue = NULL;
    }
}

void addLastK(string nama, string noTelepon, addressB &L){
    if(L -> nextK == NULL){
        addFirstK(nama, noTelepon, L);
    } else {
        addressK last = L -> nextK;
        while(last -> next != NULL) {
            last = last -> next;
        }
        addAfterK(last, nama, noTelepon);
    }
}

void delFirstK(addressB &L){
    if(L -> nextK != NULL){
        addressK hapus = L -> nextK;
        if(countElementK(L) == 1){
            L -> nextK = NULL;
        } else {
            L -> nextK = L -> nextK -> next;
        }
        hapus -> next = NULL;
        delete hapus;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfterK(addressK &prev){
    if(prev != NULL) {
        addressK hapus = prev -> next;
        if(hapus != NULL) {
            if(hapus -> next = NULL){
                prev -> next = NULL;
            } else {
                prev -> next = hapus -> next;
            }
            hapus -> next = NULL;
            delete hapus;
        }
    }
}

void delLastK(addressB &L){
    if(L -> nextK != NULL){
        if(countElementK(L) == 1){
            delFirstK(L);
        } else {
            addressK last = L -> nextK;
            addressK before_last;
            while(last -> next != NULL){
                before_last = last;
                last = last -> next;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(addressB &L){
    if(countElementK(L) != 0){
        int i;
        for(i = countElementK(L); i >= 1; i--){
            delLastK(L);
        }
    }
}

void delFirstB(List &L){
    if(L.first != NULL){
        addressB hapus = L.first;
        if(hapus -> nextK != NULL){
            delAllK(hapus);
        }

        if(countElementB(L) == 1){
            L.first = NULL;
        } else {
            L.first = L.first -> nextB;
        }
        hapus -> nextB = NULL;
        delete hapus;
    } else {
        cout << "List Kosong" << endl;
    }
}

void delAfterB(addressB &prev){
    if(prev != NULL){
        addressB hapus = prev -> nextB;
        if(hapus != NULL){
            if(hapus -> nextK != NULL) {
                delAllK(hapus);
            }

            if(hapus -> nextB == NULL){
                prev -> nextB = NULL;
            } else {
                prev -> nextB = hapus -> nextB;
            }
            hapus -> nextK = NULL;
            delete hapus;
        }
    }
}

void delLastB(List &L){
    if(L.first != NULL){
        if(countElementB(L) == 1){
            delFirstB(L);
        } else {
            addressB last = L.first;
            addressB before_last;
            while(last -> nextB != NULL){
                before_last = last;
                last = last -> nextB;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(List &L){
    if(countElementB(L) != 0){
        int i;
        for(i = countElementB(L); i >= 1; i--){
            delLastB(L);
        }
    }
}

void printElement(List L){
    string x;

    if(L.first != NULL){
        addressB bantu = L.first;
        while(bantu != NULL){
            cout << "Judul      : " << bantu -> info.judul << endl;
            cout << "Pengarang  : " << bantu -> info.pengarang << endl;
            cout << "Penerbit   : " << bantu -> info.penerbit << endl;
            cout << "Tahun      : " << bantu -> info.tahun << endl;
            cout << "ISBN       : " << bantu -> info.ISBN << endl;
            addressK bantuKolom = bantu -> nextK;
            while(bantuKolom != NULL){
                cout << "Nama           : " << bantuKolom -> info.nama << endl;
                cout << "No. Telepon    : " << bantuKolom -> info.noTelepon << endl;
                bantuKolom = bantuKolom -> next;
            }
            cout << "------------------" << endl;
            bantu = bantu -> nextB;
        }
    } else {
        cout << "List Kosong" << endl;
    }

    cout << endl;
    cout << "Ketik '0' untuk kembali ke Menu Utama" << endl;
    cout << "Ketik : ";
    cin >> x;
    if(x == "0"){
        system("cls");
        menu();
    } else {
        system("cls");
        printElement(L);
    }
}

void tambahBuku(){
    string confirm, iJudul, iPengarang, iPenerbit, iTahun, iISBN;

	cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "Apakah Ingin Tambah Data Buku : ";
    cin >> confirm;
    while(confirm != "no"){
        cout << "Judul      : ";
        cin >> iJudul;
        cout << "Pengarang  : ";
        cin >> iPengarang;
        cout << "Penerbit   : ";
        cin >> iPenerbit;
        cout << "Tahun      : ";
        cin >> iTahun;
        cout << "ISBN       : ";
        cin >> iISBN;

        addressB Q = L.first;
        addressB cari;
        while(Q != NULL){
            if(iISBN == Q -> info.ISBN){
                cari = Q;
            }
            Q = Q -> nextB;
        }
//lanjut
        if(iISBN == cari -> info.ISBN){
            system("cls");
            cout << "=========================" << endl;
            cout << "Buku dengan nomor ISBN " << iISBN << "Sudah Terdaftar" << endl;
            cout << "=========================" << endl;
            delay(1000);
        } else {
            addLastB(iJudul, iPengarang, iPenerbit, iTahun, iISBN, L);
            system("cls");
            cout << "data berhasil di Tambah";
            delay(1000);
        }

        system("cls");
        cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Apakah anda ingin Tambah Data lagi : ";
        cin >> confirm;
    }
    system("cls");
    menu();
}

void editBuku(){
    string confirm, iJudul, iPengarang, iPenerbit, iTahun, iISBN;

    confirm = "yes";
    while(confirm != "no"){
        system("cls");
        cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Input ISBN Buku yang ingin di edit: ";
        cin >> iISBN;

        addressB Q = L.first;
        addressB edit;
        while(Q != NULL){
            if(iISBN == Q -> info.ISBN){
                edit = Q;
            }
            Q = Q -> nextB;
        }

        if(iISBN != edit -> info.ISBN){
            system("cls");
            cout << "=========================" << endl;
            cout << "Buku tidak terdaftar" << endl;
            cout << "=========================" << endl;
            delay(1000);
        } else {
            cout << "Judul      : ";
            cin >> iJudul;
            cout << "Pengarang  : ";
            cin >> iPengarang;
            cout << "Penerbit   : ";
            cin >> iPenerbit;
            cout << "Tahun      : ";
            cin >> iTahun;

            edit -> info.judul = iJudul;
            edit -> info.pengarang = iPengarang;
            edit -> info.penerbit = iPenerbit;
            edit -> info.tahun = iTahun;

            system("cls");
            cout << "data berhasil di edit";
            delay(1000);
        }

        system("cls");
        cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Apakah anda ingin Edit Data lagi : ";
        cin >> confirm;
    }
	system("cls");
    menu();
}

void hapusBuku(){
    string confirm, iJudul, iPengarang, iPenerbit, iTahun, iISBN;

    confirm = "yes";
    while(confirm != "no"){
        system("cls");
        cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Input ISBN Buku yang ingin dihapus: ";
        cin >> iISBN;

        addressB Q = L.first;
        addressB cari;
        while(Q != NULL){
            if(iISBN == Q -> info.ISBN){
                cari = Q;
            }
            Q = Q -> nextB;
        }

        if(iISBN != cari -> info.ISBN){
            system("cls");
            cout << "=========================" << endl;
            cout << "Buku tidak terdaftar" << endl;
            cout << "=========================" << endl;
            delay(1000);
        } else {
            addressB bantu = L.first;
            addressB hapus;
            while(bantu -> nextB != NULL && iISBN != bantu -> info.ISBN){
                hapus = bantu;
                bantu = bantu -> nextB;
            }

            if(countElementB(L) == 1){
                delFirstB(L);
            } else {
                delAfterB(hapus);
            }
            system("cls");
            cout << "data berhasil di hapus";
            delay(1000);
        }

        system("cls");
        cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Apakah anda ingin Hapus Data lagi : ";
        cin >> confirm;
    }
	system("cls");
    menu();
}

void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void menu(){
    string x;

    system("cls");
    cout << ".::Selamat Datang di Aplikasi Penjualan Buku::." << endl;
    cout << "===============================================" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "(1. Tambah Data Buku)      (2. Edit Data Buku)" << endl <<
            "(3. Hapus Data Buku)       (4. Cari Buku)" << endl <<
            "(5. Data Buku)             (6. Pembelian)" << endl <<
            "(7. Cari Pembeli)          (8. Data Penjualan)" << endl <<
            "(0. Keluar)" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::" << endl << "Pilih : ";
    cin >> x;
    system("cls");
    if(x == "1")
    {
        tambahBuku();
    }
    else if(x == "2")
    {
        editBuku();
    }
    else if (x == "3")
    {
        hapusBuku();
    }
    else if (x == "4")
    {

    }
    else if (x == "5")
    {
        printElement(L);
    }
    else if (x == "0")
    {
        cout << "====================================" << endl;
        cout << "Terima Kasih, Sampai Jumpa Kembali." << endl;
        cout << "====================================";
        cout << endl;
    }
    else
    {
        menu();
    }
}




