#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Ticket
{
    string nama;
    string no_identitas;
    string jenis_penerbangan;
    string maskapai;
    int jumlah;
    int harga;
    Ticket *next;
};

Ticket *head = nullptr;

// struct global
struct pesawat
{
    int jenis_penerbangan;
    string domestik;
    string internasional;
    string maskapai;
    bool penerbangan;
};

// untuk menampilkan array domestik, internasional, dan maskapai
void tampilkanArray(string array[], int ukuran)
{
    for (int i = 0; i < ukuran; ++i)
    {
        cout << i + 1 << ". " << array[i] << "\n";
    }
    cout << endl;
}

void tambahTicket(const string nama, const string no, const string jenis_penerbangan, const string maskapai, int jumlah, int harga)
{
    Ticket *newTicket = new Ticket;
    newTicket->nama = nama;
    newTicket->no_identitas = no;
    newTicket->jenis_penerbangan = jenis_penerbangan;
    newTicket->maskapai = maskapai;
    newTicket->jumlah = jumlah;
    newTicket->harga = harga;
    newTicket->next = nullptr;

    if (head == nullptr)
    {
        head = newTicket;
    }
    else
    {
        Ticket *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newTicket;
    }
}

void tampilkanTiket()
{
    Ticket *temp = head;
    cout << "\n========== Daftar Tiket yang Dibeli ==========\n";
    while (temp != nullptr)
    {
        cout << "Nama Pelanggan: " << temp->nama << endl;
        cout << "No. Identitas: " << temp->no_identitas << endl;
        cout << "Jenis Penerbangan: " << temp->jenis_penerbangan << endl;
        cout << "Maskapai: " << temp->maskapai << endl;
        cout << "Jumlah Tiket: " << temp->jumlah << endl;
        cout << "Harga Tiket: Rp " << temp->harga << endl;
        cout << "=============================================\n";
        temp = temp->next;
    }
}

// untuk menampilkan informasi pembayaran
void informasiPembayaran(const string nama, const string no, const string penerbangan_domestik, const string penerbangan_internasional, bool isDomestik, const string maskapai_pesawat, const int jumlah, const int harga)
{
    string kode_pembayaran; // variabel lokal
    srand(time(0));
    // berisi nomor random
    int randomNum = rand() % 10000;
    string kodeUnik = to_string(randomNum);

    //
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // untuk mengatur tanggal
    string tanggal = to_string(1900 + ltm->tm_year) + '-' + // untuk menampilkan tahun saat ini
                     to_string(1 + ltm->tm_mon) + '-' +     // untuk menampilkan bulan saat ini
                     to_string(ltm->tm_mday);               // untuk menampilkan tanggal saat ini

    // untuk mengatur waktu
    string waktu = to_string(ltm->tm_hour) + ':' + // untuk menampilkan jam saat ini
                   to_string(ltm->tm_min) + ':' +  // untuk menampilkan menit saat ini
                   to_string(ltm->tm_sec);         // untuk menampilkan detik saat ini

    // informasi pembayaran yang muncul diakhir
    cout << "\n===== Informasi Pembayaran =====";
    cout << "\n=========== TIKET I.O ==========\n"
         << endl;
    cout << "Nama Pelanggan : " << nama << endl;
    cout << "No. Identitas : " << no << endl;
    // untuk menampilkan tujuan
    if (isDomestik)
    {
        tambahTicket(nama, no, penerbangan_domestik, maskapai_pesawat, jumlah, harga);
    }
    else
    {
        tambahTicket(nama, no, penerbangan_internasional, maskapai_pesawat, jumlah, harga);
    }
    cout << "Maskapai : " << maskapai_pesawat << endl; // mengambil dari array maskapai_pesawat
    cout << "Jumlah Tiket : " << jumlah << endl;       // menggambil dari struct lokal yang berada dalam main
    cout << "Harga Tiket : Rp " << harga << endl;      // menggambil dari struct lokal yang berada dalam main
    cout << "Harga Pembayaran : Rp " << harga * jumlah << endl;
    cout << "Tanggal Pembelian : " << tanggal << "\n"; // diambil dari fungsi informasi pendaftaran
    cout << "Waktu Pembelian: " << waktu << "\n";      // diambil dari fungsi informasi pendaftaran
    cout << "Kode Pembayaran : " << kodeUnik << "\n";  // untuk menampilkan kode pembyaran yang diambil dari fungsi informasi pendaftaran
    cout << "\n================================\n";

    do // perulangan jika kode pembayaran yang dimasukan salah maka akan terus mengulang dan jika benar maka akan selesai
    {
        cout << "Konfirmasi Kode Pembayaran : ";
        cin >> kode_pembayaran;
        if (kode_pembayaran != kodeUnik)
        {
            cout << "Kode Pembayaran yang dimasukkan salah. Coba lagi." << endl;
        }

    } while (kode_pembayaran != kodeUnik);
    cout << "\nTransaksi Berhasil. Keselamatan Anda adalah Prioritas Kami.\n";
}

