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
    int odds = (K)/2;
    if (K %2 != 0) {
      if (N%2 != 0) {
        odds++;
      }
    }
    if (odds % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}