 /*
                                                                                                     
                      _/_/_/_/                                                                       
                     _/        _/  _/_/  _/  _/_/    _/_/      _/_/_/        _/_/    _/_/_/  _/_/    
                    _/_/_/    _/_/      _/_/      _/    _/  _/_/          _/_/_/_/  _/    _/    _/   
                   _/        _/        _/        _/    _/      _/_/      _/        _/    _/    _/    
                  _/_/_/_/  _/        _/          _/_/    _/_/_/          _/_/_/  _/    _/    _/     
                                                                                                     
                                                                                                     
                                                                                                         
                                                     _/                _/                                
                    _/_/_/      _/_/    _/_/_/    _/_/_/_/    _/_/        _/  _/_/    _/_/      _/_/_/   
                   _/    _/  _/    _/  _/    _/    _/      _/_/_/_/  _/  _/_/      _/    _/  _/_/        
                  _/    _/  _/    _/  _/    _/    _/      _/        _/  _/        _/    _/      _/_/     
                 _/_/_/      _/_/    _/    _/      _/_/    _/_/_/  _/  _/          _/_/    _/_/_/        
                _/                                                                                      

*/

/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 1 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 

#include <iostream>
#include <cmath>


using namespace std;

// Calcula a raiz quadrada de um numero inteiro
int main(void)
{
  int N;
  double* x = nullptr;

  do
  {
    cout << "Numero [>0]? ";
    cin >> N;
  } while (N<=0);

  *x = sqrt(N);
  cout << "Raiz = " << *x << endl;

  return 0;
}
#############################################################################
1) Correção:

    O código acima tem um erro de ponteiro a variável x é inicializada como 
    nullptr mas não existe alocação de memória então, ao calcular a raiz 
    quadrada da entrada do usuário, o programa pode apresentar comportamento
    inesperado. Uma solução possível seria:

    #include <iostream>
    #include <cmath>
    using namespace std;
    int main(void)
    {
    int N;
    double* x = nullptr;
    x = new double;

    do
    {
        cout << "Numero [>0]? ";
        cin >> N;
    } while (N<=0);

    *x = sqrt(N);
    cout << "Raiz = " << *x << endl;

    delete x;
    return 0;
    }

    Agora a memória é devidamente alocada para o ponteiro x e após o uso a 
    memória é liberada através do comando delete.

#############################################################################
*/


/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 2 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 

#include <iostream>



using namespace std;


int main(void)
{
  int N,i;
  double* x;

  do
  {
    cout << "Ateh qual termo [>=2]? ";
    cin >> N;
  } while (N<2);

  x = new double[N];
  for (i=0; i<=N; ++i)
  {
    if (i<2) x[i] = 1.0;
    else x[i] = x[i-1]+x[i-2];
  }
  cout << "Serie = ";
  for (i=0; i<=N; ++i) cout << x[i] << ' ';
  cout << endl;

  delete[] x;

  return 0;
}
#############################################################################
2) Correção:

    Não há erro nesse código, ele aloca memória para um vetor de ponteiros
    e calcula a série de Fibonacci até o termo N, imprimindo o resultado.
    A memória é liberada corretamente no final do programa com o comando delete[].

#############################################################################
*/

/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 3 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 



#include <iostream>

using namespace std;

// Gera uma serie de 5 elementos onde cada elemento indice "i" (i de 0 a 4)
// eh a media de "i+1" valores digitados
int main(void)
{
  const int N=5;
  int i,j;
  double* x;

  x = new double[N];
  for (i=0; i<N; ++i)
  {
    cout << "Digite " << i+1 << " valores: ";
    {
      double* prov = new double[i+1];
      for (j=0; j<i+1; ++j) cin >> prov[j];
      double soma=0.0;
      for (j=0; j<i+1; ++j) soma += prov[j];
      x[i] = soma/(i+1);
    }
  }
  cout << "Serie = ";
  for (i=0; i<N; ++i) cout << x[i] << ' ';
  cout << endl;

  delete[] x;

  return 0;
}

