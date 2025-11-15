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
    int mi = INT_MAX;
    int ma = INT_MIN;
    for (int i = 0; i < N; i++) {
      int x, y; cin >> x >> y;
      mi = min(mi, x+y);
      ma = max(ma, x+y);
    }

    cout << (2*(ma-mi)) << endl;
  }

  return 0;
}