#include <cmath>
#include <iostream>// dupla inlcusao

#include "vector.h"

using namespace std;

Vetor::Vetor(const &V): N(V.N), x=nullptr{
    if (N>0) x = new double[N];
    for (int i=0; i<N; ++i) x[i] = V.x[i];
}

Vetor::Vetor(Vetor&& V) noexcept: N(V.N), x(V.x){
  V.N = 0;;
  V.x = nullptr;
}
/*
tambem pode ser feito desta forma:


Vetor::Vetor(Vetor&& V) noexcept: N(0), x=nullptr{
  swap(N,V.N);
  swap(x,V.x);
}

*/

Vetor::Vetor(int Num): N(Num), x(nullptr)
{
  //construtor com um parametro, cria um vetor com dimensao N de entrada do usuario com todos os elementos 0.0
  if (N<0) N=0;
  else if (N>0) x = new double[N](0.0);
}
//destrutor default
Vetor::~Vetor() {
    delete[] x;
}

void Vetor::set(int i, double valor)
{
  if (i<0 || i>=N)
  {
    cerr << "Indice invalido\n";
    return; //encerra a função
  }
  x[i]=valor; //atribui o valor de entrada a sua respectiva posição
}

Vetor& Vetor::operator=(const Vetor& V)
{
  /// Primeiro, testa se o usuario nao estah fazendo uma atribuicao redundante, tal como A=A
  /// Soh faz alguma coisa se nao for esse tipo de situacao absurda
  if (this == &V) return *this;
  /// Caso as dimensoes sejam diferentes, desaloca a area anterior e aloca uma nova area
  if (this->N != V.N)
  {
    delete[] x;
    N = V.N;
    if (N>0) x = new double[N];
    else x = nullptr;
  }
  /// Copia os valores dos elementos
  for (int i=0; i<N; ++i) x[i] = V.x[i];
  return *this;
}

/// Operador de atribuicao por movimento
/// (necessario jah que a classe envolve alocacao de memoria)
Vetor& Vetor::operator=(Vetor&& V) noexcept
{
  // Libera conteudo anterior
  delete[] x;
  // Move o conteudo
  N = V.N;
  x = V.x;
  // Zera o Vetor provisorio
  V.N = 0;
  V.x = nullptr;

  return *this;
}
/// Alternativa:
/*
Vetor& Vetor::operator=(Vetor&& V) noexcept
{
  // Libera memoria e zera conteudo anterior
  delete[] x;
  N = 0;
  x = nullptr;
  // Permuta o conteudo
  swap(N,V.N);
  swap(x,V.x);

  return *this;
}
*/

/// Metodo de consulta que retorna o valor de um elemento do vetor
double Vetor::operator[](int i) const
{
  if (i<0 || i>=N)
  {
    cerr << "Indice invalido\n";
    return 0.0;
  }
  return x[i];
}

/// Metodo de alteracao de valor de um elemento do vetor
void Vetor::set(int i, double valor)
{
  if (i<0 || i>=N)
  {
    cerr << "Indice invalido\n";
    return;
  }
  x[i]=valor;
}

/// Acrescenta um elemento ao final do vetor (aumenta de tamanho)
void Vetor::push_back(double valor)
{
  // Cria um Vetor provisorio com N+1 elementos
  // (Passos 1 e 2 do algoritmo classico para fazer um array dinamico "aumentar"
  // de tamanho: ver resumo sobre ponteiros)
  Vetor prov(N+1);
  // Copia todos os elementos do Vetor antigo para o novo (Passo 3)
  // Se N==0, nao entra nenhuma vez no for e nao copia nada
  for (int i=0; i<N; ++i) prov.x[i]=x[i];
  // Copia o novo valor para o final do Vetor novo (Passo 4)
  prov.x[N]=valor;
  // Atribui o novo Vetor ao antigo usando op= por movimento (passos 5, 6 e 7):
  *this = prov;
}

/// As funcoes que implementam os operadores de entrada e saida de dados
/// Como nao sao metodos da classe (sao funcoes), mas precisam acessar dados
/// privados da classe, sao declaradas como friend

ostream& operator<<(ostream& X, const Vetor& V)
{
  X << '[';
  for (int i=0; i<V.N; ++i)
  {
    X << V.x[i];
    if (i<V.N-1) X << ';';
  }
  X << ']';
  return X;
}

istream& operator>>(istream& X, Vetor& V)
{
  for (int i=0; i<V.N; ++i) X >> V.x[i];
  return X;
}

/// Soma de vetores
Vetor Vetor::operator+(const Vetor& V) const
{
  if (N!=V.N)
  {
    cerr << "Dimensoes incompativeis\n";
    return Vetor();
  }
  Vetor prov(N);
  for (int i=0; i<N; ++i) prov.x[i] = x[i] + V.x[i];
  return prov;
}

/// Subtracao de vetores (- binario)
Vetor Vetor::operator-(const Vetor& V) const
{
  if (N!=V.N)
  {
    cerr << "Dimensoes incompativeis\n";
    return Vetor();
  }
  Vetor prov(N);
  for (int i=0; i<N; ++i) prov.x[i] = x[i] - V.x[i];
  return prov;
}

/// Negativo de um vetor (- unario)
Vetor Vetor::operator-() const
{
  Vetor prov(N);
  for (int i=0; i<N; ++i) prov.x[i] = -x[i];
  return prov;
}

/// Norma euclidiana de um vetor
double Vetor::norma() const
{
  double soma(0.0);
  for (int i=0; i<N; ++i) soma += x[i]*x[i];
  return sqrt(soma);
}

/// Produto escalar
double Vetor::escalar(const Vetor& V) const
{
  if (N!=V.N)
  {
    cerr << "Dimensoes incompativeis\n";
    return 0.0;
  }
  double prov(0.0);
  for (int i=0; i<N; ++i) prov += x[i]*V.x[i];
  return prov;
}

/// Produto vetorial (apenas para vetores de dimensao 3)
Vetor Vetor::vetorial(const Vetor& V) const
{
  if (N!=3 || N!=V.N)
  {
    cerr << "Dimensoes incompativeis\n";
    return Vetor();
  }
  Vetor prov(3);
  prov.x[0] = x[1]*V.x[2] - x[2]*V.x[1];
  prov.x[1] = x[2]*V.x[0] - x[0]*V.x[2];
  prov.x[2] = x[0]*V.x[1] - x[1]*V.x[0];
  return prov;
}

