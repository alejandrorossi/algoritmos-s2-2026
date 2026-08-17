#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>



using namespace std;
using tint = long long;


int main(){

// para recorrer por ejemplo dos sets de una

         auto it1 = ns.begin();
        auto it2 = ms.begin();
        //al sacar repetidos itera menos
        while (it1 != ns.end() && it2 != ms.end()) {
            cout << "set1: " << *it1 << ", set2: " << *it2 << '\n';
            
            ++it1;
            ++it2;
        }

    }