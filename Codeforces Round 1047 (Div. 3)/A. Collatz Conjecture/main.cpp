#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T;
  cin >> T;
  
  while (T--) {
    ll k, x; cin >> k >> x;

    cout << ((ll)pow(2, k) * x) << endl;
  }

  return 0;
}