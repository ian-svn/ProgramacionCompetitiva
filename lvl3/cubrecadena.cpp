// cubrecadena_ian-svn

#include <bits/stdc++.h>
using namespace std;

int posi,posf;
int N;
string S;
vector<string> t;

void quePos(string txt, string sub){
    for(int x=0;x<txt.size();x++){
        if(sub[0]==txt[x]){
            posi=x;
        }
    }
    posf=sub.size();
}

bool contiene(string txt, string sub){
    return txt.find(sub) != string::npos;
}

int cubrecadena(string S,vector<string> t){
    for(int x=0;x<t.size();x++){
        if(contiene(S,t[x])){
            quePos(S, t[x]);
            S.erase(posi,posf);
        }
    }
    return S.size();
}

int main(){

    getline(cin, S);
    cin >> N;

    for(int x=0;x<N;x++){
        string txt;
        cin >> txt;
        t.push_back(txt);
    }

    cout << cubrecadena(S,t);
}