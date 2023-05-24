// Naufal Farros_122130055_Teknik Elektro
// M. Raihan Fikri_122130053_Teknik Elektro
// Asslam Abid_122130052_Teknik Elektro

#include <iostream>
using namespace std;

int main() {
  const int MAX_COMPONENTS = 10;
  string components[MAX_COMPONENTS];
  float values[MAX_COMPONENTS];
  int componentCount;
  float totalResistance = 0.0;
  float totalCurrent = 0.0;
  float totalVoltage = 0.0;

  // Meminta pengguna memasukkan jumlah komponen dalam rangkaian
  cout << "Masukkan jumlah komponen dalam rangkaian: ";
  cin >> componentCount;

  // Memasukkan nama dan nilai-nilai komponen
  for (int i = 0; i < componentCount; i++) {
    cout << "Masukkan nama komponen ke-" << i + 1 << ": ";
    cin >> components[i];

    cout << "Masukkan nilai komponen ke-" << i + 1 << ": ";
    cin >> values[i];
  }

  // Menampilkan data komponen
  cout << "\nData Komponen:\n";
  for (int i = 0; i < componentCount; i++) {
    cout << "Komponen ke-" << i + 1 << ": " << components[i]
         << ", Nilai: " << values[i] << endl;
  }

  // Menghitung total hambatan dan total arus
  for (int i = 0; i < componentCount; i++) {
    totalResistance += values[i];
    if (components[i] != "Sumber") {
      totalCurrent += 1 / values[i]; // Menggunakan konsep hukum Ohm
    }
  }
  totalCurrent = 1 / totalCurrent;

  // Memeriksa apakah ada komponen "Sumber" dan meminta nilai arus sumber jika
  // ada
  for (int i = 0; i < componentCount; i++) {
    if (components[i] == "Sumber") {
      cout << "Masukkan nilai arus sumber: ";
      cin >> totalCurrent;
      break;
    }
  }

  // Menghitung total tegangan
  for (int i = 0; i < componentCount; i++) {
    if (components[i] != "Sumber") {
      totalVoltage += totalCurrent * values[i];
    }
  }

  // Menampilkan hasil perhitungan
  cout << "\nHasil Perhitungan:\n";
  cout << "Total Hambatan: " << totalResistance << endl;
  cout << "Total Arus: " << totalCurrent << endl;
  cout << "Total Tegangan: " << totalVoltage << endl;

  return 0;
}
