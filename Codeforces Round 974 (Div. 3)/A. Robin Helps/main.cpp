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

    int gold = 0;
    int ans = 0;
    for (int j = 0; j < N; j++) {
      int cur; cin >> cur;
      if (cur >= K) {
        gold += cur;
      } else if (cur == 0 && gold > 0) {
        ans++;
        gold--;
      }
    }

    cout << ans << endl;
  }

  return 0;
}