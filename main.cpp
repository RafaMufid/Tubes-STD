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

    int i = 0;
    while(i < 8){
        cout << "Masukkan ID Simpul: ";
        cin >> inputVertexID;
        if(searchVertexID(G, inputVertexID) != NULL){
            cout << "Masukkan Tujuan dan Bobot: ";
            cin >> tujuan;
            cin >> bobot;
            addEdge(G, inputVertexID, tujuan, bobot);
        }
        i++;
    }

    showGraph(G);
    cout << "On Progress..." << endl;
    return 0;
}
