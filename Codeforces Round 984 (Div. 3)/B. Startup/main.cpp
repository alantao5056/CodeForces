#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, K; cin >> N >> K;

    vector<int> brands(K);
    for (int j = 0; j < K; j++) {
      int b, c; cin >> b >> c; b--;
      brands[b] += c;
    }

    sort(brands.begin(), brands.end());
    ll ans = 0;
    for (int j = K-1; j > max(-1, K-1-N); j--) {
      ans += brands[j];
    }

    cout << ans << endl;
  }

  return 0;
}