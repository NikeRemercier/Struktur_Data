#include <iostream>
using namespace std;

const int SIZE_MATRIX = 100; //menentukan batas maksimum ukuran array 2D dalam program

int main() {
    int n;
    cout << "Masukkan ukuran MATRIX (n x n): ";
    cin >> n;
    if(n <= 0 || n > SIZE_MATRIX) {
        cout << "Ukuran harus lebih besar dari 0 dan tidak lebih dari " << SIZE_MATRIX << endl;
    }

    int Matrix[SIZE_MATRIX][SIZE_MATRIX]; // untuk menentukan perkalian matrix

    // Isi array 2D dengan angka
    int count = 1;  //dimulai dari 1 dan diinkremen setiap kali sebuah elemen array diisi. 
                    //jika n adalah 3, maka array akan diisi dengan nilai 1, 2, 3, ..., 9 secara berurutan. 
                    //Ini memastikan bahwa array 2D akan memiliki angka yang berurutan dari kiri ke kanan, dari atas ke bawah, sesuai dengan indeks baris dan kolomnya.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Matrix[i][j] = count;
            count++;
        }
    }

    cout << "Array 2D sebelum rotasi:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Rotasi array 2D
    // Transpose matrix
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(Matrix[i][j], Matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while(right < left) {
            swap(Matrix[i][left], Matrix[i][right]);
            left++;
            right--;
        }
    }

    cout << "\nArray 2D setelah rotasi 90 derajat searah jarum jam:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
