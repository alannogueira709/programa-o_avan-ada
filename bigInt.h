#ifndef _BIGINT_H_
#define _BIGINT_H_
/*
 |   | ____|    \    __ \  ____|  _ \          __ )_ _|  ___| _ _|  \  |__ __|
 |   | __|     _ \   |   | __|   |   |         __ \  |  |       |    \ |   |
 ___ | |      ___ \  |   | |     __ <  _____|  |   | |  |   |   |  |\  |   |
_|  _|_____|_/    _\____/ _____|_| \_\        ____/___|\____| ___|_| \_|  _|

*/
#include <cstdint> //para utilizar os tipos int8_t
#include <iostream> //Para utilizar o istream e ostream

class BigInt{

private:

     ///Atributos privados da classe BigInt:

        bool neg;

        int nDig;

        int8_t* d;

    ///Construtor específico

        BigInt(bool sinal, int numero);

    /// Método privado 
    void correct(BigInt &big);

public:

    ///Construtores públicos:

    BigInt(): neg(false), nDig(1), d(new int8_t[nDig]){
        d[0] = 0;
    }
    BigInt(long long int longInt);
    ///Construtores por cópia e movimento (necessários para alocação dinâmica de memória):

    BigInt(const BigInt &big);

    BigInt(BigInt &&big) noexcept;

    ///Atribuidores dos construtores:

    BigInt &operator=(const BigInt &big);

    BigInt &operator=(BigInt &&big) noexcept;


    ///Funções de consulta:

    bool isNeg() const{return neg;}

    int size() const{return nDig;}

    bool isZero() const;

    int8_t operator[](int i) const;

    ///Entrada e saída de dados:
    friend std::ostream &operator<<(std::ostream &os, const BigInt &big);
    friend std::istream &operator>>(std::istream &is, BigInt &big);

    ///Destrutor:

    ~BigInt();

};
#endif