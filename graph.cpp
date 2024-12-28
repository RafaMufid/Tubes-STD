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
