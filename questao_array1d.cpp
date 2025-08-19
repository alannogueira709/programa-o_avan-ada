/*
          __  __          _ _                                         
         |  \/  |        | (_)      _      /\                         
         | \  / | ___  __| |_  __ _(_)    /  \   _ __ _ __ __ _ _   _ 
         | |\/| |/ _ \/ _` | |/ _` |     / /\ \ | '__| '__/ _` | | | |
         | |  | |  __/ (_| | | (_| |_   / ____ \| |  | | | (_| | |_| |
         |_|  |_|\___|\__,_|_|\__,_(_) /_/    \_\_|  |_|  \__,_|\__, |
                                                                 __/ |
                                                                |___/ 
                   _____  _                       _           
                  |  __ \(_)                     (_)          
                  | |  | |_ _ __   __ _ _ __ ___  _  ___ ___  
                  | |  | | | '_ \ / _` | '_ ` _ \| |/ __/ _ \ 
                  | |__| | | | | | (_| | | | | | | | (_| (_) |
                  |_____/|_|_| |_|\__,_|_| |_| |_|_|\___\___/ 
                                                              
                                                              

*/

#include <iostream>

using namespace std;

int main()
{
  float * arr = nullptr;
  int N=0;              // Dimensao do array; inicialmente igual a zero
  float Num;            // O numero digitado
  int i;                // Um contador

  do
  {
    cout << "Digite um numero [0.0 para parar]: ";
    cin >> Num;
    if (Num != 0.0)
    {
      float * prov = new float[N+1];
      for(i=0; i<N;i++) prov[i] = arr[i];
      prov[N]= Num;
      delete[] arr;
      arr = prov;
      N++;
    }
  }
  while (Num != 0.0);

  if (N==0)
  {
    cout << "Voce nao digitou nenhum numero!!!\n";
    return 0;
  }

  // Calculo da media, numeros acima e abaixo da media
  float soma = 0.0, media;
  int num_acima=0, num_abaixo=0;

  for (i=0; i<N; ++i) soma += arr[i];
  media = soma/N;
  for (i=0; i<N; ++i)
  {
    if (arr[i] > media) num_acima++;
    if (arr[i] < media) num_abaixo++;
  }

  cout << "Os numeros digitados:";
  for (i=0; i<N; ++i) cout << ' ' << arr[i];
  cout << endl;
  cout << "A media eh: " << media << endl;
  cout << "Acima da media: " << num_acima << endl;
  cout << "Abaixo da media: " << num_abaixo << endl;

  delete[] arr;


  return 0;
}