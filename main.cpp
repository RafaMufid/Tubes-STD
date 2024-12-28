#include <iostream>
#include "graph.h"

using namespace std;

void menu() {
    cout << "==============================\n";
    cout << "           MENU\n";
    cout << "==============================\n";
    cout << "1. Buat Graph\n";
    cout << "2. Tambah Jalur\n";
    cout << "3. Tampilkan Graph\n";
    cout << "4. Cari Jalur Terpendek\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

int main()
{
    graph G;
    bool isRunning = true;
    int choice;

    while (isRunning) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: {
                buildGraph(G);
                break;
            }
            case 2: {
                char inputVertexID, tujuan, inputBanjir;
                int bobot;

                cout << "Masukkan ID Simpul: ";
                cin >> inputVertexID;
                if (searchVertexID(G, inputVertexID) != NULL) {
                    cout << "Masukkan Tujuan dan Bobot: ";
                    cin >> tujuan;
                    cin >> bobot;
                    cout << "Apakah jalur ini banjir? (Y/N): ";
                    cin >> inputBanjir;
                    addEdge(G, inputVertexID, tujuan, bobot, toupper(inputBanjir) == 'Y');
                } else {
                    cout << "Simpul tidak ditemukan. Tambahkan simpul terlebih dahulu.\n";
                }
                break;
            }
            case 3: {
                showGraph(G);
                break;
            }
            case 4: {
                char start, end;
                cout << "Masukkan simpul awal: ";
                cin >> start;
                cout << "Masukkan simpul tujuan: ";
                cin >> end;
                findShortestPath(G, toupper(start), toupper(end));
                break;
            }
            case 5: {
                isRunning = false;
                cout << "Keluar dari program.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
            }
        }
    }

    return 0;
}
