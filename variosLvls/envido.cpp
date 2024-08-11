// envido_ian-svn. lvl 1, 2 y 3

#include <bits/stdc++.h>
using namespace std;

int cartaMasAlta(int numero1, int numero2, int numero3){
    int cA = max(max(numero1,numero2),max(numero2,numero3));
    if(numero1>=10||numero2>=10||numero3>=10){
        if(numero1>=10&&numero2>=10&&numero3>=10){
            return 0;
        }
        if(numero1>=10||numero2>=10){
            cA=(numero1>=10) ? numero2 : numero1;
        } else if(numero3>=10||numero2>=10){
            cA=(numero3>=10) ? numero2 : numero3;
        }
    }
    return cA;
}

int envido(int numero1, string palo1,int  numero2, string  palo2,int  numero3, string  palo3){
    
    if((palo1==palo2)||(palo2==palo3)||(palo3==palo1)){
        string paloIgual; int num1; int num2;
        if(palo1==palo2&&palo2==palo3){
            num1=(numero1<10&&numero2<10) ? max(numero1,numero2) : min(numero1,numero2);
            num2=(numero2<10&&numero3<10) ? max(numero2,numero3) : min(numero2,numero3);
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
        }

        if((num1<10&&(num2<10))&&num1<=12&&num2<=12&&num1>=1&&num2>=1){
            return num1+num2+20;
        } else if(num1>=10&&num2>=10){
            return 20;
        } else if((num1>=10||(num2>=10))&&num1<=12&&num2<=12&&num1>=1&&num2>=1){
            int numMenor = (num1<10) ? numMenor=num1 : numMenor=num2;
            return 20 + numMenor;
        } 

    }

    return cartaMasAlta(numero1, numero2, numero3);
}

int main(){
    int numero1, numero3, numero2; 
    string palo1, palo2, palo3;

    cin >> numero1 >> palo1;
    cin >> numero2 >> palo2;
    cin >> numero3 >> palo3;

    if(!(numero1>=1&&numero1<=12&&numero1!=8&&numero1!=9)){
        return 1;
    }
    if(!(numero2>=1&&numero2<=12&&numero2!=8&&numero2!=9)){
        return 2;
    }
    if(!(numero3>=1&&numero3<=12&&numero3!=8&&numero3!=9)){
        return 3;
    }
    
    if(palo1!="oros"&&palo1!="copas"&&palo1!="espadas"&&palo1!="bastos"){
        return 4;
    }
    if(palo2!="oros"&&palo2!="copas"&&palo2!="espadas"&&palo2!="bastos"){
        return 5;
    }
    if(palo3!="oros"&&palo3!="copas"&&palo3!="espadas"&&palo3!="bastos"){
        return 6;
    }
    int res = envido(numero1, palo1, numero2, palo2, numero3, palo3);

    cout << res << endl;

    return 0;
}