// fungsi untuk menyimpan harga tiket
int hargaTiket(const string penerbangan_domestik, const string penerbangan_internasional)
{
    int harga = 0; // int harga untuk fungsi (lokal)
    if (!penerbangan_internasional.empty())
    {
        if (penerbangan_internasional == "MEDINAH")
        {
            harga = 1000000;
        }
        if (penerbangan_internasional == "QATAR")
        {
            harga = 1500000;
        }
        if (penerbangan_internasional == "TOKYO")
        {
            harga = 2000000;
        }
        if (penerbangan_internasional == "SYDNEY")
        {
            harga = 2500000;
        }
        if (penerbangan_internasional == "SEOUL")
        {
            harga = 3000000;
        }
        if (penerbangan_internasional == "BANGKOK")
        {
            harga = 3500000;
        }
        if (penerbangan_internasional == "KUALA LUMPUR")
        {
            harga = 4000000;
        }
        if (penerbangan_internasional == "SINGPORE")
        {
            harga = 4500000;
        }
        if (penerbangan_internasional == "SHANGHAI")
        {
            harga = 5000000;
        }
        if (penerbangan_internasional == "HONGKONG")
        {
            harga = 5500000;
        }
    }
    else if (!penerbangan_domestik.empty()) // For domestic flights
    {
        if (penerbangan_domestik == "JAKARTA")
        {
            harga = 1000000;
        }
        if (penerbangan_domestik == "BANDUNG")
        {
            harga = 1500000;
        }
        if (penerbangan_domestik == "BOGOR")
        {
            harga = 2000000;
        }
        if (penerbangan_domestik == "BALI")
        {
            harga = 2500000;
        }
        if (penerbangan_domestik == "PADANG")
        {
            harga = 3000000;
        }
        if (penerbangan_domestik == "PONTIANAK")
        {
            harga = 3500000;
        }
        if (penerbangan_domestik == "SOLO")
        {
            harga = 4000000;
        }
        if (penerbangan_domestik == "BALIKPAPAN")
        {
            harga = 4500000;
        }
        if (penerbangan_domestik == "MALANG")
        {
            harga = 5000000;
        }
        if (penerbangan_domestik == "ACEH")
        {
            harga = 5500000;
        }
    }
    return harga;
}
string nama; // variabel global

