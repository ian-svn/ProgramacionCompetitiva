// cadenas_ian-svn

#include <bits/stdc++.h>
using namespace std;

int cadenas(int num){

    vector<int> vec;

    int suma=0;
    int rest=num;
    for(int x=num;x>=1;x--){
        if(rest%x==0){
            rest=x;
            suma+=rest;
        }
    }

    return suma;
}

int main (){

    system("cls");

    int num;
    cin >> num;

    cout << cadenas(num);
}