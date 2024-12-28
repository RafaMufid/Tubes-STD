#include <iostream>
#include "graph.h"


void createVertex(char newVertexID, adrVertex &v){
    v = new vertex;
    idVertex(v) = newVertexID;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

void initGraph(graph &G){
    firstVertex(G) = NULL;
}

void addVertex(graph &G, char newVertexID){
    adrVertex v;
    createVertex(newVertexID, v);
    if(firstVertex(G) == NULL){
        firstVertex(G) = v;
    }else{
        adrVertex v2 = firstVertex(G);
        while(nextVertex(v2) != NULL){
            v2 = nextVertex(v2);
        }
        nextVertex(v2) = v;
    }
}

void buildGraph(graph &G){
    initGraph(G);
    char newVertexID;
    cout << "Masukkan ID Vertex (huruf A-Z)" << endl;
    cin >> newVertexID;
    while ((newVertexID >= 'A' && newVertexID <= 'Z')||(newVertexID >= 'a'&&newVertexID <= 'z')) {
        newVertexID = toupper(newVertexID);
        addVertex(G, newVertexID);
        cin >> newVertexID;
    }
    cout << "Graph berhasil dibuat." << endl;
}

void showGraph(graph G){
    cout << "Graph:" << endl;
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        cout << "Vertex: " << idVertex(v);
        adrEdge e = firstEdge(v);
        while(e != NULL){
            if(!isBanjir(e)){
                cout << " -> " << destVertexID(e) << "(" << weight(e) << ")";
            }else{
                cout << " -> " << destVertexID(e) << "(" << weight(e) << ") '*Banjir*'";
            }
            e = nextEdge(e);
        }
        cout << endl;
        v = nextVertex(v);
    }
}

adrVertex searchVertexID(graph &G, char vertexID){
    adrVertex v = firstVertex(G);
    while(v != NULL){
        if(vertexID == idVertex(v)){
            return v;
        }
        v = nextVertex(v);
    }
    return NULL;
}

void addEdge(graph &G, char vertexId, char destVertexId, int weight, bool isBanjir){
    adrVertex v = searchVertexID(G, vertexId);
    if(v == NULL){
        cout << "Vertex Tidak Ditemukan..." << endl;
    }else{
        adrEdge e = new edge;
        destVertexID(e) = destVertexId;
        weight(e) = weight;
        isBanjir(e) = isBanjir;
        nextEdge(e) = NULL;
        if(firstEdge(v) == NULL){
            firstEdge(v) = e;
        }else{
            adrEdge e2 = firstEdge(v);
            while(nextEdge(e2) != NULL){
                e2 = nextEdge(e2);
            }
            nextEdge(e2) = e;
        }
    }
}

void setStatusBanjir(graph &G, char vertexId, char destVertexId, bool status){
    adrVertex v = searchVertexID(G, vertexId);
    if(v != NULL){
        adrEdge e = firstEdge(v);
        while(e != NULL){
            if(destVertexID(e) == destVertexId){
                isBanjir(e) = status;
            }
            e = nextEdge(e);
        }
        cout << "Edge dari " << vertexId << " ke " << destVertexId << " tidak ditemukan." << endl;
    }else{
        cout << "Vertex " << vertexId << " tidak ditemukan." << endl;
    }
}

int countVertex(graph &G){
    int jmlVertex = 0;
    adrVertex v = firstVertex(G);
    while(v != NULL){
        jmlVertex++;
        v = nextVertex(v);
    }
    return jmlVertex;
}

void findShortestPath(graph &G, char start, char end) {
    map<char, int> distances; // Menyimpan jarak minimum ke setiap simpul
    map<char, char> predecessors; // Menyimpan jalur sebelumnya
    map<char, bool> visited; // Menyimpan status kunjungan

    // Inisialisasi semua simpul
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        distances[idVertex(v)] = INT_MAX; // Set jarak awal menjadi tak hingga
        predecessors[idVertex(v)] = '\0';
        visited[idVertex(v)] = false;
        v = nextVertex(v);
    }

    // Jarak ke simpul awal adalah 0
    distances[start] = 0;

    for (int i = 0; i < countVertex(G); ++i) {
        // Cari simpul dengan jarak terpendek yang belum dikunjungi
        char currentVertex = '\0';
        int minDistance = INT_MAX;
        for (auto &pair : distances) {
            if (!visited[pair.first] && pair.second < minDistance) {
                minDistance = pair.second;
                currentVertex = pair.first;
            }
        }

        if (currentVertex == '\0') {
            break; // Tidak ada simpul yang dapat dijangkau lagi
        }

        visited[currentVertex] = true;

        // Update jarak ke simpul tetangga
        adrVertex currentV = searchVertexID(G, currentVertex);
        adrEdge e = firstEdge(currentV);
        while (e != NULL) {
            if (!isBanjir(e)) { // Hindari jalur banjir
                int newDistance = distances[currentVertex] + weight(e);
                if (newDistance < distances[destVertexID(e)]) {
                    distances[destVertexID(e)] = newDistance;
                    predecessors[destVertexID(e)] = currentVertex;
                }
            }
            e = nextEdge(e);
        }
    }

    // Cetak hasil jalur terpendek
    if (distances[end] == INT_MAX) {
        cout << "Tidak ada jalur dari " << start << " ke " << end << " yang tidak banjir." << endl;
        return;
    }

    cout << "Jarak terpendek dari " << start << " ke " << end << " adalah: " << distances[end] << endl;
    cout << "Jalur: ";

    // Rekonstruksi jalur
    string path = "";
    for (char at = end; at != '\0'; at = predecessors[at]) {
        path = at + path;
    }

    cout << path << endl;
}
