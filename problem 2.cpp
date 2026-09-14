#include <iostream>

using namespace std;

// Function manual untuk menghitung panjang string
int hitungPanjang(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function manual untuk mendapatkan posisi angka dari huruf A-Z (A=1 ... Z=26)
int posisiAlfabet(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return 0;
}

// Function manual untuk mengonversi posisi angka 1-26 kembali ke huruf kapital
char alfabetDariPosisi(int pos) {
    return 'A' + (pos - 1);
}

int main() {
    char pesan_asli[1000];
    if (!(cin >> pesan_asli)) return 0;

    char pesan_sandi[1000];
    int len = hitungPanjang(pesan_asli);
    int nilai_sebelumnya = 0;

    for (int i = 0; i < len; i++) {
        char huruf = pesan_asli[i];
        int nilai_huruf = posisiAlfabet(huruf);

        int nilai_baru = (nilai_huruf + nilai_sebelumnya - 1) % 26 + 1;
        pesan_sandi[i] = alfabetDariPosisi(nilai_baru);

        nilai_sebelumnya = nilai_huruf;
    }

    pesan_sandi[len] = '\0'; // Menutup c-string

    cout << "Pesan Sandi: " << pesan_sandi << endl;

    return 0;
}