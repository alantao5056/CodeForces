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
    ll a, b; cin >> a >> b;

    if (a%2 == 1 && b % 2 == 1) {
      cout << (a*b+1) << endl;
      continue;
    }
    if (a%2 == 1 && b%2 == 0) {
      if (b%4 != 0) {
        cout << -1 << endl;
        continue;
      }

      cout << (a * (b/2) + 2) << endl;;
      continue;
    }

    if (a%2 == 0 && b%2 == 1) {
      cout << -1 << endl;
      continue;
    }

    cout << (a*(b/2)+2) << endl;
  }

  return 0;
}