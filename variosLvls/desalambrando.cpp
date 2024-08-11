// desalambrando_ian-svn. lvl 2 y 3

#include <bits/stdc++.h>
using namespace std;

int desalambrado(int N, vector<int>& a, vector<int>& b, vector<int>& c, int& m) {
    vector<int> eli;

    for (int x = 1; x <= N; x++) {
        vector<int> postesAdyas;
        
        for (int y = 0; y < m; y++) {
            if (a[y] == x || b[y] == x) {
                int posteAd = (a[y] == x) ? b[y] : a[y];
                postesAdyas.push_back(posteAd);
            }
        }

        if (postesAdyas.size() > 2) {
            for(int poste : postesAdyas){
                int cant=0;
                for (int y = 0; y < m; y++) {
                    if (a[y] == poste || b[y] == poste) {
                        cant++;
                    }
                }

                if(cant>2){
                    for (int y = 0; y < m; y++) {
                        if ((a[y] == poste && b[y] == x)||(a[y] == x && b[y] == poste)) {
                            eli.push_back(c[y]);
                            a.erase(a.begin()+y);
                            b.erase(b.begin()+y);
                            c.erase(c.begin()+y);
                            m=m-1;
                        }
                    }
                }
            }
        }
    }

    int cuadrado=0;
    int acu=0;

    for(int x = 1; x <= N; x++){
        int cantidad=0;
        for (int y = 0; y < m; y++) {
            if (a[y] == x || b[y] == x) {
                cantidad++;
            }
        }
        if(cantidad==2){
            cuadrado++;
        }
    }

    acu = 0;

    if(cuadrado==N){
        int aux=99999999,pos;
   
        for (int x = 0; x < m; x++) {
            if(aux > c[x]){
                aux = c[x];
                pos = x;
            }
        }

        eli.push_back(c[pos]);
        a.erase(a.begin()+pos);
        b.erase(b.begin()+pos);
        c.erase(c.begin()+pos);
        m=m-1;
    }

    for (int x = 0; x < eli.size(); x++) {
        acu+=eli[x];
    }


    return acu;
}

int main() {
    int N, m;
    vector<int> A, B, C;

    cin >> N >> m;

    for (int x = 0; x < m; x++) {
        int a, b, c;
        cin >> a >> b >> c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        if (a == b) {
            return 0;
        }
        if (a > N || b > N) {
            return 0;
        }
    }

    cout << desalambrado(N, A, B, C, m);

    return 0;
}
