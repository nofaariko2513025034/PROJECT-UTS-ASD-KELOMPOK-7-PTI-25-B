#include <iostream>
#include <iomanip>
// Daftar barang sederhana (hardcoded)
const int JUMLAH_BARANG = 5;
const char* NAMA_BARANG[JUMLAH_BARANG] = {"Buku Tulis", "Pensil", "Pulpen", "Buku Gambar", "Eraser"};
const int HARGA_BARANG[JUMLAH_BARANG] = {5000, 2000, 3000, 8000, 1000};
// Fungsi tampilkan daftar barang
void tampilkanDaftarBarang() {
    std::cout << "\n=== DAFTAR BARANG ===" << std::endl;
    std::cout << std::left << std::setw(3) << "No" 
              << std::setw(15) << "Nama Barang" 
              << std::setw(10) << "Harga (Rp)" << std::endl;
    for (int i = 0; i < JUMLAH_BARANG; ++i) {
        std::cout << std::left << std::setw(3) << (i + 1)
                  << std::setw(15) << NAMA_BARANG[i]
                  << std::setw(10) << HARGA_BARANG[i] << std::endl;
    }
    std::cout << "===================\n";
}
// Fungsi proses transaksi (satu barang saja)
void prosesTransaksi() {

    tampilkanDaftarBarang();
    const int MAKS_BARANG = 20;
    int daftarBarang[MAKS_BARANG];
    int daftarJumlah[MAKS_BARANG];
    int banyakBarang = 0;
    int total = 0;
    while (true) {
        int noBarang, jumlah;
        std::cout << "Masukkan nomor barang (1-5, 0 untuk selesai): ";
        std::cin >> noBarang;
        if (noBarang == 0) break;
        if (noBarang < 1 || noBarang > 5) {
            std::cout << "Nomor tidak valid! Gunakan 1-5 atau 0 untuk selesai.\n";
            continue;
        }
        std::cout << "Masukkan jumlah barang: ";
        std::cin >> jumlah;
        if (jumlah <= 0) {
            std::cout << "Jumlah harus lebih dari 0!\n";
            continue;
        }
        daftarBarang[banyakBarang] = noBarang - 1;
        daftarJumlah[banyakBarang] = jumlah;
        total += HARGA_BARANG[noBarang - 1] * jumlah;
        banyakBarang++;
        if (banyakBarang >= MAKS_BARANG) {
            std::cout << "Maksimal barang tercapai!\n";
            break;
        }
    }
    if (banyakBarang == 0) {
        std::cout << "Tidak ada barang yang dibeli.\n";
        return;
    }
    std::cout << "\nTotal harga semua barang: Rp " << total << std::endl;
    int uangBayar;
    std::cout << "Masukkan uang pembayaran (Rp): ";
    std::cin >> uangBayar;
    int kembalian = 0;
    if (uangBayar < total) {
        std::cout << "Uang kurang! Minimal Rp " << total << ".\n";
    } else if (uangBayar > total) {
        kembalian = uangBayar - total;
        std::cout << "Kembalian: Rp " << kembalian << std::endl;
    } else {
        std::cout << "Pembayaran pas!\n";
    }
    // Tampilkan ringkasan semua barang
    std::cout << "\n=== RINGKASAN TRANSAKSI ===" << std::endl;
    std::cout << std::left << std::setw(15) << "Nama Barang" << std::setw(8) << "Jumlah" << std::setw(12) << "Subtotal" << std::endl;
    for (int i = 0; i < banyakBarang; ++i) {
        int idx = daftarBarang[i];
        int subtotal = HARGA_BARANG[idx] * daftarJumlah[i];
        std::cout << std::left << std::setw(15) << NAMA_BARANG[idx] << std::setw(8) << daftarJumlah[i] << std::setw(12) << subtotal << std::endl;
    }
    std::cout << "Total Harga: Rp " << total << std::endl;
    std::cout << "Uang Dibayar: Rp " << uangBayar << std::endl;
    std::cout << "Kembalian: Rp " << kembalian << std::endl;
    std::cout << "==========================\n";
    std::cout << "Transaksi selesai! Terima kasih.\n";
}
int main() {
    int pilihan;
    do {
        std::cout << "\n=== KASIR MINI SEDERHANA ===" << std::endl;
        std::cout << "1. Mulai Transaksi" << std::endl;
        std::cout << "0. Keluar" << std::endl;
        std::cout << "Pilih (0-1): ";
        std::cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                prosesTransaksi();
                std::cout << "Tekan Enter untuk kembali ke menu...";
                std::cin.ignore();
                std::cin.get();  // Pause
                break;
            case 0:
                std::cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);  // Perulangan do-while untuk menu
    
    return 0;
}