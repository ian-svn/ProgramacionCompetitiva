// zetadieta_ian-svn

#include <bits/stdc++.h>
using namespace std;


int zetadieta(int C, int P, int G){
    int count=0,cal=0;
    while(count!=3){
        count=0;

        if(C>=27||C>0){
            C-=27;
            cal+=105;
        } else {
            count++;
        }


        if(P>=30||P>0){
            P-=30;
            cal+=120;
        } else {
            count++;
        }


        if(G>=1||G>0){
            G-=1;
            cal+=9;
        } else {
            count++;
        }
    }
    return cal;
}

int main(){
    int C, P, G;
    
    cin >> C >> P >> G;
    
    cout << zetadieta(C, P, G);
}