#############################################################################
3) Correção:

    O erro desse código está no fato de que o prov, o ponteiro provisório para 
    armazenar os valores do usuário em um vetor maior do que o estipulado é 
    corretamente alocado, porém não há a liberação de memória após o uso levando
    a vazamento de memória. Uma sugestão de melhoria seria:  


        #include <iostream>

        using namespace std;

        // Gera uma serie de 5 elementos onde cada elemento indice "i" (i de 0 a 4)
        // eh a media de "i+1" valores digitados
        int main(void)
        {
        const int N=5;
        int i,j;
        double* x;

        x = new double[N];
        for (i=0; i<N; ++i)
        {
            cout << "Digite " << i+1 << " valores: ";
            {
            double* prov = new double[i+1];
            for (j=0; j<i+1; ++j) cin >> prov[j];
            double soma=0.0;
            for (j=0; j<i+1; ++j) soma += prov[j];
            x[i] = soma/(i+1);

            delete[] prov;
            }
        }
        cout << "Serie = ";
        for (i=0; i<N; ++i) cout << x[i] << ' ';
        cout << endl;

        delete[] x;

        return 0;
        }

#############################################################################
*/


/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 4 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 



#include <iostream>
#include <ctime>



using namespace std;

// Gera N (>=2) numeros aleatorios entre 0 e N-1
int main(void)
{
  int N, i;
  int* numeros;

  srand(time(nullptr));

  do
  {
    cout << "Quantos numeros [>=2]? ";
    cin >> N;
  } while (N<2);

  numeros = new int[N];
  for (i=0; i<N; ++i)
  {
    numeros[i] = rand()%N;
  }

  cout << "Numeros = ";
  for (i=0; i<N; ++i) cout << numeros[i] << ' ';
  cout << endl;

  delete numeros;

  return 0;
}

#############################################################################
4) Correção:

    O único erro desse código é que o ponteiro numeros é alocado dinamicamente
    como um array e aao tentar liberar a memória o programa utiliza "delete numeros"
    ao invés de "delete[] numeros".

#############################################################################
*/

/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 5 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 


#include <iostream>
#include <ctime>


using namespace std;


int main(void)
{
  int N=0;
  char* cadeia = new char[N+1];
  char opcao;

  cadeia[N] = '\0'; // Ultima posicao tem que ser \0

  do
  {
    cout << "Cadeia atual = " << cadeia << endl;
    cout << "Proximo caractere [X para terminar]: ";
    cin >> opcao;
    if (opcao != 'X')
    {
      char* prov = new char[N+2];
      for (int i=0; i<N; ++i) prov[i] = cadeia[i]; // Copia os N caracteres
      prov[N] = opcao; // Acrescenta o caractere digitado na penultima posicao
      N++;
      prov[N] = '\0';  // Ultima posicao tem que ser \0
      delete[] cadeia;
      cadeia = prov;
    }
  } while (opcao!='X');

  delete[] cadeia;

  return 0;
}

#############################################################################
5) Correção:

    Não existem erros de ponteiros, nem de alocação dinâmica de memória nesse 
    código, ele cria o array de chars cadeia, aloca a memória e cria outro 
    ponteiro para armazenar os chars e usa um espaço a mais para representar o 
    \0 no final da string. A memória é liberada corretamente no final do
    programa com o comando delete[].

#############################################################################
*/

/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 6 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 




#include <iostream>



using namespace std;

// Gera os N primeiros termos da serie de Fibonacci (N >= 0)
// Os 2 primeiros sao 1, os demais sao a soma dos 2 anteriores
int main(void)
{
  int N,i;
  double* x;

  do
  {
    cout << "Quantos numeros [>=0]? ";
    cin >> N;
  } while (N<0);

  x = new double[N];
  for (i=0; i<N; ++i)
  {
    if (i<2) x[i] = 1.0;
    else x[i] = x[i-1]+x[i-2];
  }
  cout << "Serie = ";
  for (i=0; i<N; ++i) cout << x[i] << ' ';
  cout << endl;

  delete[] x;

  return 0;
}

#############################################################################
6) Correção:

    Não existem erros de ponteiros nesse código nem de memória alocada dinami-
    camente.

#############################################################################
*/



/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 7 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 


#include <iostream>


using namespace std;

