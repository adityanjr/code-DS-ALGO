#include <iostream>

using namespace std;

int
main ()
{
  long long int t, T;
  cin >> T;
  for (t = 0; t < T; t++)
    {
      long long int a, b, x, y, n;
      cin >> a >> b >> x >> y >> n;
      long long int k=a-x, l=b-y, m=n;
      long long int a1=a, b1=b, A=0, B=0;

	  long long int p = min (k, n);
	  a -= p;
	  n -= p;
	  long long int q = min (l, n);
	  b -= q;
	  n -= q;
	  A = a * b;

	  long long int r = min (l, m);
	  b1 -= r;
	  m -= r;
	  long long int s = min (k, m);
	  a1 -= s;
	  m -= s;
	  B = a1 * b1;

	  cout << min (A, B) << endl;

    }
}
