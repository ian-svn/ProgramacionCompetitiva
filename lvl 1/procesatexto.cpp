// procesatexto_ian-svn

#include <bits/stdc++.h>
using namespace std;

string INTERCAMBIA(string str){
    for(int x=0;x<str.size();x++){
        if(str[x]>=97&&str[x]<=122){
            str[x]-=32;
        } else if(str[x]>=65&&str[x]<=90){
            str[x]+=32;
        }
    }
    return str; 
}
string BORRAULTI(string str){
    if(str.empty()){
        return str;
    }
    str.erase(str.end()-1,str.end());
    
    return str;
}
string BORRAPRI(string str){
    str.erase(str.begin(),str.begin()+1);
    return str;
}

string DUP(string str){
    string strN = str.append(str);
    return strN;
}
string ROTA(string str){
    char aux;
    aux = str.front();
    str.front()=str.back();
    str.back()=aux;
    return str;
}
string INVERTIR(string str){
    reverse(str.begin(),str.end());
    return str;
}
string CHAUAGUS(string str){
    if(!str.empty()){
        int count=0,i,e;
        for(int x=0;x<str.size();x++){
            if((str[x]=='a'||str[x]=='A')&&(str[x+1]=='g'||str[x+1]=='G')&&(str[x+2]=='u'||str[x+2]=='U')&&(str[x+3]=='s'||str[x+3]=='S')){
                i=x;
                e=x+3;
                str.erase(i, 4);
                break;
            }
        }
    }
    return str;
}

string AGREGA(string str,string a){
    str.append(a);
    return str;
}

string DUP(string str,int i, int j){
    string aux = str.substr(i,j - i+1);
    str.insert(j,aux);
    return str;
}

string INVERTIR(string str,int i,int j){
    reverse(str.begin()+i,str.begin()+j+1);
    return str;
}
string BORRA(string str,int i){
    str.erase(i,1);
    return str;
}
string CHAU(string str,string a){
    int e = str.find(a);
    int i = a.size();
    
    if (e == string::npos) {
        return str;
    }
    if(a.size()>str.size()){
        return str;
    }

    str.erase(e,i);

    return str;
}

vector<string> comandos;

string procesatexto(string str_rest, vector<string> comandos){
    for(string comando : comandos){
        int i,j;
        string a;
        if(comando == "INTERCAMBIA"){
            str_rest = INTERCAMBIA(str_rest);
        }
        else if(comando == "BORRAULTI"){
            str_rest = BORRAULTI(str_rest);
        }
        else if(comando == "BORRAPRI"){
            str_rest = BORRAPRI(str_rest);
        }
        else if(comando == "DUP"){
            str_rest = DUP(str_rest);
        }
        else if(comando == "ROTA"){
            str_rest = ROTA(str_rest);
        }
        else if(comando == "INVERTIR"){
            str_rest = INVERTIR(str_rest);
        }
        else if(comando == "CHAUAGUS"){
            str_rest = CHAUAGUS(str_rest);
        }
        else if(comando.find('-') != string::npos){
            int x = comando.find('-');
            if(comando.find("AGREGA-")!= string::npos){
                string a = comando.substr(x+1,comando.size());
                str_rest = AGREGA(str_rest,a);
            }

            else if(comando.find("DUP-")!= string::npos){
                int y=comando.find('-',x+1);
                
                i = stoi(comando.substr(x+1,y-1));
                j = stoi(comando.substr(y+1));

                str_rest =  DUP(str_rest,i-1,j-1);
            }
            else if(comando.find("INVERTIR-") == 0){
                int y=comando.find('-',x+1);

                i = stoi(comando.substr(x+1,y-1));
                j = stoi(comando.substr(y+1));

                str_rest = INVERTIR(str_rest,i-1,j-1);
            }
            else if(comando.find("BORRA-") == 0){
                i = stoi(comando.substr(x+1));
                str_rest = BORRA(str_rest,i-1);
            }
            else if(comando.find("CHAU-")==0){
                string a = comando.substr(x+1,comando.size());
                str_rest = CHAU(str_rest,a);
            }
        }
    }
    return str_rest;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    string str_ini;
    int n;

    fflush(stdin);
    cin>>str_ini;
    cin>>n;


    for(int x=0;x<n;x++){
        string comando;
        cin >> comando;
        comandos.push_back(comando);
    }

    string string_rest = procesatexto(str_ini,comandos);

    cout<<string_rest;
}