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

void addFirstB(string judul, string pengarang, string penerbit, string tahun, string ISBN, int stok, int harga, List &L){
    addressB newValue = new eBaris;
    newValue -> info.judul = judul;
    newValue -> info.pengarang = pengarang;
    newValue -> info.penerbit = penerbit;
    newValue -> info.tahun = tahun;
    newValue -> info.ISBN = ISBN;
    newValue -> info.stok = stok;
    newValue -> info.harga = harga;
    newValue -> nextK = NULL;

    if(L.first == NULL){
        newValue -> nextB = NULL;
    } else {
        newValue -> nextB = L.first;
    }
    L.first = newValue;
    newValue = NULL;
}

void addAfterB(addressB &prev, string judul, string pengarang, string penerbit, string tahun, string ISBN, int stok, int harga){
    if(prev != NULL){
        addressB newValue = new eBaris;
        newValue -> info.judul = judul;
        newValue -> info.pengarang = pengarang;
        newValue -> info.penerbit = penerbit;
        newValue -> info.tahun = tahun;
        newValue -> info.ISBN = ISBN;
        newValue -> info.stok = stok;
        newValue -> info.harga = harga;

        if(prev -> nextB == NULL){
            newValue -> nextB = NULL;
        } else {
            newValue -> nextB = prev -> nextB;
        }
        prev -> nextB = newValue;
        newValue = NULL;
    }
}

void addLastB(string judul, string pengarang, string penerbit, string tahun, string ISBN, int stok, int harga, List &L){
    if(L.first == NULL) {
        addFirstB(judul, pengarang, penerbit, tahun, ISBN, stok, harga, L);
    } else {
        addressB last = L.first;
        while(last -> nextB != NULL) {
            last = last -> nextB;
        }
        addAfterB(last, judul, pengarang, penerbit, tahun, ISBN, stok, harga);
    }
}

void addFirstK(string nama, string noTelepon, int jumlah, addressB &L){
    addressK newValue = new eKolom;
    newValue -> info.nama = nama;
    newValue -> info.noTelepon = noTelepon;
    newValue -> info.jumlah = jumlah;

    if(L -> nextB == NULL) {
        newValue -> next = NULL;
    } else {
        newValue -> next = L -> nextK;
    }
    L -> nextK = newValue;
    newValue = NULL;
}

void addAfterK(addressK &prev, string nama, string noTelepon, int jumlah){
    if(prev != NULL) {
        addressK newValue = new eKolom;
        newValue -> info.nama = nama;
        newValue -> info.noTelepon = noTelepon;
        newValue -> info.jumlah = jumlah;

        if(prev -> next == NULL) {
            newValue -> next = NULL;
        } else {
            newValue -> next = prev -> next;
        }
        prev -> next = newValue;
        newValue = NULL;
    }
}

