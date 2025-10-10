#include <iostream>
#include <string>
#include "planejador.h"

using namespace std;

int main()
{
  Planejador P;
  const string DIR="arq_teste/";
  string arq_pontos, arq_rotas;
  int I;

  // Leitura de arquivos validos
  cout << "Verifique se os arquivos corretos foram lidos e o numero de pontos e rotas eh igual\n";
  for (I=1; I<=3; ++I)
  {
    arq_pontos = DIR+"pontos_ok"+to_string(I)+".txt";
    arq_rotas = DIR+"rotas_ok"+to_string(I)+".txt";
    try
    {
      P.ler(arq_pontos,arq_rotas);
      cout << "OK! Arquivos " << I << " lidos "
           << " NumPontos=" << P.getNumPontos() << " NumRotas=" << P.getNumRotas() << endl;
    }
    catch(exception& E)
    {
      cerr << "ERRO na leitura do arquivo " << I << " - " << E.what() << endl;
    }
  }

  // Guarda as caracteristas do arquivo correto lido
  size_t num_pontos_anterior = P.getNumPontos();
  size_t num_rotas_anterior = P.getNumRotas();

  // Tentativa de leitura de arquivos de pontos invalidos
  cout << "\nVerifique se foi detectado erro nos arquivos incorretos de pontos e nao alterou conteudo anterior\n";
  arq_rotas = DIR+"rotas_ok1.txt";
  for (I=1; I<=10; ++I)
  {
    arq_pontos = DIR+"pontos_err"+to_string(I)+".txt";
    try
    {
      P.ler(arq_pontos,arq_rotas);
      cerr << "ERRO! Arquivo de pontos " << I << " lido, deveria indicar erro\n";
    }
    catch(exception& E)
    {
      if (P.getNumPontos()!=num_pontos_anterior || P.getNumRotas()!=num_rotas_anterior)
      {
        cerr << "ERRO! Arquivo de pontos " << I << " indicou corretamente um erro, mas o conteudo anterior foi alterado\n";
      }
      else
      {
        cout << "OK! Arquivo de pontos " << I << " indicou e tratou corretamente um erro - " << E.what() << endl;
      }
    }
  }

  // Tentativa de leitura de arquivos de rotas invalidos
  cout << "\nVerifique se foi detectado erro nos arquivos incorretos de rotas e nao alterou conteudo anterior\n";
  arq_pontos = DIR+"pontos_ok1.txt";
  for (I=1; I<=12; ++I)
  {
    arq_rotas = DIR+"rotas_err"+to_string(I)+".txt";
    try
    {
      P.ler(arq_pontos,arq_rotas);
      cerr << "ERRO! Arquivo de rotas " << I << " lido, deveria indicar erro\n";
    }
    catch(exception& E)
    {
      if (P.getNumPontos()!=num_pontos_anterior || P.getNumRotas()!=num_rotas_anterior)
      {
        cerr << "ERRO! Arquivo de rotas " << I << " indicou corretamente um erro, mas o conteudo anterior foi alterado\n";
      }
      else
      {
        cout << "OK! Arquivo de rotas " << I << " indicou e tratou corretamente um erro - " << E.what() << endl;
      }
    }
  }


  return 0;
}
