#include <bits/stdc++.h>
using namespace std;

int N;

int panes(vector<int> k,vector<int> C){

    int min,maxC;
    for(int p : k)
        min+=p;
    for(int c : C)
        maxC+=c;

    min-=maxC; //min pan dado a cada ciudad
    
    for(int x=0;x<N;x++){
        int c;
        (x!=0) ? c=C[x-1] : c=C[x];
        if(k[x]<k[x+1]){
            
        }
    }

}

int main(){
    
    system("cls");

    cin >> N;

    vector<int> k;
    for(int x=0;x<N;x++){
        int num;
        cin>>num;
        k.push_back(num);
    }

    vector<int> C;
    for(int x=0;x<N-1;x++){
        int num;
        cin>>num;
        C.push_back(num);
    }

    int pm = panes(k,C);


    cout<<pm<<endl;
}