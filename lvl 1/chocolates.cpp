// chocolates_ian-svn

#include <bits/stdc++.h>
using namespace std;

int chocolates(int K,vector<int> x){
    int rest=0;
    
    for(int y=0;y<x.size();y++){
        while(x[y]>=K){
            x[y]-=K;
            rest++;
        }
    }

    return rest;
}

int main(){
    int K, N;
    vector <int> x;

    cin >> N >> K;
    for(int y=0;y<N;y++){
        int a;
        cin >> a;
        x.push_back(a);
    }

    cout << chocolates(K,x);
}