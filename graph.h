#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#define firstVertex(G) G.firstVertex
#define nextVertex(v) v->nextVertex
#define firstEdge(v) v->firstEdge
#define idVertex(v) v->idVertex
#define isBanjir(e) e->isBanjir
#define destVertexID(e) e->destVertexID
#define weight(e) e->weight
#define nextEdge(e) e->nextEdge

using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex{
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge{
    bool isBanjir;
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct graph{
    adrVertex firstVertex;
};

void createVertex(char newVertexID, adrVertex &v);
void initGraph(graph &G);
void addVertex(graph &G, char newVertexID);
void buildGraph(graph &G);
void showGraph(graph G);
adrVertex searchVertexID(graph &G, char vertexID);
void addEdge(graph &G,char vertexId,char destVertexId, int weight, bool isBanjir);
void setStatusBanjir(graph &G, char vertexId, char destVertexId, bool status);
int countVertex(graph &G);

#endif // GRAPH_H_INCLUDED
