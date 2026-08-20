/**
 * lemmings verdes vs azules
 * 
 * batalla en rondas, y campos de batalla
 * por cada ronda:
 * cada bando elije lemming mas fuerte
 * sobrevive el de mas poder-el de menos poder. Mismo poder, mueren
 * sobreviviente vuelve al ejercito
 * 
 * si hay menos lem que campos de pelea, tantas batallas como la menor cantidad de lemmings
 * 
 * guerra termina con uno sin lemmings o ambos mismo tiempo
 * 
 * INPUT: N casos 1..100
 * B SG SB. Campos de batalla, lemVerdes, lemAzules. 1..100.000
 * sg lineas con poder de los green lemmings 1..100
 * sb lineas con poder de los blue lemmings 1..100
 * 
 * OUTPUT:
 * segun quien gane:
 * green and blue died
 * green win y una linea con los sobrevivientes en descendiente
 * blue win sobrevivientes descendiente
 * linea blanca entre casos de uso
 * 
 * IDEA: 
 * 
 */


#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 
#include <set> 



using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //priority queue, 01 para maximo y log n borrar e insertar
    priority_queue<int> pq;

    tint N; cin>>N;

    while(N--){

        tint b, sg, sb;
        cin >> b >> sg >> sb;

        priority_queue<int> gs, bs;

        for(tint i=0;i<sg;i++){
            tint lem; cin>>lem;
            gs.push(lem);
        }
    
        for(tint i=0;i<sb;i++){
            tint lem; cin>>lem;
            bs.push(lem);
        }

        //batalla
        while(!gs.empty() and !bs.empty()){

            vector<tint> round_B; 
            vector<tint> round_G;

            tint fights = min({b, static_cast<tint>(gs.size()), static_cast<tint>(bs.size())});

            //ronda
            for(tint i=0; i<fights; i++){

                tint gL = gs.top();
                tint bL = bs.top();

                gs.pop();
                bs.pop();

                // guardar pa pushear despues
                if(gL>bL) round_G.push_back(gL-bL);
                else if (bL>gL) round_B.push_back(bL-gL);

                // si son iguales, ya quedaron popeados
            }

            //terminaron las batallas, reinsertar heridos
            for(auto lemming: round_B) bs.push(lemming);
            for(auto lemming: round_G) gs.push(lemming);
            round_B.clear();
            round_G.clear();
        }

        if(gs.empty() && bs.empty()) cout<< "green and blue died"<< endl;
        else if(gs.empty()){
            cout<< "blue wins"<< endl;
            size_t size = bs.size();
            for(size_t i=0; i<size; i++){
                cout << bs.top() << endl;
                bs.pop();
                if(i!= size-1) cout <<endl;
            }
        } else if(bs.empty()){
            cout<< "green wins"<< endl;
            size_t size = gs.size();
            for(size_t i=0; i<size; i++){
                cout << gs.top();
                gs.pop();
                if(i!= size-1) cout <<endl;
            }
        } 
        cout<<endl;

        
        
    }
    
    return 0;
}