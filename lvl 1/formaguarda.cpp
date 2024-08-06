// formaguarda_ian-svn


#include <bits/stdc++.h>
using namespace std;

string formaguarda(int N,string tipo,string patron){
    char result[N];

    if(tipo=="NORMAL"){
        for(int x=0,y=0;x<N;x++,y++){
            if(y==patron.size()){
                y=0;
            }
            result[x]=patron[y];
        }
    }
    else if(tipo=="ESPEJADA"){
        for(int x=0,y=0;x<N;x++,y++){
            if(y==patron.size()){
                y=0;
                reverse(patron.begin(),patron.end());
            }
            result[x]=patron[y];
        }
    }

    return result;
}

int main(){

    system("cls");

    int N;
    string tipo;
    string patron;

    cin >> N >> tipo >> patron;

    cout << formaguarda(N,tipo,patron);
}
