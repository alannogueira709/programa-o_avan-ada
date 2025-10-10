#include <stdexcept>
#include <cmath>
#include <fstream>
#include <limits>
#include <algorithm>
#include <list>

#include "planejador.h"

using namespace std;

/* *************************
   * CLASSE IDPONTO        *
   ************************* */

/// Atribuicao de string
void IDPonto::set(string&& S)
{
  t=move(S);
  if (!valid()) t.clear();
}

/* *************************
   * CLASSE IDROTA         *
   ************************* */

/// Atribuicao de string
void IDRota::set(string&& S)
{
  t=move(S);
  if (!valid()) t.clear();
}

/* *************************
   * CLASSE PONTO          *
   ************************* */

/// Impressao em console
ostream& operator<<(ostream& X, const Ponto& P)
{
  X << P.id << '\t' << P.nome << " (" <<P.latitude << ',' << P.longitude << ')';
  return X;
}

/// Distancia entre 2 pontos (formula de haversine)
double Ponto::distancia(const Ponto& P) const
{
  // Gera excecao se pontos invalidos
  if (!valid() || !P.valid())
    throw invalid_argument("distancia: ponto(s) invalido(s)");

  // Tratar logo pontos identicos
  if (id == P.id) return 0.0;
  // Constantes
  static const double MY_PI = 3.14159265358979323846;
  static const double R_EARTH = 6371.0;
  // Conversao para radianos
  double lat1 = MY_PI*this->latitude/180.0;
  double lat2 = MY_PI*P.latitude/180.0;
  double lon1 = MY_PI*this->longitude/180.0;
  double lon2 = MY_PI*P.longitude/180.0;
  // Seno das diferencas
  double sin_dlat2 = sin((lat2-lat1)/2.0);
  double sin_dlon2 = sin((lon2-lon1)/2.0);
  // Quadrado do seno do angulo entre os pontos
  double sin2_ang = sin_dlat2*sin_dlat2 + cos(lat1)*cos(lat2)*sin_dlon2*sin_dlon2;
  // Em vez de utilizar a funcao arcosseno, asin(sqrt(sin2_ang)),
  // vou utilizar a funcao arcotangente, menos sensivel a erros numericos.
  // Distancia entre os pontos
  return 2.0*R_EARTH*atan2(sqrt(sin2_ang),sqrt(1-sin2_ang));
}

/* *************************
   * CLASSE ROTA           *
   ************************* */

/// Impressao em console
ostream& operator<<(ostream& X, const Rota& R)
{
  X << R.id << '\t' << R.nome << '\t' << R.comprimento << "km"
    << " [" << R.extremidade[0] << ',' << R.extremidade[1] << ']';
  return X;
}

/// Retorna a outra extremidade da rota, a que nao eh o parametro.
/// Gera excecao se o parametro nao for uma das extremidades da rota.
IDPonto Rota::outraExtremidade(const IDPonto& ID) const
{
  if (extremidade[0]==ID) return extremidade[1];
  if (extremidade[1]==ID) return extremidade[0];
  throw invalid_argument("outraExtremidade: invalid IDPonto parameter");
}

/* *************************
   * CLASSE PLANEJADOR     *
   ************************* */

/// Torna o mapa vazio
void Planejador::clear(){
  pontos.clear();
  rotas.clear();
}

