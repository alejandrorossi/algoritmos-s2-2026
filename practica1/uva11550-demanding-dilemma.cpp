/**
 * 
 * grafo simple no dirigido es
 * G=(V,E) 
 * V es set de vertices no vacio
 * E es unordered set de pair(u,v) 
 * u,v ⊆ V y u!=v
 * 
 * Con ayuda buscando enunciado:
 * Hay n vértices.
    Hay m aristas.
    La matriz tiene tamaño n × m.
    Cada fila representa un vértice.
    Cada columna representa una arista.
    M(i,j) = 1 significa que la arista j es incidente al vértice i.
    M(i,j) = 0 significa que no lo es.
 *

 INPUT: t 1..41. que son test cases
 *  n m  con n 1..8 y m 0.. n(n-1)/2
 *  n lineas de m numeros enteros (0|1)
 *  
 * OUTPUT: 
 * YES si es que la matriz puede ser de incidencia de algun grafo no dirigido
 * NO si no puede
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <queue> 
#include <stack> 
#include <unordered_set> 



using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   // m puede ser el número de combinaciones posibles al 
   // seleccionar dos elementos de un grupo de n elementos.

   tint t; cin >>t;

   while(t--){
        tint n,m;
        cin >>n>>m;

        unordered_set<pair<tint,tint>> E;

        for(tint i=0; i<n; i++){
            for(tint j=0; j<m; j++){
                tint x; cin >>x;

                // guardar vertice con arista?
                // o sea crear grafo
            }
        }

        // no entiendo logica central

   }
    return 0;
}