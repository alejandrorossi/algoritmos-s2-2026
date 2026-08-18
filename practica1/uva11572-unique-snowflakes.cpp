/**
 * 
 * secuencia de n copos de nieve, identificados con numeros
 * formar bolsa copos diferentes entre si
 * la bolsa debe contener un segmento consecutivo (toma todos elementos en un tramo)
 * 
 * INPUT: varios casos
 * 
 * n que son los copos de la maquina 0.. 1.000.000
 * n lineas con un x de 0 a 10^9 on id de copo
 *      se repiten ids
 * 
 * OUTPUT: numero con maxima secuencia unica
 * 
 * 
 * Solucion del profe
 */


#include <iostream>
#include <vector>
#include <queue> 
#include <stack> 
#include <set> 



using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint T; cin >> T;
    while(T--) {

        //appearance[i] guarda ultima aparicion del copo i 
        unordered_map<tint, tint> appearance; //buscar, eliminar y agregar O(1)
        tint left = -1, ans = 0;
        
        tint n; cin >> n;
        for(tint i = 0; i < n; ++i) {
            tint s; cin >> s;

            //iteracion avanza para adelante
            //left mueve adelante al encontrar duplicado unicamente
            // se guarda distancia maxima (compara en cada paso)

            //SLIDING WINDOW


            if(auto pos = appearance.find(s); pos != appearance.end()) //repetido
                left = pos->second; //posicion actual

            ans = max(ans, i - left);
            appearance[s] = i; //actualizo ultima posicion
        }
        cout << ans << endl;
    }

    //...
    return 0;
}