// Solicita ao usuario a digitacao de N numeros (N>=3) e armazena em "orig"
// Em seguida, calcula nova serie "media", na qual os elementos da extremidade
// de "media" sao iguais aos elementos correspondentes em "orig" e
// os demais elementos de "media" sao a media de 3 elementos em "orig": o
// correpondente, o anterior e o seguinte.
int main(void)
{
  int N,i;
  double *orig, *media;

  do
  {
    cout << "Quantos numeros [>=3]? ";
    cin >> N;
  } while (N<3);

  orig = new double[N];
  for (i=0; i<N; ++i)
  {
    cout << "Elemento indice " << i << ": ";
    cin >> orig[i];
  }

  media = orig;
  // Calcula apenas os elementos que nao sao das extremidades (de 1 a N-2)
  for (i=1; i<N-1; ++i)
  {
    media[i] = (orig[i-1]+orig[i]+orig[i+1])/3.0;
  }

  cout << "Media = ";
  for (i=0; i<N; ++i) cout << media[i] << ' ';
  cout << endl;

  delete[] orig;
  delete[] media;

  return 0;
}
#############################################################################
7) Correção:
    Os ponteiros são atribuidos corretamente e alocados de forma certa, porém 
    ao deletá-los há dois deletes seguidos o que faz com que o primeiro delete 
    apague também o endereço de memória do segundo o que pode causar compor-
    tamentos indefinidos no código.
    

#############################################################################
*/


/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 8 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 

#include <iostream>
#include <ctime>


using namespace std;

// Gera cadeias de caracteres aleatorios de tamanho crescente
// A cadeia aumenta de tamanho ateh que o usuario decida parar
int main(void)
{
  int N=0, i;
  char *cadeia = nullptr, opcao;

  srand(time(nullptr));

  do
  {
    N++;
    cadeia = new char[N+1]; // Um char a mais (N+1) para conter o \0 final
    for (i=0; i<N; ++i) cadeia[i] = 'A' + rand()%26;  // Gera de 'A' a 'Z'
    cadeia[N] = '\0';
    cout << "Cadeia = " << cadeia << endl;
    do
    {
      cout << "Deseja continuar [S/N]? ";
      cin >> opcao;
      opcao = toupper(opcao);
    } while (opcao!='S' && opcao!='N');
  } while (opcao=='S');

  delete[] cadeia;

  return 0;
}

#############################################################################
8) Correção:
    O código tem um problema relacionado a alocação de memória do ponteiro 
    cadeia pois quando o usuário deseja gerar mais caracteres na cadeia, o pro
    grama aloca mais memória e o endereço de memória anterior não é liberado
    ocasionando no programa consumindo mais memória que o necessário. 
#############################################################################
*/

/*

                        _   _   _   _   _   _   _     _  
                       / \ / \ / \ / \ / \ / \ / \   / \ 
                      ( Q | u | e | s | t | a | o ) ( 9 )
                       \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ 
#include <iostream>
#include <ctime>

using namespace std;


int main(void)
{
  int N=0;
  int* cadeia = nullptr;
  int i;
  char opcao;

  srand(time(nullptr));

  do
  {
    {
      int* prov = new int[N+1];
      for (i=0; i<N; ++i) prov[i] = cadeia[i]; // Copia os N inteiros
      prov[N] = rand()%10;  // Gera de 0 a 9 no ultimo
      N++;
      cadeia = prov;
      delete[] prov;
    }
    cout << "Cadeia = ";
    for (i=0; i<N; i++) cout << cadeia[i];
    cout << endl;
    do
    {
      cout << "Deseja continuar [S/N]? ";
      cin >> opcao;
      opcao = toupper(opcao);
    } while (opcao!='S' && opcao!='N');
  } while (opcao=='S');

  delete[] cadeia;

  return 0;
}

#############################################################################
9) Correção:
    O programa acima contém um erro que é o fato de que na linha 30(515 aqui)
    ocorre que cadeia recebe o mesmo endereço de memória de prov que logo em 
    seguida é LIBERADO... logo não teria um endereço de memória para alocar a
    nova cadeia de inteiros resultando em comportamentos inesperados.

#############################################################################
*/