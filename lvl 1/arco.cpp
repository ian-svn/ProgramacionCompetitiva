    // arco_ian-svn 17:13 29

    #include <bits/stdc++.h>
    using namespace std;

    string arco(int x,int y){
        string rest;
        
        if(x>0&&x<732&&y<232){
            rest="GOL";
        } else if(x>=0&&x<=732&&y<=232){
            rest="PALO";
        } else {
            rest="AFUERA";
        }

        return rest;
    }

    int main(){
        int x, y;
        cin >> x >> y;
        if(x>1000||x<-1000||y>1000||y<-1000){
            return 0;
        }
        cout << arco(x,y);
    }