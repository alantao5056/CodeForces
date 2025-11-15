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

  int T;
  cin >> T;
  while (T--) {
    int N; cin >> N;
    int k = 1;
    for (; k < 13; k++) {
      if (N <= pow(5, k)) break;
    }

    if (k == 1) {
      cout << "MIT time" << endl;
    } else {
      cout << "MIT" <<  "^" << k << " time" << endl;
    }
  }

  return 0;
}