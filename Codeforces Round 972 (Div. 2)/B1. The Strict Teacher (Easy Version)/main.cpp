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
    int d, t1, t2; cin >> t1 >> t2 >> d;
    if (t1 > t2) swap(t1, t2);
    if (d > t1 && d < t2) {
      cout << (t2-t1)/2 << endl;
    } else if (d < t1) {
      cout << t1-1 << endl;
    } else {
      cout << M-t2 << endl;
    }
  }

  return 0;
}