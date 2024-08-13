// divisores1_ian-svn

#include <bits/stdc++.h>
using namespace std;


bool numPrimo(int num){
    int count=0;
    for(int x=1;x<=num;x++){
        if(num%x==0){
            count++;
        }
    }
    if(count == 2){
        return true;
    }
    return false;
}

vector<int> divisores(int N){

    vector<int> a;
    vector<int> g;

    int auxiliar = N;

    int aux=0;

    a.push_back(N);
    g.push_back(N);
   
    while(N!=1){
        if(aux==0){
            for(int x=N;x>=1;x--){
                if(numPrimo(x)&&N%x==0){
                    int b = N/x;
                    a.push_back(b);
                    N/=x;
                    break;
                }
            }
            aux=1;
        } else {
            for(int x=1;x<N;x++){
                if(numPrimo(x)&&N%x==0){
                    int b = N/x;
                    a.push_back(b);
                    N/=x;
                    break;
                }
            }
            aux=0;
        }
    }
    aux=1;
    N=auxiliar;

    while(N!=1){
        if(aux==0){
            for(int x=N;x>=1;x--){
                if(numPrimo(x)&&N%x==0){
                    int a = N/x;
                    g.push_back(a);
                    N/=x;
                    break;
                }
            }
            aux=1;
        } else {
            for(int x=1;x<=N;x++){
                if(numPrimo(x)&&N%x==0){
                    int b = N/x;
                    g.push_back(b);
                    N/=x;
                    break;
                }
            }
            aux=0;
        }
    }
   

    vector<int> rest;

    int acu1=0;
    int acu2=0;
   
    for(int x=0;x<a.size();x++){
        acu1+=a[x];
    }

    for(int x=0;x<g.size();x++){
        acu2+=g[x];
    }

    rest.push_back(acu1);
    rest.push_back(acu2);

    return rest;
}

int main(){
    int N;

    cin >> N;

    vector <int> rest = divisores(N);

    for(int x=0;x<rest.size();x++){
        cout << rest[x] << " ";
    }

}