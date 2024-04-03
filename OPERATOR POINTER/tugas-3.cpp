#include <iostream>
#include <string>

using namespace std;

// Struct untuk data nilai mahasiswa
struct Nilai {
    float absen;
    float tugas;
    float uts;
    float uas;
    float nilai_akhir;
    char nilai_huruf;
};

// Struct untuk data mahasiswa
struct Mahasiswa {
    string npm;
    string nama;
    Nilai nilai;
};

// Fungsi untuk menghitung nilai huruf berdasarkan nilai akhir
char hitungNilaiHuruf(float nilai_akhir) {
    if (nilai_akhir > 80)
        return 'A';
    else if (nilai_akhir > 70)
        return 'B';
    else if (nilai_akhir > 60)
        return 'C';
    else
        return 'D';
}

int main() {
    Mahasiswa daftar_mahasiswa[20];
    int jumlah_mahasiswa = 0;

    char menu;
    do {
        cout << "Menu Program:" << endl;
        cout << "a. Input Data Mahasiswa" << endl;
        cout << "b. Tampil Data Mahasiswa" << endl;
        cout << "c. Edit Data Mahasiswa" << endl;
        cout << "d. Hapus Data Mahasiswa" << endl;
        cout << "e. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 'a': {
                // Input Data Mahasiswa
                if (jumlah_mahasiswa < 20) {
                    Mahasiswa mhs;
                    cout << "NPM: ";
                    cin >> mhs.npm;
                    cout << "Nama: ";
                    cin >> mhs.nama;
                    cout << "Nilai Absen: ";
                    cin >> mhs.nilai.absen;
                    cout << "Nilai Tugas: ";
                    cin >> mhs.nilai.tugas;
                    cout << "Nilai UTS: ";
                    cin >> mhs.nilai.uts;
                    cout << "Nilai UAS: ";
                    cin >> mhs.nilai.uas;

                    // Hitung nilai akhir
                    mhs.nilai.nilai_akhir = 0.1 * mhs.nilai.absen + 0.2 * mhs.nilai.tugas + 0.3 * mhs.nilai.uts + 0.4 * mhs.nilai.uas;

                    // Hitung nilai huruf
                    mhs.nilai.nilai_huruf = hitungNilaiHuruf(mhs.nilai.nilai_akhir);

                    // Simpan data mahasiswa
                    daftar_mahasiswa[jumlah_mahasiswa++] = mhs;

                    cout << "Data mahasiswa berhasil ditambahkan." << endl;
                } else {
                    cout << "Jumlah maksimum mahasiswa telah tercapai." << endl;
                }
                break;
            }
            case 'b': {
                // Tampil Data Mahasiswa
                if (jumlah_mahasiswa > 0) {
                    cout << "Data Mahasiswa:" << endl;
                    for (int i = 0; i < jumlah_mahasiswa; ++i) {
                        cout << "NPM: " << daftar_mahasiswa[i].npm << endl;
                        cout << "Nama: " << daftar_mahasiswa[i].nama << endl;
                        cout << "Nilai Akhir: " << daftar_mahasiswa[i].nilai.nilai_akhir << endl;
                        cout << "Nilai Huruf: " << daftar_mahasiswa[i].nilai.nilai_huruf << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Belum ada data mahasiswa." << endl;
                }
                break;
            }
            case 'c': {
                // Edit Data Mahasiswa
                string cari_npm;
                cout << "Masukkan NPM mahasiswa yang ingin diubah: ";
                cin >> cari_npm;

                bool ditemukan = false;
                for (int i = 0; i < jumlah_mahasiswa; ++i) {
                    if (daftar_mahasiswa[i].npm == cari_npm) {
                        cout << "Nama baru: ";
                        cin >> daftar_mahasiswa[i].nama;
                        cout << "Nilai Absen baru: ";
                        cin >> daftar_mahasiswa[i].nilai.absen;
                        cout << "Nilai Tugas baru: ";
                        cin >> daftar_mahasiswa[i].nilai.tugas;
                        cout << "Nilai UTS baru: ";
                        cin >> daftar_mahasiswa[i].nilai.uts;
                        cout << "Nilai UAS baru: ";
                        cin >> daftar_mahasiswa[i].nilai.uas;

                        // Hitung nilai akhir dan nilai huruf baru
                        daftar_mahasiswa[i].nilai.nilai_akhir = 0.1 * daftar_mahasiswa[i].nilai.absen + 0.2 * daftar_mahasiswa[i].nilai.tugas + 0.3 * daftar_mahasiswa[i].nilai.uts + 0.4 * daftar_mahasiswa[i].nilai.uas;
                        daftar_mahasiswa[i].nilai.nilai_huruf = hitungNilaiHuruf(daftar_mahasiswa[i].nilai.nilai_akhir);

                        cout << "Data mahasiswa berhasil diubah." << endl;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan)
                    cout << "Mahasiswa dengan NPM tersebut tidak ditemukan." << endl;
                break;
            }
            case 'd': {
                // Hapus Data Mahasiswa
                string cari_npm;
                cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
                cin >> cari_npm;

                bool ditemukan = false;
                for (int i = 0; i < jumlah_mahasiswa; ++i) {
                    if (daftar_mahasiswa[i].npm == cari_npm) {
                        // Geser data ke kiri untuk menghapus
                        for (int j = i; j < jumlah_mahasiswa - 1; ++j) {
                            daftar_mahasiswa[j] = daftar_mahasiswa[j + 1];
                        }
                        jumlah_mahasiswa--;

                        cout << "Data mahasiswa berhasil dihapus." << endl;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan)
                    cout << "Mahasiswa dengan NPM tersebut tidak ditemukan." << endl;
                break;
            }
            case 'e': {
                // Keluar dari program
                cout << "Program selesai." << endl;
                break;
            }
            default:
                cout << "Menu tidak valid." << endl;
        }
    } while (menu != 'e');

    return 0;
}