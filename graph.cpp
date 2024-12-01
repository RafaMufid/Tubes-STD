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
            cout << " -> " << destVertexID(e) << "(" << weight(e) << ")";
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

void addEdge(graph &G, char vertexId, char destVertexId, int weight){
    adrVertex v = searchVertexID(G, vertexId);
    if(v == NULL){
        cout << "Vertex Tidak Ditemukan..." << endl;
    }else{
        adrEdge e = new edge;
        destVertexID(e) = destVertexId;
        weight(e) = weight;
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

