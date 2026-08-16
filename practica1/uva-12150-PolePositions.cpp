/**
 * https://onlinejudge.org/external/121/12150.pdf
 * 
 * Hay n autos, cada uno con identificador c (unicos) y posiciones ganadas/perdidas p
 * posicion de cada auto viene en el input
 * 
 * Objetivo: reconstruir grilla inicial
 * Si se puede reconstruir, imprimir numeros de autos en posicion original
 * Si no se puede imprimir -1
 * n = 2..10^3
 * p = -10^6 .. 10^6
 * 
 * INPUT:
 * varios casos en el input, c/u termina con n=0
 * primer linea N
 * N lineas con C y P (termina con N=0)
 * OUTPUT: imprimiruna linea con los numeros de los autos en orden o -1
 */


#include <iostream>
#include <vector>


using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long n;

    while(cin>>n){

        if (n==0) break;

        vector<int> positions(n, -1); // al agregar si tiene algo menor a 0
        long c, p;
        bool ok = true;

        for(int i=0; i<n; i++){
            cin >> c >> p;  
            int pos = i + p; // es suma y no resta, porque es posicional, - es avanzar. 

            if(!ok) continue;

            if(pos < 0 || pos >=n || positions.at(pos)>-1) ok = false;
            else positions[pos] = c;
        }

        if (ok) {
            for(int i = 0; i < n; i++) {
                cout << positions[i];
                 if(i != n-1) cout << " ";
            }
        }
        else cout << -1;

        cout << "\n";
    }

    return 0;
}