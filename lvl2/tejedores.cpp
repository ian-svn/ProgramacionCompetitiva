// tejedores_ian-svn

#include <bits/stdc++.h>
using namespace std;

int tejedores(int K, vector<int> t){
    bool aux;
    int a=0;
    vector<int> sum;

    for(int y = 0 ;y<t.size();y+=K){
        int maximo=-999999;
        for(int x=y;x<y+K;x++){
            if(maximo<t[x]){
                maximo=t[x];
            }
            if(!(x+1<y+K)||t.size()<=x){
                sum.push_back(maximo);
            }
            if(t.size()<=x){
                break;
            }
        }
    }

    int rest=0;

    for(int x = 0;x<sum.size();x++){
        rest+=sum[x];
    }

    return rest;
}


int main(){
    int N, K;
    cin >> N >> K;
    vector<int> t(N);
    for(int x=0;x<N;x++){
        cin >> t[x];
    }

    cout << tejedores(K,t);
}