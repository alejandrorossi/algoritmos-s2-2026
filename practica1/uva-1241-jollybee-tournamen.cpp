/**
 * 
 * hay 2^n jugadores
 * es un torneo, algunos se retiran sin jugar
 * para cada partido:
    * 2 pueden estar disponibles, juegan y uno avanza
    * uno disponible,es un walkover y pasa
    * ninguno disponible, ninguno pasa
 * 
 * determinar cuantos walkovers hay en el torneo
 * ids de jugadores van de 1 a 2^N, ordenados en posiciones de torneo
 * 
 * torneo es una llave
 * 
 * INPUT:
 * un T caos de uso
 * luego N 1..10 y M 0..2^N
 * M integers con los jugadores que abandonaron
 * OUTPUT: imprimir el numero de walkovers del torneo por caso
 * 
 * 
 * IDEA: esto suena a que se tiene que hacer algo raro con desplazamiento de bits
 */


#include <iostream>
#include <vector>


using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint T;
    cin >> T ;

    while(T--){

        tint n, m, elem;
        cin >> n >> m;

        // desplazamiento de bits = 2^n
        tint players = 1<<n; 

        // 1 caso base es que m = 2^n entonces no hay
        // 2 caso base es que m = 2^n -1 entonces hay n
        if(m == players) {cout<< 0 << "\n"; continue;}
        if(m == players-1) {cout<< n << "\n"; continue;}

       vector<bool> playing(players, true);

        for (tint i=0; i<m; i++){
            cin >> elem;
            playing[elem-1] = false;
        }

        tint w = 0;

        vector<bool> aux(players/2, true);

        //mientras haya jugadores, jugar cada ronda. NextRound = jugadores/2

        while(players>1){
                                    //avanzar por partido de a 2
            for(tint i=0; i<players; i+=2){ 
               if( playing[i] && playing[i+1]) // partido normal 
                    aux[i/2]=true; 
               else if (playing[i] ^ playing[i+1]){ //uno solo juega XOR
                    w++;
                    aux[i/2]=true; 
               } 
               else if (!playing[i] && !playing[i+1]) // ninguno juega
                    aux[i/2]=false; 
            }

            //next round
            swap(aux, playing);
            players = players/2;
            aux.resize(players);

        }

        cout<< w <<"\n";
    
    }
    return 0;
}