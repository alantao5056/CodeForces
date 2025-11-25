#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int gcd(int a, int b) {
  int res = min(a, b);
  while (res > 1) {
    if (a % res == 0 && b % res == 0)
      break;
    res--;
  }
	return res;
}


int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    int N; cin >> N;
    map<pair<int, int>, int> m;
    vector<pii> people(N);
    for (int i = 0; i < N; i++) {
      int x, y, u, v; cin >> x >> y >> u >> v;

      int dy = v-y;
      int dx = u-x;
      int g = gcd(dy, dx);
      dy /= g; dx /= g;

      pii k = {dy, dx};
      people[i] = k;
      m[k] = i;
    }

    ll res = 0;
    for (auto const& [key, val] : m) {
      res += val * m[{key.first, -key.second}];
    }
    cout << (res/2) << endl;
  }

  return 0;
}