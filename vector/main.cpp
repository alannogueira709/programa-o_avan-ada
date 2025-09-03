#include <iostream>
#include "vetor.h"

using namespace std;

int main(void)
{
  Vetor V1(3), V2(3), V3;

  cout << "Entre um vetor (" << V1.size() << " elementos):\n";
  cin >> V1;

  V2.set(0, 1.2);
  V2.set(1, -3.14);
  V2.set(2, 0.333);

  cout << "O segundo vetor eh " << V2 << endl;

  cout << "Soma V1+V2 = " << V1+V2 << endl;
  cout << "Produto escalar V1.V2 = " << V1.escalar(V2) << endl;
  V3 = V1.vetorial(V2);
  cout << "Produto vetorial V1xV2 = " << V3 << endl;

  V3.push_back(13);
  V3.push_back(15);
  cout << "Vetor aumentado = " << V3 << endl;

  return 0;
}
