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
 * IDEA:
 * se agrega todo en un set, 
 * al leer segunda lista, cuenta repetidos
 * 
 * se usa unordered_set que tiene .count() en O(1)
 * 
 */


#include <iostream>
#include <unordered_set>



using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint n, m;
    while(cin >> n >> m){

        if(n == 0 && m== 0) return 0;

        unordered_set<tint> a;

        for(tint i=0; i<n; i++){
            tint cd;
            cin >> cd;
            a.insert(cd);
        }

        tint res= 0;

        for(tint i=0; i<m; i++){
            tint cd;
            cin >> cd;
            if(a.count(cd)) res++;
        }

        cout << res <<"\n";
    }

   return 0;
}