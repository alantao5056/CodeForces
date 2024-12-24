#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> T;

  for (int t = 0; t < T; t++) {
    int l, r, i, k; cin >> l >> r >> i >> k;

    for (int j = l; j <= r; j++) {
      if ((j % (int)pow(2, i)) != (k % (int)pow(2, i))) {
        cout << j << endl;
      }
    }

    cout << endl << endl;
  }

  return 0;
}