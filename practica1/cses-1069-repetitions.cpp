/**
 * https://cses.fi/problemset/task/1069
 * 
 * dado un string con A C G y T
 * determinar la repeticion mas larga en la sequencia
 * 
 * encontrar la secuencia del mismo caracter mas larga
 * 
 * n es 10^6, menos de 10^8 en On tarda menos de un segundo
 * 
 */

 #include <iostream>
#include <vector>

using namespace std;
using tint = long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int i = 1;
    int maxx = 1;
    int partial = 1;
    long len = s.length();


    if(len == 1) { 
        cout << maxx<< "\n";
        return 0;
    }

    char previous = s.at(0);

    while(i<len) {

        if(previous == s.at(i)){
            partial++;
        }else{
            maxx = max(partial, maxx);
            partial = 1;
        }
    
       previous = s.at(i); 
       i++;  
    }
    cout << max(partial, maxx)<< "\n";
    return 0;

}