/// Leh um mapa dos arquivos arq_pontos e arq_rotas.
/// Caso nao consiga ler dos arquivos, deixa o mapa inalterado e gera excecao ios_base::failure.
void Planejador::ler(const std::string& arq_pontos,
                     const std::string& arq_rotas)
{
  // Vetores temporarios para armazenamento dos Pontos e Rotas lidos.
 
  list<Ponto> listPontos;
  list<Rota> listRotas;

  list<Ponto>::iterator itr_Ponto;
  list<Rota>::iterator itr_Rota;

  try
  {
    string cabecalho;

    ifstream arq(arq_pontos);
    if (!arq.is_open()) throw 1;
    
    getline(arq, cabecalho);

    if (cabecalho != "ID;Nome;Latitude;Longitude" || arq.fail()) throw 2;

  do
  {
  Ponto ponto;
  
  arq >> ws;

  getline(arq, cabecalho, ';');
  if(arq.fail()) throw 3;

  ponto.id.set(move(cabecalho));
  if(!ponto.id.valid()) throw 4;

  getline(arq, cabecalho, ';');
  if(arq.fail() || cabecalho.size()<2) throw 5;

  ponto.nome = move(cabecalho);

  arq >> ponto.latitude;
  if(arq.fail()) throw 6;

  arq.ignore(1,';');

  arq >> ponto.longitude;
  if(arq.fail()) throw 7;

  auto itr_idPonto = find(listPontos.begin(), listPontos.end(), ponto.id);
  if(itr_idPonto == listPontos.end()) throw 8;

  listPontos.push_back(move(ponto));

  } while (!arq.eof());
    arq.close();
  }
  catch(int i)
  {
    string msg_err = "Erro " + to_string(i) + " na leitura do arquivo de pontos " + arq_pontos;
    throw ios_base::failure(msg_err);
  }
  
try
{
  string cabecalho;

  
  ifstream arq(arq_rotas);  // Use ifstream em vez de fstream para leitura
  if(!arq.is_open()) throw 1;

  
  getline(arq, cabecalho);
  if(cabecalho.back() == '\r') cabecalho.pop_back(); // Remove \r se existir
  if(arq.fail() || cabecalho != "ID;Nome;Extremidade 1;Extremidade 2;Comprimento") throw 2;

  
  do {
    arq >> ws; 
    if(arq.eof()) break; 
    
    Rota rota;
    string cabecalho;

    getline(arq, cabecalho , ';');
    if(arq.fail()) throw 3;

    rota.id.set(move(cabecalho));

    getline(arq, cabecalho, ';');
    getline(arq, cabecalho, ';');
    if(arq.fail()) throw 4;

    rota.nome = move(cabecalho);

    getline(arq, cabecalho, ';');
    if(arq.fail()) throw 5;

    rota.extremidade[0].set(move(cabecalho));


    getline(arq, cabecalho, ';');
    if(arq.fail()) throw 6;
    
    rota.extremidade[1].set(move(cabecalho));

    
    arq >> rota.comprimento;
    if(arq.fail()) throw 7;

    arq >> ws;

    if(!rota.valid()) throw 8;

    auto itr_idPonto1 = find(listPontos.begin(), listPontos.end(), rota.extremidade[0]);
    if(itr_idPonto1 == listPontos.end()) throw 9;

    auto itr_idPonto2 = find(listPontos.begin(), listPontos.end(), rota.extremidade[1]);
    if(itr_idPonto2 == listPontos.end()) throw 10;

    auto itr_rota = find(listRotas.begin(), listRotas.end(), rota.id);
    if(itr_rota != listRotas.end()) throw 11;

    listRotas.push_back(move(rota));


  } while (!arq.eof());

  arq.close();
}
catch(int i)
{
  string msg_err = "Erro " + to_string(i) + " na leitura do arquivo de rotas " + arq_rotas;
  throw ios_base::failure(msg_err);
}
  pontos.resize(listPontos.size());
  rotas.resize(listRotas.size());

  copy(listPontos.begin(), listPontos.end(), pontos.begin());
  copy(listRotas.begin(), listRotas.end(), rotas.begin());
}
/// Retorna um Ponto do mapa, passando a id como parametro.
/// Se a id for inexistente, gera excecao.
/// Deve receber ACRESCIMOS
Ponto Planejador::getPonto(const IDPonto& Id) const
{
  // Procura um ponto que corresponde aa Id do parametro
  auto iter = find(pontos.begin(), pontos.end(), Id);
  if(iter != pontos.end()) return *iter; 

  throw invalid_argument("getPonto: invalid IDPonto parameter");
}

/// Retorna um Rota do mapa, passando a id como parametro.
/// Se a id for inexistente, gera excecao.
/// Deve receber ACRESCIMOS
Rota Planejador::getRota(const IDRota& Id) const
{
  // Procura uma rota que corresponde aa Id do parametro
  /* ***********  /
  /  FALTA FAZER  /
  /  *********** */
  // Em caso de sucesso, retorna a rota encontrada
  /* ***********  /
  /  FALTA FAZER  /
  /  *********** */
  // Se nao encontrou, gera excecao
  throw invalid_argument("getRota: invalid IDRota parameter");
}

/// *******************************************************************************
/// Calcula o caminho entre a origem e o destino do planejador usando o algoritmo A*
/// *******************************************************************************

/// Noh: os elementos dos conjuntos de busca do algoritmo A*.
/// Deve ser DECLARADA E IMPLEMENTADA inteiramente.
/* ***********  /
/  FALTA FAZER  /
/  *********** */

/// Calcula o caminho mais curto no mapa entre origem e destino, usando o algoritmo A*
/// Retorna o comprimento do caminho encontrado (<0 se nao existe caminho).
/// O parametro C retorna o caminho encontrado (vazio se nao existe caminho).
/// O parametro NumAberto retorna o numero de nos (>=0) em Aberto ao termino do algoritmo A*,
/// mesmo quando nao existe caminho.
/// O parametro NumFechado retorna o numero de nos (>=0) em Fechado ao termino do algoritmo A*,
/// mesmo quando nao existe caminho.
/// Em caso de parametros de entrada invalidos ou de erro no algoritmo, gera excecao.
/// Deve receber ACRESCIMOS.
double Planejador::calculaCaminho(const IDPonto& id_origem,
                                  const IDPonto& id_destino,
                                  Caminho& C, int& NumAberto, int& NumFechado)
{
  try
  {
    // Mapa vazio
    if (empty()) throw 1;

    Ponto pt_origem, pt_destino;
    // Calcula os pontos que correspondem a id_origem e id_destino.
    // Se algum nao existir, throw 2
    try
    {
      pt_origem = getPonto(id_origem);
      pt_destino = getPonto(id_destino);
    }
    catch(...)
    {
      throw 2;
    }

    /* *****************************  /
    /  IMPLEMENTACAO DO ALGORITMO A*  /
    /  ***************************** */

    /* ***********  /
    /  FALTA FAZER  /
    /  *********** */

    // Substitua pelo caminho correto
    C = Caminho();

    // Substitua pelo valor correto
    return -1.0;
  }
  catch(int i)
  {
    string msg_err = "Erro " + to_string(i) + " no calculo do caminho\n";
    throw invalid_argument(msg_err);
  }

  // Zera o caminho resultado em caso de erro
  C = Caminho();

  // Retorna -1 em caso de erro
  return -1.0;
}
