#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> vecResp;
int N;

void inicialzar(){
    cin >> N;
}

void agregar(int x){
    vec.push_back(x);
}

void contar(int a, int b){
    int count=0;
    for(int x=0;x<vec.size();x++){
        if(vec[x]>=a&&vec[x]<=b){
            count++;
        }
    }
    vecResp.push_back(count);
}

int main(){

    inicialzar();

    for(int x=0;x<N;x++){
        int des;
        cin >> des;
        if(des == 1){
            int x;
            cin >> x;
            agregar(x);
        } else if(des == 0){
            int a,b;
            cin >> a >> b;
            contar(a,b);
        }
    }

    for (int e : vecResp){
        cout << e << endl;
    }

    return 0;
}