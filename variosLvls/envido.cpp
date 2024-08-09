// envido_ian-svn  

#include <bits/stdc++.h>
using namespace std;

int envido(int numero1, string palo1,int  numero2, string  palo2,int  numero3, string  palo3){
    if((palo1==palo2)||(palo2==palo3)||(palo3==palo1)){
        string paloIgual; int num1; int num2;
        if(palo1==palo2&&palo2==palo3){
            num1=max(numero1,numero2);
            num2=max(numero2,numero3);
            if(num2==num1){ num2=numero3;}
        } else if((palo1==palo2)){
            num1=numero1;
            num2=numero2;
        } else if(palo2==palo3){
            num1=numero2;
            num2=numero3;
        } else if(palo3==palo1){
            num1=numero1;
            num2=numero3;
        } else {
            return max(max(numero1,numero2),max(numero2,numero3));
        } 

        if((num1<10&&(num2<10))&&num1<=12&&num2<=12&&num1>=1&&num2>=1){
            return num1+num2+20;
        } if((num1>=10||(num2>=10))&&num1<=12&&num2<=12&&num1>=1&&num2>=1){
            int numMenor = (num1<10) ? numMenor=num1 : numMenor=num2;
            return 20 + numMenor;
        }

    }

    return max(max(numero1,numero2),max(numero2,numero3));
}

int main(){
    int numero1, numero3, numero2; 
    string palo1, palo2, palo3;

    cin >> numero1 >> palo1;
    cin >> numero2 >> palo2;
    cin >> numero3 >> palo3;

    cout << envido(numero1, palo1, numero2, palo2, numero3, palo3);

    return 0;
}