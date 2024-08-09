// pizzas_ian-svn   22 27      41

/*

*/

#include <bits/stdc++.h>
using namespace std;

void repPorciones(int np,int cantP){
    const int enCuantoSeCorta = 8; 
    int porcioneT = cantP*enCuantoSeCorta;
    int maso = porcioneT/np;

    for(int x = 0;x<np;x++){
        if(maso<porcioneT)
            porcioneT-=maso;
    }

    cout << maso << " " << porcioneT;
    
} 

int main(){
    int np, cantP;

    cin >> np >> cantP;

    repPorciones(np,cantP);

}