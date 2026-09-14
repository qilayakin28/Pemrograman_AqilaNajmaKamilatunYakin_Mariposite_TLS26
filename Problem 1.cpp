#include <iostream>

using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;

    int astronot[1000];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int urutan_eliminasi[1000];
    int jumlah_tereliminasi = 0;
    int ukuran_astronot = N;
    int index_sekarang = 0;

    while (ukuran_astronot > 1) {
        index_sekarang = (index_sekarang + K - 1) % ukuran_astronot;

        int nomor_tereliminasi = astronot[index_sekarang];
        urutan_eliminasi[jumlah_tereliminasi] = nomor_tereliminasi;
        jumlah_tereliminasi++;

        for (int i = index_sekarang; i < ukuran_astronot - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        ukuran_astronot--;

        if (nomor_tereliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        if (K < 2) {
            K = 2;
        }
    }

    cout << "Urutan Astronot yang Dieliminasi: ";
    for (int i = 0; i < jumlah_tereliminasi; i++) {
        cout << urutan_eliminasi[i];
        if (i < jumlah_tereliminasi - 1) {
            cout << " ";
        }
    }
    cout << endl;

    cout << "Astronot Terakhir yang Bertahan: " << astronot[0] << endl;

    return 0;
}