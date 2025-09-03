#ifndef _VETOR_H_
#define _VETOR_H_

#include <iostream> //para usar o istream e ostream

class Vetor{
private:
    int N;
    double* x;
public:
    //construtores e destrutores 1º
    Vetor(): N(0), x(nullptr){};
    Vetor(const Vetor& V);
    Vetor(Vetor&& V) noexcept;
    explicit Vetor(int Num);
    ~Vetor();
    //operadores de atribuição 2º
    Vetor& operator=(const Vetor& V);
    Vetor& operator=(Vetor &&V) noexcept;

    //metodos de consulta e alteracao 3º
    int size() const{return N;}
    double operator[](int i) const; //(consulta)toda funçao checa seus parametros
    void set(int i, double valor);
    void push_back(double valor);

    // funcoes friends para ler os dados privados da classe Vetor que utilizam dos streams de saida e entrada de dados
    friend std::ostream& operator<<(std::ostream& X, const Vetor& V);
    friend std::istream& operator>>(std::ostream& X, Vetor& V);

    //funcoes de definir operadores
    Vetor operator+(const Vetor& V) const;
    Vetor operator-(const Vetor& V) const;

    //operador unario
    Vetor operator-() const;

    //funcoes de metodos de vetores, algebra vetorial e matricial
    double norma()const;
    double escalar(const Vetor& V) const;
    double vetorial(const Vetor& V) const;

};

#endif // _VETOR_H_
