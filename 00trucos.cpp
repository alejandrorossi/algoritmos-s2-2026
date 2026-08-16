#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
using tint = long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const int INF = 1e9;
    long long INF = 1e9;

    vector<int> v;              // vector vacío
    vector<int> b(5);           // 5 elementos inicializados en 0
    vector<int> c(5, 7);        // 5 elementos inicializados en 7
    vector<int> nums = {1, 2, 3, 5, 5, 8};  // inicialización con lista

    v.push_back(10);   // agrega al final
    v.pop_back();      // elimina el último
    int ultimo = v.back();    // muestra ultimo elemento
    int primero = v.front();  // muestra primer elemento
    int x = v[0]; // acceso por índice
    int tam = v.size(); // tamaño actual
    v.resize(10); // cambia tamaño
    v.clear();    // vacía el vector
    v.empty(); //booleano


    //vector
    int n;
    cin >> n; // leer cantidad a cargar
    vector<int> arr(n);
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; // leer n elementos
    }

    for (int x : nums) {
        cout << x << '\n';
    }

    //PAIRS
    vector<pair<int, int>> pares;
    pares.push_back({1, 2});

    for (auto p : pares) {
        cout << p.first << " " << p.second << '\n';
    }

    //map
    map<string, int> mp;
    mp["juan"] = 10; // inserta o modifica
    cout << mp["juan"] << '\n'; // acceder
    bool juan = mp.count("juan"); // verifica existencia
    mp.erase("juan"); // elimina clave

    for (auto par : mp) {
        cout << par.first << " -> " << par.second << '\n';
    }

    //CARGAR MATRIZ
    int m, n;  cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m)); // matrix M con n filas, inicializadas con vectores vacios de m columnas

    for (int i = 0; i < n; i++) { //filas
        for (int j = 0; j < m; j++) { //columnas
            cin >> M[i][j]; //para imprimir sería cout << M[i][j] << " ";
            //M[i][j] = s[j] - '0'; // si vienen numeros pegados como string
            //   cout << M[i][j] << " "; //imprimirla
        }
        //cout << "\n"; //imprimirla
    }

    //colections

    set<int> s; // ordenados, sin repetir
    s.insert(5); // erase(x), count(x)

    multiset<int> ms; //ordenados con repetidos
    ms.insert(4); ms.insert(5);
    auto it = ms.lower_bound(4); //primer elemento mayor o igual a x (retorna iterador)
    auto it2 = ms.upper_bound(4); // primer estricto mayor (retorna iterador)
     cout << *it << '\n'; // para ver el valor 4
    it == ms.end(); // operacion de verificacion si no encuentra

    //priority queue para min/max en O1
    priority_queue<int> pq;
    // priority_queue<pair<int,int>> pq;  pair ordena por first, lexicografico
    pq.push(10);  pq.push(3);
    cout << pq.top(); //10
    pq.pop(); //elimina maximo

    //min heap
    // con greater siempre tiene arriba al menor, pero no queda ordenado internamente
    priority_queue<int, vector<int>, greater<int>> pq_min; 
    pq_min.push(10);
    pq_min.push(3);
    pq_min.push(20);
    pq_min.push(1);
    pq.top(); //1 si se hace pop, luego el top será 3, si se repite 10 y 20, luego empty da true
    //1 3 10 20


    return 0;
}

/**
 * 2×10^5=200000s
 * logaritmo 17.6 = 18
 * 
 * 
 */