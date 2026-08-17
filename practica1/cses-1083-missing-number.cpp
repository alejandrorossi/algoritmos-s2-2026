/**
 * 
 * tenemos numeros de 1..n
 * falta uno
 * 
 * INPUT:
 * n va de 2 a 2.10^5
 * segunda linea tiene n-1 numeros de 1..n
 * 
 */


#include <iostream>
#include <vector>
#include <set>


using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    tint n;
    cin >> n;

    tint a;
    set<tint> numbers;

    while(cin >> a){
        numbers.insert(a);
    }

    for(tint i=1; i<=n; i++){
        if(!numbers.count(i)){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}