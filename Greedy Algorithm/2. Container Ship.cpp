// ## Description of the problem

// There is a merchant ship whose capacity to load is K tons and a set of containers with their respective weights
// Design an algorithm to:
// -Maximize the number of containers: We will introduce the containers in a
// growing in weight.
// -Maximize the loaded weight: We will introduce the containers in a
// growing in weight.


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main()
{
  const int CAPACITY = 500;

  vector<int> weights;
  int weights_add = 0;
  int num_containers;

  for (int i = 0; i < 1000; i++)
  {
    weights.push_back( rand() % 100 + 1);
  }

  sort(weights.begin(), weights.end());

  int i = 0;
  bool continuo = true;

  while (continuo)
  {
    if (weights_add + weights[i] > CAPACITY)
      continuo = false;

    if (weights_add + weights[i] <= CAPACITY)
    {
      weights_add += weights[i];
      num_containers++;
      i++;
    }
  }


  cout << "\n\tMAXIMAZING CONTAINERS NUMBER WITH GREEDY" << endl;

  cout << "Number of inserted containers = " << num_containers << endl;
  cout << "Weight of our ship = " << weights_add << endl;

  /****************************************************************************/

  i = 999;
  continuo = true;
  num_containers = 0;
  weights_add = 0;


    while (continuo)
    {
      if (weights_add + weights[i] > CAPACITY)
        continuo = false;

      if (weights_add + weights[i] <= CAPACITY)
      {
        weights_add += weights[i];
        num_containers++;
        i--;
      }
    }

    cout << endl << "MAXIMIZING THE WEIGHT WITH GREEDY" << endl;

    cout << "Number of inserted containers =" << num_containers << endl;
    cout << "Weight of our ship =" << weights_add << endl;




  return 0;
}
