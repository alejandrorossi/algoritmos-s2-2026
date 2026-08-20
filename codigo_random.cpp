#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>



using namespace std;
using tint = long long;


int main(){

        set<int> ns, ms;
        // para recorrer por ejemplo dos sets de una
        auto it1 = ns.begin();
        auto it2 = ms.begin();
        //al sacar repetidos itera menos
        while (it1 != ns.end() && it2 != ms.end()) {
            cout << "set1: " << *it1 << ", set2: " << *it2 << '\n';
            
            ++it1;
            ++it2;
        }

    //descarta resto de in hasta llegar a salto
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 


    // hacer interseccion
     multiset<tint> intersection;
    set_intersection(ns.begin(), ns.end(),ms.begin(), ms.end(), inserter(intersection, intersection.begin()));


    }