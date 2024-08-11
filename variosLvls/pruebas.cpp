#include <bits/stdc++.h>
using namespace std;

void desalambrado(int N,vector<int> a,vector<int> b,int m){

    for(int x=0;x<N;x++){
        int cant=0;
        int numBuscado=x;
        int eli=0;
        vector<int> postesAdyas;

        for(int y=0;y<m;y++){
            if((numBuscado==a[y]||numBuscado==b[y])&&numBuscado!=y){
                cant++;
                int posteAd = (a[y]==numBuscado) ? a[y] : b[y];
                postesAdyas.push_back(posteAd);
            }
        }
        
        if(cant>2){
            int aux=0;
            do{
                aux=1;
            for(int p : postesAdyas){ 
                int cantidad=0;
                for(int y=0;y<m;y++){   
                    if((p==a[y]||p==b[y])&&p!=y){
                        cantidad++;
                    }
                }
                if(cantidad>2){
                    eli=p;
                }

                if(cantidad>3){
                    aux=0;
                }
            }

            if(eli!=0){
                for(int z=0;z<m;z++){
                    if((a[z]==eli||b[z]==eli)&&(a[z]==numBuscado||b[z]==numBuscado)){
                        a.erase(a.begin() + z);
                        b.erase(b.begin() + z);
                    }
                }
            }

            }while(aux==0);
        }
    }
}
/*
int desalambrado(int N, vector <int> A, vector <int> B, vector <int> C){

}
*/

int main(){

    int N, m;
    vector <int> A;
    vector <int> B;
    vector <int> C;

    cin >> N >> m;

    for(int x = 0; x < m;x++){
        int a,b,c;
        cin >> a >> b >> c; 
        A.push_back(a); 
        B.push_back(b); 
        C.push_back(c);
        if(a==b){
            cout << "chau1";
            return 0;
        } if(a>N||b>N){
            cout << "chau2";
            return 0;
        }
    }

    desalambrado(N, A, B,m);

    for(int x = 0;x<m;x++){
        cout<<A[x] << " " << B[x] << endl;
    }

}