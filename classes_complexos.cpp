/******************************************************************************

   ____   _                                       ____                               _                             
  / ___| | |   __ _   ___   ___    ___   ___     / ___|   ___    _ __ ___    _ __   | |   ___  __  __   ___    ___ 
 | |     | |  / _` | / __| / __|  / _ \ / __|   | |      / _ \  | '_ ` _ \  | '_ \  | |  / _ \ \ \/ /  / _ \  / __|
 | |___  | | | (_| | \__ \ \__ \ |  __/ \__ \   | |___  | (_) | | | | | | | | |_) | | | |  __/  >  <  | (_) | \__ \
  \____| |_|  \__,_| |___/ |___/  \___| |___/    \____|  \___/  |_| |_| |_| | .__/  |_|  \___| /_/\_\  \___/  |___/
                                                                            |_|                                    

*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

class Complexo{
    private:
        double real, imag;
    public:
        double getReal() const {return real;}
        double getImag() const {return imag;}
    void ler();
    void imprimir() const;
    
    Complexo soma(Complexo &c) const;
    Complexo produto(Complexo &c) const;
    
};

void Complexo::ler(){
    cout<<"Insira a parte real da função: ";
    cin>>real;
    cout<<"Insira a parte imaginária da função: ";
    cin>>imag;
    
}


void Complexo::imprimir()const {
    cout<<"Parte real: "<< real;
    if(imag > 0.0) cout << '+'; else cout<<'-';
    cout<<"j"<<fabs(imag);
    
}


Complexo Complexo::soma(Complexo &c) const{
    Complexo prov;
    prov.real = this->real + c.real;
    prov.imag = this->imag + c.imag;
    return prov;
}


Complexo Complexo::produto(Complexo &c) const{
    Complexo prov;
    prov.real = this->real * c.real - this->imag*c.imag;
    prov.imag = this->real * c.imag + c.real*this->imag;
    return prov;
}



int main()
{
  Complexo C1, C2, S, P;

  cout << "Digite o primeiro numero Complexo (C1):\n";
  C1.ler();

  cout << "Digite o segundo numero Complexo (C2):\n";
  C2.ler();

  S = C1.soma(C2);
  P = C1.produto(C2);

  cout << "Soma = ";
  S.imprimir();
  cout << endl;

  cout << "Produto = ";
  P.imprimir();
  cout << endl;

}