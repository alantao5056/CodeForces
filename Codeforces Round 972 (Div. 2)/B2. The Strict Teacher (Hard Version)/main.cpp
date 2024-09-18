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
    int M, N, Q; cin >> M >> N >> Q;
    vector<int> t(N);
    for (int j = 0; j < N; j++) {
      cin >> t[j];
    }

    sort(t.begin(), t.end());

    for (int j = 0; j < Q; j++) {
      int d; cin >> d;

      if (d < t[0]) {
        cout << t[0]-1 << endl;
        continue;
      }

      if (d > t[N-1]) {
        cout << M-t[N-1] << endl;
        continue;
      }

      int idx = (upper_bound(t.begin(), t.end(), d) - t.begin());
      cout << (t[idx] - t[idx-1]) / 2 << endl;
    }
  }

  return 0;
}