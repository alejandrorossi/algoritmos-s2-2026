/**
 * 
 * matrices, i fila, j columna
 * "1" base
 * hay que trasponer una matriz: M^t
 * es intercambiar filas por columnas
 * a(i,j)= a^t(j,i)
 * 
 * INPUT:
 * m,n.  row column
 * m sets de numeros de dos lineas
 *  linea 1: r col1 .. colR
 *      donde R es elementos!=0 de fila (indices ascendentes)
 *      indices no mencionados entre 1 y R valdrán 0
 *  linea2: v1 v2 .. vR (valores)
 * 
 * // la solucion es directamente leerla invertida,
 * 
 * // imprimirla es medio un lio
 * 
 */

#include <iostream>
#include <vector>
#include <deque> 

using namespace std;
using tint = long long;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint n,m;
    
    //rows and columns
    while (cin >> m >> n) {

        //n filas, m columnas, o sea al reves de como viene
        vector<vector<tint>>Mt(n, vector<tint>(m));
        vector<tint>nonZerosPerRow(n); // las filas que tendrá, necesario pa respuesta

        for(tint i=0; i<m; i++){ // se leen solo filas, que van a ser columnas
                
            tint r; 
            cin >> r;
            vector<tint> coords(r); //mejor asi que dinamico con pushback?

            for(int k=0; k<r; k++){ //lectura de posiciones
                tint col; cin >> col;
                coords[k]=col;
            }
        
            for(auto c:coords){ // carga valores (viene cols, mandar a row)
                tint val; cin >> val;
                Mt[c-1][i] = val; // esto es fila - columna, pero invertimos
                nonZerosPerRow[c-1]++; //c es columna que va. a ser fila
            }    
        }

        cout<< n <<" "<< m <<endl;

        // imprimo
        for (int i = 0; i < n; i++) { //filas
            cout<<nonZerosPerRow[i]; // esto tiene numero  de columnas diferentes de 0
            vector<tint> secondLine;

            //impresion de index de columnas con valores
            for (int j = 0; j < m; j++) { //columnas
                //cout << Mt[i][j] << " "; 
                if(Mt[i][j]!=0) {
                        cout<<" "<< j+1;
                        secondLine.push_back(j);
                    }
            }
            
            cout << endl;
            //impresion de la segunda linea, valores de columnas
            tint sLinelen = secondLine.size();
            for(int s=0; s<sLinelen; s++) {
                cout << Mt[i][secondLine.at(s)];
                if(s<sLinelen-1) cout <<" ";
            }

            cout << endl;
        
        }
        // procesar una matriz completa
    }
    return 0;
}