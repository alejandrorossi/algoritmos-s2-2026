/**
 * 
 * hay un texto mal formateado, a veces se presionó Home y a veces End
 * 
 * INPUT: 
 * varias lineas con un texto, cada linea es un T
 * de 1 a 100.000
 * 
 * letras, _ y []
 *  termina en end of file EOF
 * 
 * This_is_a_[Beiju]_text
 * [[]][][]Happy_Birthday_to_Tsinghua_University
 * 
 * OUTPUT:
 * imrpimir el Beiju para cada caso
 * Beiju: 
 * 
 * BeijuThis_is_a__text
 * Happy_Birthday_to_Tsinghua_University
 * 
 * 
 */


#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;


    while(cin>>s){

        // usar estructura en vez de string
        // con string excede, con list tarda 0,1, con deque tarda 0,05
        // inserciones en extremos es O(1)
        deque<char> res; 
        auto rit = res.begin();

        for (auto it = s.begin(); it != s.end(); ++it) {

            switch (*it) {
                case '[':
                    rit = res.begin();
                    break;
                case ']':
                    rit = res.end();
                    break;
                default:
                   // cout<< "está en: "<<*rit<< " y va el caracter " <<*it<<"\n";
                    rit = res.insert(rit, *it); // esto retorna un iterador porque modifica
                    rit++; // avanzarlo, por esto tmb rompía
                    break;
            }
        }
        for (char c : res)
            cout << c;

        cout << '\n';
    }
    
}