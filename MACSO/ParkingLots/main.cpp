#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int tot = N*M;
  cout << ((tot % 2) ? ((tot - 1)/2) : (tot/2)) << endl;

  return 0;
}