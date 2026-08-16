/**
 *  secuencia de n> 0 integers es un jolly jumper si los valores absolutos entre
 * elementos sucesivos toman todos los valores entre 1 y n-1
 * 
 * n <= 3000 y n integers representando la sequencia
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using tint = long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint n;
    tint prev;
    tint next;

    while(cin >> n) {
        vector<bool> v(n-1, false); //desde 0...

        if (n < 1) {
            cout << "Jolly" << "\n";
            continue;
        }

        cin >> prev;
        bool ok = true;

        for (int i = 1; i < n and ok; i++) {
            
            cin >> next;

            int res = abs(prev - next); 

            if ( res>n-1 || res <1 || v[res-1]) {
                ok = false;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //descarta hasta llegar a salto
                continue;
            }

            v[res-1] = true;
           
            prev = next;
        }

        if (ok) cout << "Jolly"<<"\n";
        else cout << "Not jolly" << "\n";
    }

}