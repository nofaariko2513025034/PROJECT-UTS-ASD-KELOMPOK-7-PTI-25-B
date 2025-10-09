#include <iostream>
#include <string>  // Untuk string sederhana (opsional, bisa diganti cout)
// Daftar barang sederhana (hardcoded)
const int JUMLAH_BARANG = 5;
const char* NAMA_BARANG[JUMLAH_BARANG] = {"Buku Tulis", "Pensil", "Pulpen", "Buku Gambar", "Eraser"};
const int HARGA_BARANG[JUMLAH_BARANG] = {5000, 2000, 3000, 8000, 1000};
// Konstanta untuk keranjang (maksimal 10 item)
const int MAX_ITEM = 10;
// Fungsi tampilkan daftar barang (sederhana)
void tampilkanDaftarBarang() {
    std::cout << "\n=== DAFTAR BARANG ===\n";
    std::cout << "No  Nama Barang     Harga (Rp)\n";
    std::cout << "--------------------\n";
    for (int i = 0; i < JUMLAH_BARANG; ++i) {
        std::cout << (i + 1) << "   " << NAMA_BARANG[i] << "     " << HARGA_BARANG[i] << "\n";
    }
    std::cout << "===================\n";
}
// Fungsi proses transaksi (lebih dari 1 barang, sederhana)
void prosesTransaksi() {
    tampilkanDaftarBarang();
    
    // Array untuk keranjang
    int index_barang[MAX_ITEM];
    int jumlah_item[MAX_ITEM];
    int jumlah_item_dipilih = 0;
    
    // Inisialisasi keranjang
    for (int i = 0; i < MAX_ITEM; ++i) {
        index_barang[i] = -1;
        jumlah_item[i] = 0;
    }
    
    // Loop tambah barang
    while (true) {
        int noBarang;
        std::cout << "Masukkan nomor barang (1-5, atau 0 untuk selesai): ";
        std::cin >> noBarang;
        
        if (noBarang == 0) {
            break;
        }
        
        if (noBarang < 1 || noBarang > 5) {
            std::cout << "Nomor tidak valid! Gunakan 1-5 atau 0.\n";
            continue;
        }
        
        int jumlah;
        std::cout << "Masukkan jumlah barang: ";
        std::cin >> jumlah;
        if (jumlah <= 0) {
            std::cout << "Jumlah harus lebih dari 0!\n";
            continue;
        }
        
        // Tambah ke keranjang jika belum penuh
        if (jumlah_item_dipilih < MAX_ITEM) {
            index_barang[jumlah_item_dipilih] = noBarang - 1;
            jumlah_item[jumlah_item_dipilih] = jumlah;
            jumlah_item_dipilih++;
            std::cout << "Barang ditambahkan.\n";
        } else {
            std::cout << "Keranjang penuh!\n";
        }
    }
    
    // Cek jika kosong
    if (jumlah_item_dipilih == 0) {
        std::cout << "Tidak ada barang. Transaksi dibatalkan.\n";
        return;
    }
    
    // Hitung total
    int total = 0;
    for (int i = 0; i < jumlah_item_dipilih; ++i) {
        total += HARGA_BARANG[index_barang[i]] * jumlah_item[i];
    }
    
    std::cout << "\nTotal harga: Rp " << total << "\n";
    
    // Pembayaran
    int uangBayar;
    std::cout << "Masukkan uang pembayaran (Rp): ";
    std::cin >> uangBayar;
    
    int kembalian = 0;
    if (uangBayar < total) {
        std::cout << "Uang kurang! Minimal Rp " << total << ".\n";
        return;
    } else if (uangBayar > total) {
        kembalian = uangBayar - total;
        std::cout << "Kembalian: Rp " << kembalian << "\n";
    } else {
        std::cout << "Pembayaran pas!\n";
    }
    
    // Ringkasan sederhana
    std::cout << "\n=== RINGKASAN TRANSAKSI ===\n";
    for (int i = 0; i < jumlah_item_dipilih; ++i) {
        int subtotal = HARGA_BARANG[index_barang[i]] * jumlah_item[i];
        std::cout << NAMA_BARANG[index_barang[i]] << " x" << jumlah_item[i] 
                  << " = Rp " << subtotal << "\n";
    }
    std::cout << "--------------------\n";
    std::cout << "Total Harga: Rp " << total << "\n";
    std::cout << "Uang Dibayar: Rp " << uangBayar << "\n";
    std::cout << "Kembalian: Rp " << kembalian << "\n";
    std::cout << "==========================\n";
    
    std::cout << "Transaksi selesai! Terima kasih.\n";
}
int main() {
    int pilihan;
    do {
        std::cout << "\n=== KASIR MINI SEDERHANA ===\n";
        std::cout << "1. Mulai Transaksi\n";
        std::cout << "0. Keluar\n";
        std::cout << "Pilih (0-1): ";
        std::cin >> pilihan;
        
        if (pilihan == 1) {
            prosesTransaksi();
        } else if (pilihan == 0) {
            std::cout << "Terima kasih! Program selesai.\n";
        } else {
            std::cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
    
    return 0;
}