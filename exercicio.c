/*
 ######  ######## ########  ##     ##  ######  ########         ##    ## ##     ## ##     ## ######## ########   #######   ######   ######   #######  ##     ## ########  ##       ######## ##     ##  #######   ######
##    ##    ##    ##     ## ##     ## ##    ##    ##            ###   ## ##     ## ###   ### ##       ##     ## ##     ## ##    ## ##    ## ##     ## ###   ### ##     ## ##       ##        ##   ##  ##     ## ##    ##
##          ##    ##     ## ##     ## ##          ##            ####  ## ##     ## #### #### ##       ##     ## ##     ## ##       ##       ##     ## #### #### ##     ## ##       ##         ## ##   ##     ## ##
 ######     ##    ########  ##     ## ##          ##    ####### ## ## ## ##     ## ## ### ## ######   ########  ##     ##  ######  ##       ##     ## ## ### ## ########  ##       ######      ###    ##     ##  ######
      ##    ##    ##   ##   ##     ## ##          ##            ##  #### ##     ## ##     ## ##       ##   ##   ##     ##       ## ##       ##     ## ##     ## ##        ##       ##         ## ##   ##     ##       ##
##    ##    ##    ##    ##  ##     ## ##    ##    ##            ##   ### ##     ## ##     ## ##       ##    ##  ##     ## ##    ## ##    ## ##     ## ##     ## ##        ##       ##        ##   ##  ##     ## ##    ##
 ######     ##    ##     ##  #######   ######     ##            ##    ##  #######  ##     ## ######## ##     ##  #######   ######   ######   #######  ##     ## ##        ######## ######## ##     ##  #######   ######


*/


#include <iostream>

using namespace std;

struct Complexo{
    double real, imag;
};

void recebe_complexo(Complexo &c){
    cout << "Insira a parte real de sua fun��o: ";
    cin >> c.real;
    cout << "Insira a parte imaginaria de sua fun��o:";
    cin >> c.imag;
}

Complexo ler(){
    Complexo prov;
    cout<< "Insira a parte real da sua fun��o: ";
    cin>> prov.real
    cout<< "Insira a parte imaginaria da sua fun��o: ";
    cin>> prov.imag
}

void imprime_complexo(const Complexo &c){
    cout<<"f(x)= "<< c.real;
    if(c.imag>0.0) cout<<"+" else cout<<"-";
    cout<<c.imag<<"j";
}

Complexo imprimir(){
    Complexo prov;
    cout<<"f(x)= "<< prov.real;
    if(prov.imag>0.0) cout<<"+" else cout<<"-";
    cout<<prov.imag<<"j";

}

int main(){



}



####imcompleto
