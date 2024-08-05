// Hallando el valor de x_ian-svn

#include <bits/stdc++.h>
using namespace std;

int hallarx(string a, string b, string c){
    int x;
    int count=0;
    if(a.find('x')!=string::npos){
        count = 1;
    } else if(b.find('x')!=string::npos){
        count = 2;
    } else if(c.find('x')!=string::npos){
        count = 3;
    } else {
        return -1;
    }
    
    if(count==1){
        int i=stoi(b);
        int j=stoi(c);
        int k= a.find('x');

        for(int y=0;y<=9;y++){
            string newNum=a;
            newNum.erase(k,1);
            newNum.insert(newNum.begin()+k,y+'0');
            int nuwNumI = stoi(newNum);

            if(nuwNumI+i==j){
                return y;
            }
        }
        return -1;
    } else if(count==2){
        int i=stoi(a);
        int j=stoi(c);
        int k= b.find('x');
    

        for(int y=0;y<=9;y++){
            string newNum=b;
            newNum.erase(k,1);
            newNum.insert(newNum.begin()+k,y+'0');
            int nuwNumI = stoi(newNum);

            if(nuwNumI+i==j){
                return y;
            }
        }
        return -1;
    } else if(count==3){
        int i=stoi(a);
        int j=stoi(b);
        int k= c.find('x');
        
        for(int y=0;y<=9;y++){
            string newNum=c;
            newNum.erase(k,1);
            newNum.insert(newNum.begin()+k,y+'0');
            int nuwNumI = stoi(newNum);
            if(j+i==nuwNumI){
                return y;
            }
    }
        return -1;
    }

    return -1;
}

int main (){

    system("cls");

    string a,b,c;

    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    
    cout << hallarx(a,b,c);
}