void addLastK(string nama, string noTelepon, int jumlah, addressB &L){
    if(L -> nextK == NULL){
        addFirstK(nama, noTelepon, jumlah, L);
    } else {
        addressK last = L -> nextK;
        while(last -> next != NULL) {
            last = last -> next;
        }
        addAfterK(last, nama, noTelepon, jumlah);
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
            cout << "Stok       : " << bantu -> info.stok << endl;
            cout << "Harga      : " << bantu -> info.harga << endl;
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
    int iStok, iHarga;

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
        cout << "Stok       : ";
        cin >> iStok;
        cout << "Harga      : ";
        cin >> iHarga;

        addressB Q = L.first;
        addressB cari;
        while(Q != NULL){
            if(iISBN == Q -> info.ISBN){
                cari = Q;
            }
            Q = Q -> nextB;
        }

        if(iISBN == cari -> info.ISBN){
            system("cls");
            cout << "=========================" << endl;
            cout << "Buku dengan nomor ISBN " << iISBN << "Sudah Terdaftar" << endl;
            cout << "=========================" << endl;
            delay(1000);
        } else {
            addLastB(iJudul, iPengarang, iPenerbit, iTahun, iISBN, iStok, iHarga, L);
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
    int iStok, iHarga;

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
            cout << "Stok       : ";
            cin >> iStok;
            cout << "Harga      : ";
            cin >> iHarga;

            edit -> info.judul = iJudul;
            edit -> info.pengarang = iPengarang;
            edit -> info.penerbit = iPenerbit;
            edit -> info.tahun = iTahun;
            edit -> info.stok = iStok;
            edit -> info.harga = iHarga;

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
    string confirm, iISBN;

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
            while(bantu != NULL && iISBN != bantu -> info.ISBN){
                hapus = bantu;
                bantu = bantu -> nextB;
            }

            // problem hapus
            if(countElementB(L) == 1 || bantu == L.first){
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

void cariBuku(){
    string x, iISBN;

    system("cls");
    cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "Input ISBN Buku yang ingin dicari: ";
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
    } else {
        cout << "Judul      : " << cari -> info.judul << endl;
        cout << "Pengarang  : " << cari -> info.pengarang << endl;
        cout << "Penerbit   : " << cari -> info.penerbit << endl;
        cout << "Tahun      : " << cari -> info.tahun << endl;
        cout << "ISBN       : " << cari -> info.ISBN << endl;
        cout << "Stok       : " << cari -> info.stok << endl;
        cout << "Harga      : " << cari -> info.harga << endl;
        cout << "------------------" << endl;
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
        cariBuku();
    }
}

void pembelian(){
    string confirm, x, y, z;
    int w;

    confirm = "yes";
    while(confirm != "no"){
        cout << "=================================================================" << endl;
        cout << "Note: Jika belum mengetahui ISBN silahkan lihat di menu Data Buku" << endl;
        cout << "=================================================================" << endl;
        cout << "Ketik ISBN Buku yang ingin dibeli: ";
        cin >> x;
        cout << "Nama Pembeli: ";
        cin >> y;
        cout << "No. Telepon: ";
        cin >> z;
        cout << "Jumlah: ";
        cin >> w;

        addressB Q = L.first;
        addressB cari;
        while(Q != NULL){
            if(x == Q -> info.ISBN){
                cari = Q;
            }
            Q = Q -> nextB;
        }

        if(x != cari -> info.ISBN){
            system("cls");
            cout << "=========================" << endl;
            cout << "Buku tidak terdaftar" << endl;
            cout << "=========================" << endl;
            delay(1000);
        } else {
            cout << "Total harga = " << cari -> info.harga * w << endl;
            cout << "Ingin membelinya? ";
            cin >> confirm;
            if(confirm == "yes"){
                addLastK(y, z, w, cari);
                cari -> info.stok = cari -> info.stok - w;
                system("cls");
                cout << "Buku berhasil di Di Beli";
                delay(1000);
            } else {
                system("cls");
                cout << "Membeli Buku di Batalkan";
                delay(1000);
            }
        }

        system("cls");
        cout << "::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Apakah anda ingin membeli Buku lagi : ";
        cin >> confirm;
    }
    system("cls");
    menu();
}

void cariPembeli(){
    string x;

    cout << "===========================================================================" << endl;
    cout << "Note: Jika belum mengetahui No. Telepon silahkan lihat di menu Data Pembeli" << endl;
    cout << "===========================================================================" << endl;
    cout << "Ketik No. Telepon Pembeli: ";
    cin >> x;

    addressB Q = L.first;
    addressK cari;
    while(Q != NULL){
        addressK bantu = Q -> nextK;
        while(bantu != NULL){
            if(x == bantu -> info.noTelepon){
                cari = bantu;
            }
            bantu = bantu -> next;
        }
        Q = Q -> nextB;
    }

    if(x != cari -> info.noTelepon){
        system("cls");
        cout << "=========================" << endl;
        cout << "Pembeli tidak terdaftar" << endl;
        cout << "=========================" << endl;
        delay(1000);
    } else {
        cout << "Nama Pembeli   : " << cari -> info.nama << endl;
        cout << "No. Telepon    : " << cari -> info.noTelepon << endl;
        cout << "Jumlah         : " << cari -> info.jumlah << endl;
        cout << "------------------" << endl;
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
        cariBuku();
    }
}

void dataPenjualan(){
    string x;
    int SUM = 0;

    if(L.first != NULL){
        addressB bantu = L.first;
        while(bantu != NULL){
            cout << "Judul          : " << bantu -> info.judul << endl;
            cout << "Pengarang      : " << bantu -> info.pengarang << endl;
            cout << "Penerbit       : " << bantu -> info.penerbit << endl;
            cout << "Tahun          : " << bantu -> info.tahun << endl;
            cout << "ISBN           : " << bantu -> info.ISBN << endl;

            int terjual = 0;
            addressK total = bantu -> nextK;
            while(total != NULL){
                terjual = terjual + total -> info.jumlah;
                total = total -> next;
            }

            cout << "Jumlah Pembeli : " << countElementK(bantu) << endl;
            cout << "Terjual        : " << terjual << endl;
            cout << "Pendapatan     : " << (bantu -> info.harga) * (terjual) << endl;
            cout << "------------------------------------" << endl;

            SUM = SUM + (bantu -> info.harga * terjual);

            bantu = bantu -> nextB;
        }
        cout << "====================================" << endl;
        cout << "Total Pendapatan Keseluruhan Buku: " << SUM << endl;
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

void dataPembeli(){
    string x;
    int SUM;

    if(L.first != NULL){
        addressB bantu = L.first;
        while(bantu != NULL){
            addressK pembeli = bantu -> nextK;
            while(pembeli != NULL){
                cout << "Nama Pembeli   : " << pembeli -> info.nama << endl;
                cout << "No. Telepon    : " << pembeli -> info.noTelepon << endl;
                cout << "------------------------------------" << endl;
                pembeli = pembeli -> next;
            }
            bantu = bantu -> nextB;
        }
        cout << "====================================" << endl;
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
            "(7. Data Pembeli)          (8. Cari Pembeli)" << endl <<
            "(9. Data Penjualan)        (0. Keluar)" << endl;
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
        cariBuku();
    }
    else if (x == "5")
    {
        printElement(L);
    }
    else if (x == "6")
    {
        pembelian();
    }
    else if (x == "7")
    {
        dataPembeli();
    }
    else if (x == "8")
    {
        cariPembeli();
    }
    else if (x == "9")
    {
        dataPenjualan();
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




