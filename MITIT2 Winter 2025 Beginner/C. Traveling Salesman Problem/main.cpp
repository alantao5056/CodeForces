#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    int N; cin >> N;

    int pi, pj; cin >> pi >> pj;
    int ii = pi; int ij = pj;
    ll res = 0;
    for (int i = 0; i < N-1; i++) {
      int ci, cj; cin >> ci >> cj;

      res += abs(pi-ci + pj-cj);
      pi = ci; pj = cj;
    }

    res += abs(ii-pi + ij - pj);
    cout << res << endl;
  }

  return 0;
}