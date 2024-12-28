#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    graph G;
    buildGraph(G);

    char inputVertexID;
    char tujuan;
    int bobot;
    char inputBanjir;

    int jumlahVertex = countVertex(G);
    for(int i = 0; i < jumlahVertex; i++){
        cout << "Masukkan ID Simpul: ";
        cin >> inputVertexID;
        if(searchVertexID(G, inputVertexID) != NULL){
            cout << "Masukkan Tujuan dan Bobot: ";
            cin >> tujuan;
            cin >> bobot;
            cout << "Apakah jalur ini banjir? (Y/N): ";
            cin >> inputBanjir;
            addEdge(G, inputVertexID, tujuan, bobot, toupper(inputBanjir) == 'Y');
        }
    }

    showGraph(G);
    return 0;
}
