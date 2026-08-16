/**
 * 
 * dos sets, desordenados, sin repetir
 * 
 * cds, quieren vender los que estén repetidos
 * 
 * INPUT: varios test cases
 * cada uno:
 * n m  que van de 1.. 1millon
 * n lineas con numeros, id de cada cd, ascendente
 * 
 * cada id va de 1 a 1billon
 * 
 * 0 0 termina programa
 * 
 * OUTPUT:
 * un integer, los elementos que tienen ambos.
 * 
 * 
 * encontrar la interseccion entre dos conjujntos
 * 
 * 
 */


#include <iostream>
#include <set>
#include <algorithm>


using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint n, m;
    while(cin >> n >> m){

        if(n == 0 && m== 0) return 0;

        set<tint> a;
        set<tint> b;

        for(tint i=0; i<n; i++){
            tint cd;
            cin >> cd;
            a.insert(cd);
        }

        for(tint i=0; i<m; i++){
            tint cd;
            cin >> cd;
            b.insert(cd);
        }


        //esta es una forma de usar la libreria, sale ya hecho
        set<tint> intersection;
      //  set_intersection(a.begin(), a.end(),b.begin(), b.end(), inserter(intersection, intersection.begin()));

      //de manera manual es:

        if(b.size()> a.size()) swap(a,b);

        for(auto elem:a){
            if (b.count(elem)){ // true si existe
                intersection.insert(elem);
            } 
        }

       // for(auto x:intersection){ // esto es para imprimir cada cd
         //   cout<< x;

           // if(x != *intersection.rbegin()){ principio desde la derecha
             //   cout << " ";
           // }
       // }
        cout << intersection.size() <<"\n";
    }

   return 0;
}