int main()
{
    // struct lokal
    struct siswa
    {
        int harga;
        int jumlah;
        char pilihan;
    } var;

    string no; // variabel lokal
    // struct pesawat (global) yang diberi nama flights
    pesawat flights;

    // pengisian array penerbangan_domestik, penerbangan_internasional, maskapai_pesawat
    string penerbangan_domestik[10] = {"JAKARTA", "BANDUNG", "BOGOR", "BALI", "PADANG", "PONTIANAK", "SOLO", "BALIKPAPAN", "MALANG", "ACEH"};               // Array penerbangan_domestik
    string penerbangan_internasional[10] = {"MEDINAH", "QATAR", "TOKYO", "SYDNEY", "SEOUL", "BANGKOK", "KUALA LUMPUR", "SINGPORE", "SHANGHAI", "HONGKONG"}; // Array penerbangan_internasional
    string maskapai_pesawat[5] = {"GARUDAINDONESIA", "WINGSAIR", "LIONAIR", "BATIKAIR", "CITILINK"};                                                        // Array maskapai_pesawat

    cout << "------------------------------------------------------------------" << endl;
    cout << "                  SELAMAT DATANG DI TIKET.IO" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "\nPilih Penerbangan" << endl;
    cout << "1. Penerbangan Domestik" << endl;
    cout << "2. Penerbangan Internasional" << endl;
    cout << "3. KELUAR" << endl;

    // meminta user untuk memilih pilihan yang mana
    cout << "\nMasukan pilihan penerbangan : ";
    cin >> flights.jenis_penerbangan; // dimasukkan kedalam jenis penerbangan yg berada di struct pesawat (global)

    // untuk membbuat keputusan akan menjalankan yang mana
    switch (flights.jenis_penerbangan)
    {
    case 1: // berisi penerbangan domestik
        cout << "\nANDA MEMILIH PENERBANGAN DOMESTIK" << endl;
        cout << "Tujuan Penerbangan Domestik :\n";
        tampilkanArray(penerbangan_domestik, 10); // untuk menampilkan pilihan tujuan yang diambil dari array penerbangan_domestik
        do // perulangan untuk memastikan apakah tujuan yang dipilih ada, apabila tidak ada ulang lagi sampai benar

        {
            flights.penerbangan = true; // Tetapkan ke true di awal setiap iterasi loop
            cout << "Masukan Penerbangan Domestik yang dituju (Gunakan Huruf KAPITAL) : ";
            cin >> flights.domestik;
            for (int i = 0; i < 10; ++i) // Mengecek apakah nilai penerbangan domestik berada dalam array penerbangan_domestik
            {
                if (flights.domestik == penerbangan_domestik[i])
                {
                    flights.penerbangan = false;
                    break;
                }
            }
            if (flights.penerbangan)
            {
                cout << "Penerbangan Domestik yang dituju tidak ada. Coba lagi." << endl;
            }
        } while (flights.penerbangan); // Akhir dari perulangan

        cout << "\nMaskapai Pesawat yang tersedia :\n";// untuk memilih maskapi
        tampilkanArray(maskapai_pesawat, 5);// untuk menampilkan pilihan tujuan yang diambil dari array maskapai_pesawat
        do// perulangan untuk memastikan apakah maskapai yang dipilih ada, apabila tidak ada ulang lagi sampai benar
        {
            flights.penerbangan = true; // Tetapkan ke true di awal setiap iterasi loop
            cout << "Masukan Maskapai yang Anda inginkan (Gunakan Huruf KAPITAL) : ";
            cin >> flights.maskapai;

            for (int i = 0; i < 5; ++i) // Mengecek apakah nilai maskapai berada dalam array maskapai
            {
                if (flights.maskapai == maskapai_pesawat[i])
                {
                    flights.penerbangan = false;
                    break;
                }
            }
            if (flights.penerbangan)
            {
                cout << "Maskapai yang dipilih tidak ada. Coba lagi." << endl;
            }
        } while (flights.penerbangan); // Akhir dari perulangan
        do// perulangan utnuk memasukkan data serta memastikan apakah data yang diisi sudah benar
        {
            cout << "\n------------------------------------------------------------------" << endl;
            cout << "Masukkan Nama anda: ";
            cin >> nama;
            cout << "Masukaan No. Identitas anda: ";
            cin >> no;
            cout << "Masukkan Jumlah tiket yang anda diinginkan: ";
            cin >> var.jumlah;

            // kondisi untuk menampilkan harga tiket serta gate pesawat
            if (flights.domestik == penerbangan_domestik[0])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 5" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[1])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 4" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[2])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 3" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[3])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 2" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[4])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 1" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[5])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 4" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[6])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 3" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[7])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 2" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[8])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 1" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.domestik == penerbangan_domestik[9])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.domestik << " Rp. " << var.harga << endl;
                cout << "No. Gate = 5" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            cout << "\nApakah Data yang Dimasukkan Sudah Benar? (Y / N): ";
            cin >> var.pilihan;

            // kondisi untuk memastikan apakah data yang dimasukkan sudah benar atau belum
        } while (var.pilihan != 'Y' && var.pilihan != 'y');

        // fungsi yang menampilkan resi pembayaran dari informasi pembayaran
        informasiPembayaran(nama, no, flights.domestik, "", true, flights.maskapai, var.jumlah, var.harga);

        // untuk menampilkan tiket yang dibeli
        tampilkanTiket();

        break;

    // pilihan kedua oenerbangan internasional
    case 2:
        cout << "\nANDA MEMILIH PENERBANGAN INTERNASIONAL" << endl;
        // Menampilkan jadwal penerbangan
        // cout << "\nJadwal Penerbangan Internasional:\n"
        //      << endl;
        // for (int i = 0; i < sizeof(jadwalInternasional) / sizeof(jadwalInternasional[0]); ++i)
        // {
        //     cout << jadwalInternasional[i].tujuan << " - Waktu: " << jadwalInternasional[i].waktu << endl;
        // }
        cout << "\nTujuan Penerbangan Internasional :\n";
        tampilkanArray(penerbangan_internasional, 10);
        do
        {
            flights.penerbangan = true; // Tetapkan ke true di awal setiap iterasi loop
            cout << "Masukan Penerbangan Internasional yang dituju(Gunakan Huruf KAPITAL): ";
            cin >> flights.internasional;

            for (int i = 0; i < 10; ++i) // Mengecek apakah nilai internasional berada dalam array penerbangan_internasional
            {
                if (flights.internasional == penerbangan_internasional[i])
                {
                    flights.penerbangan = false;
                    break;
                }
            }
            if (flights.penerbangan)
            {
                cout << "Penerbangan Internasional yang dituju tidak ada. Coba lagi." << endl;
            }
        } while (flights.penerbangan); // Akhir dari perulangan

        // untuk memilih maskapai yang diinginkan
        cout << "\nMaskapai Pesawat yang tersedia :\n";
        // untuk menampilkan array yang diambil dari maskapai_pesawat
        tampilkanArray(maskapai_pesawat, 5);
        // perulangan untuk meminta customer memasukkan maskappai yang diinginkan dan mengecek apakah maskapai yang dipilih ada apabila tidak akan diulang samapai memesukkan yang benar
        do
        {
            flights.penerbangan = true; // Tetapkan ke true di awal setiap iterasi loop
            // meminta customer untuk memilih maskapi yang diinginkan
            cout << "Masukan Maskapai yang Anda inginkan(Gunakan Huruf KAPITAL): ";
            cin >> flights.maskapai;

            for (int i = 0; i < 5; ++i) // Mengecek apakah nilai maskapai berada dalam array maskapai
            {
                if (flights.maskapai == maskapai_pesawat[i])
                {
                    flights.penerbangan = false;
                    break;
                }
            }
            if (flights.penerbangan)
            {
                cout << "Maskapai yang dipilih tidak ada. Coba lagi." << endl;
            }
        } while (flights.penerbangan); // Akhir dari perulangan

        // perulangan untuk memasukkan data serta memastikan apakah data yg dimasukkan sudah benar atau belum
        do
        {
            cout << "\n------------------------------------------------------------------" << endl;
            cout << "Masukkan Nama anda: ";
            cin >> nama;
            cout << "Masukaan No. Identitas anda: ";
            cin >> no;
            cout << "Masukkan Jumlah tiket yang anda diinginkan: ";
            cin >> var.jumlah; // variabel jumlah yang bernama var dari struct siswa
            // kondisi untuk menampilkan harga tiket serta no gate pesawat
            if (flights.internasional == penerbangan_internasional[0])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 6" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[1])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 9" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[2])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 9" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[3])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 7" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[4])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 8" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[5])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 7" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[6])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 9" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[7])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 7" << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[8])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 6" << endl;
            }
            else if (flights.internasional == penerbangan_internasional[9])
            {
                var.harga = hargaTiket(flights.domestik, flights.internasional); // variable var.harga digunakan untuk menyimpan fungsi harga tiket

                // Display the ticket price based on the calculated harga
                cout << "Harga Tiket Penerbangan ke " << flights.internasional << " Rp. " << var.harga << endl;
                cout << "No. Gate = 8" << endl;
            }
            // untuk menanyakan apakah data sudah benar atau belum
            cout << "\nApakah Data yang Dimasukkan Sudah Benar? (Y / N): ";
            cin >> var.pilihan;
        } while (var.pilihan != 'Y' && var.pilihan != 'y');

        // untuk menampilkan resi pembayaran dari fungsi info pembayaran
        informasiPembayaran(nama, no, "", flights.internasional, false, flights.maskapai, var.jumlah, var.harga);

        // untuk menampilkan tiket yang dibeli
        tampilkanTiket();
        break;

    // pilihan ketiga keluar
    case 3:
        cout << "===== Terimakasih telah menggunakan TIKET.IO!!! =====" << endl;
        cout << "================ Sampai Jumpa Lagi... ===============" << endl;
        break;
    default:
        cout << "Pilihan Tidak Ada. Harap Coba Lagi!!" << endl;
        break;
    }
    return 0;
}
