#include <iostream>   // Biblioteca estándar para la entrada/salida
#include <vector>     // Biblioteca para usar la clase std::vector (vectores dinámicos)
#include <cmath>      // Biblioteca para funciones matemáticas (aunque solo queda para futuras operaciones)

using namespace std;  // Evita escribir "std::" antes de los objetos de la biblioteca estándar

// Declaramos variables globales para el número de filas (N) y columnas (M)
int N, M;

// Función que calcula el "esfuerzo" entre dos alturas elevando al cuadrado su diferencia
int fun(int h1, int h2) {
    return (h1 - h2) * (h1 - h2);  // Devuelve el cuadrado de la diferencia de alturas
}

// Función principal que recibe una matriz (mapa) y calcula el esfuerzo total en el trekking
int trekking(const vector<vector<int>>& mapa) {
    int esfuerzo = 0;  // Variable para acumular el esfuerzo total
    int x = 0, y = 0;  // Posición inicial en la matriz, comenzamos en la esquina superior izquierda (0, 0)

    // Bucle que se ejecuta hasta llegar a la última fila o columna
    while (x < N - 1 || y < M - 1) {  
        // Primero intentamos movernos hacia abajo (si x+1 está dentro de los límites)
        // También verificamos si es mejor moverse hacia abajo en vez de a la derecha
        if (x + 1 < N && (y + 1 >= M || abs(mapa[x+1][y] - mapa[x][y]) <= abs(mapa[x][y+1] - mapa[x][y]))) {
            // Si la diferencia de alturas entre la posición actual y la de abajo es menor o igual a 150
            if (abs(mapa[x+1][y] - mapa[x][y]) <= 150) {
                esfuerzo += fun(mapa[x+1][y], mapa[x][y]);  // Calculamos y sumamos el esfuerzo entre las dos alturas
                x++;  // Movemos hacia abajo (incrementamos x)
            }
        }
        // Si no podemos movernos hacia abajo, o si es más conveniente moverse a la derecha
        // Verificamos que y+1 está dentro de los límites y que la diferencia de alturas es válida
        else if (y + 1 < M && (y - 1 <= 0 || abs(mapa[x][y-1] - mapa[x][y]) <= abs(mapa[x][y+1] - mapa[x][y]))) {
            if (abs(mapa[x][y+1] - mapa[x][y]) <= 150) {
                esfuerzo += fun(mapa[x][y+1], mapa[x][y]);  // Calculamos y sumamos el esfuerzo entre las dos alturas
                y++;  // Movemos hacia la derecha (incrementamos y)
            }
        } else if (y + 1 < M) {
            if (abs(mapa[x][y+1] - mapa[x][y]) <= 150) {
                esfuerzo += fun(mapa[x][y+1], mapa[x][y]);  // Calculamos y sumamos el esfuerzo entre las dos alturas
                y++;  // Movemos hacia la derecha (incrementamos y)
            }
        } else {
            esfuerzo=-1;
            break;
        }
    }

    // Retornamos el esfuerzo total acumulado
    return esfuerzo;
}

int main() {
    // Leemos el tamaño de la matriz (N filas y M columnas)
    cin >> N >> M;

    // Declaramos una matriz de tamaño N x M, inicializada con ceros
    vector<vector<int>> mapa(N, vector<int>(M));

    // Rellenamos la matriz con las alturas del mapa
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mapa[i][j];  // Leemos el valor de altura de cada celda de la matriz
        }
    }

    // Llamamos a la función trekking() pasando la matriz "mapa" como argumento
    // Almacenamos el resultado (esfuerzo total) en la variable 'resultado'
    int resultado = trekking(mapa);

    // Mostramos el esfuerzo total calculado
    cout << "Esfuerzo total: " << resultado << endl;

    return 0;  // El programa termina correctamente
}
