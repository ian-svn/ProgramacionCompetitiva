#include <string>
#include <vector>

using namespace std;

int filtranum(vector<int> &numeros, vector<int> &resultado) {
    int n=0;
    for(int x=0;x<numeros.size();x++){
        string numero;
        numero = to_string(numeros[x]); 
        if(numero[0]==numero[numero.size()-1]){
            resultado.push_back(numeros[x]);
            n++;
        }
    }
    return n;
}
