// dividiendo_ian-svm

#include <bits/stdc++.h>
using namespace std;

int numero, veces;

int dividiedo(int numero, int veces){
    int rest=numero;
    for(int x=0;x<veces;x++){
        rest = rest/2;
    }
    return rest;
}

int main(){

    cin >> numero >> veces;

    cout << dividiedo(numero,veces);
}
