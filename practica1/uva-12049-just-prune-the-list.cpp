/**
 * 
 * dos listas de integers, se pueden eliminar numeros de cualquiera
 * desordenados inicialmente
 * 
 * minimo numero de eliminaciones para obtener mismas listas
 * 
 * INPUT:
 * primer linea T<=100 casos de uso
 * N 1..10000 numero de elemento en primer lista
 * M 1..10000 elemento en segunda lista
 * n lineas elementos primer lista
 * m lineas con elementos segunda lista
 * 
 * OUTPUT:
 * num de elementos a remover x T
 * 
 * IDEA:
 * idea 1: agregar a un map y contar el numero de veces para cada lista
 *          luego recorrer y acumular las diferencias
 *          TARDA MUCHO, incluso sacando el calculo al agregar segunda lista
 * COn unordered_map tampoco
 * MAP NO SE PUEDE, TARDA
 * 
 * idea 2 agregar a multiset ordenado.
 *          recorrer ambas a la vez comparando elementos posicionales
 *          si no coincidem, sumar uno a respuesta y mover iterador
 *          LA ITERACION ES MUY COMPLEJA
 * 
 * idea 3. Interseccion, y resultado es N-interseccion  +   M-interseccion
 * 
 * 
 */


#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>



using namespace std;
using tint = long long;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint T;
    cin>>T;

    while(T--){

        //cout<< "CASO: "<<T<<"\n";
        tint N, M;
        cin >> N >> M;
    
        multiset<tint> ns; //ordenados, mas facil
        multiset<tint> ms;

        tint a;
        for(tint i=0; i<N; i++){
            cin >> a;
            //cout<<"llega n: "<< a <<"\n";
            ns.insert(a);
        }

        tint b;
        for(tint i=0; i<M; i++){
            cin >> b;
            ms.insert(b);
        }

        tint res = 0;

        multiset<tint> intersection;
        set_intersection(ns.begin(), ns.end(),ms.begin(), ms.end(), inserter(intersection, intersection.begin()));


        res = N+M - (intersection.size()*2);

        cout << res << "\n";
    }
}