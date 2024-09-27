#include <iostream>
#include <string>
#include <vector>

using namespace std;

int filtranum(vector<int> &numeros, vector<int> &resultado);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> numeros;
    numeros.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> numeros[i0];
    }
    vector<int> resultado;
    resultado.resize(0);
    int returnedValue;
    returnedValue = filtranum(numeros, resultado);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(resultado.size()); i++) {
        if (i > 0) cout << " ";
        cout << resultado[i];
    }
    cout << "\n";
    return 0;
}
