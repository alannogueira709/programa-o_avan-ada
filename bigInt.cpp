#include "bigInt.h"

#include <iostream>
#include <cmath>

using namespace std;

BigInt::BigInt(bool sinal, int numero): neg(sinal) {
    if (numero <= 0){
       nDig = 0;
       d = nullptr;
    }
    else{
        nDig = numero;
        d = new int8_t[nDig];
        for(int i = 0; i < nDig; i++){
            d[i] = 0;
        }
    }
}
BigInt::BigInt(long long int li){
    if (li < 0){
        neg = true;
        li = -li;
    }
    neg = false;

    if (li == 0){
       BigInt();
         return;
    }else{
        nDig = 1 + int(log10(fabs(li)));
        d = new int8_t[nDig];
        for(int i = 0; i < nDig; i++){
            d[i] = li % 10;
            li /= 10;
        }
    }
    
}


BigInt::~BigInt(){
    delete[] d;
}

void BigInt::correct(BigInt &big){
    if (big.size() <= 0 || big.d == nullptr){
        big = BigInt();
    }
    for(int i=big.size()- 1; i>=0; i--){
        if (big.d[i]!=0){
            return;
        }
        big.nDig--;
    }
    if(big.nDig){
        int8_t *novoD = new int8_t[big.nDig];
        for(int i = 0; i < big.nDig; i++){
            novoD[i] = big.d[i];
        }
        delete[] big.d;
        big.d = novoD; 
    }
}
