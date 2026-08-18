/**
 * https://onlinejudge.org/external/119/11995.pdf
 * 
 * hay una estructura tipo bolsa, soporta dos operaciones
 * 1 x que agrega elemento
 * 2 quita un elemento
 * 
 * deducir estructura basada en operaciones dadas con retornos
 * 
 * INPUT:  varios T, cada uno:
 * n 1..1000
 * n lineas con c x   que es comando 1|2 y un integer x
 * 
 * x 1..100
 * termina con end of file
 * 
 * OUTPUT: 
 * stack|queue|priority queue|impossible|not sure|
 * 
 * IDEA: instanciar las 3 estructuras , agregar y evaluar de a una
 *  - si mas de una es true: not sure
 *  - si solo una. imprimir esa
 *  - ninguna: impossible
 * 
 * 
 * NO PASA JUEZ, WRONG AnSWER
 * 
 */


#include <iostream>
#include <vector>
#include <queue> 
#include <stack> 


using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint n;
    while(cin >> n) {
       
        priority_queue<int> pq;
        queue<int> q;
        stack<int> st;
        
        int operation, elem;

        bool isPq = true;
        bool isQ = true;
        bool isSt = true;

        for(int i=0; i<n; i++) {
            cin >> operation >> elem;
            
            if(operation==1) { 
                pq.push(elem); //esto es O log n
                q.push(elem);
                st.push(elem);
            } else { 
                // si no coincide con elem UNA vez, ya no es ese
                // si verifique que no es, me ahorro el .pop
                if(isPq) {
                    if(pq.empty()) isPq=false;
                    else isPq = pq.top()==elem; 
                    if(isPq) pq.pop(); // O log n
                } 
                if(isQ) {
                    if(q.empty())  isQ=false;
                    else isQ = q.front()==elem; 
                    if(isQ)q.pop();
                }
                if(isSt) {
                    if(st.empty())  isSt=false; 
                    else isSt= st.top()==elem; 
                    if(isSt)st.pop();
                }
            }
        }

        // CASOS BASE: 1. ninguno, 2. todos 3. es alguno 4. son varios
        
        if(!isPq && !isQ && !isSt) {cout << "impossible" <<"\n"; continue;};

        if(isPq && isQ && isSt)  {cout << "not sure" <<"\n"; continue;}; //<- me faltaba este

        //otros casos
        if (isPq ^ isQ ^ isSt){
            if(isPq) cout << "priority queue"<<"\n";
            else if(isQ) cout << "queue"<<"\n";
            else if(isSt) cout << "stack"<<"\n";
        }else{
            cout <<"not sure"<<"\n";
        }

    }

    
    return 0;
}