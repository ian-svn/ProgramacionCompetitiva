// shining1_ian-svn 12 46 11

#include <bits/stdc++.h>
using namespace std;

int sanar(int magia, vector<int> vidaInicial, vector<int> vidaActual, vector<int> distancia){
    int rest=0, x=0;
    while(!(magia<3)){
        if(vidaInicial[x]>vidaActual[x]&&distancia[x]==1&&magia>=3){
            magia-=3;
            rest+=10;
            vidaActual[x]+10;
            if(vidaInicial[x]<vidaActual[x]){
                rest-=vidaInicial[x]-vidaActual[x];
                vidaActual[x]-=vidaInicial[x]-vidaActual[x];
            }
        } else if(vidaInicial[x]>vidaActual[x]&&distancia[x]==1||distancia[x]==2&&magia>=5){
            magia-=5;
            rest+=10;
            vidaActual[x]+=10;
            if(vidaInicial[x]<vidaActual[x]){
                rest-=vidaActual[x]-vidaInicial[x];
                vidaActual[x]-=vidaActual[x]-vidaInicial[x];
            }
        }
        x++;
        if(x>vidaInicial.size()){
            x=0;
        }
        cout << magia  << " puntos: " << rest << endl;
    }
    return rest;
}

int main(){
    int N, magia;
    vector<int> distancia;
    vector<int> vidaInicial;
    vector<int> vidaActual;

    cin >> N >> magia;

    for(int x=0;x<N;x++){
        int a,b,c;
        cin >> a >> b >> c;
        vidaInicial.push_back(a);
        vidaActual.push_back(b);
        distancia.push_back(c);
    }

    cout << sanar(magia, vidaInicial, vidaActual, distancia);

    return 0;
}
