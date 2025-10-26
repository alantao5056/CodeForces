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

  int N, K;
  cin >> N >> K;

  int zero = 0;
  int cnt = 0;
  bool allHalf = (K/2 == 0);

  for (int i = 0; i < N; i++) {
    int cur; cin >> cur; cur = cur%K;
    if (cur == 0) {
      zero++;
    } else {
      if (cur != K/2) {
        allHalf = false;
      }
      cnt++;
    }
  }

  if (cnt == 2) {
    cout << "Rob" << endl;
    return 0;
  }

  if (cnt == 0) {
    cout << "Gabe" << endl;
    return 0;
  }

  bool iwin = true;
  if (allHalf) {
    if (cnt % 4 == 0) {
      // even number of pairs
      iwin = false;
    }
  } else if (cnt % 2 == 1) {
    iwin = false;
  }

  if ((zero%2)^((int)iwin)) {
    cout << "Rob" << endl;
  } else {
    cout << "Gabe" << endl;
  }

  return 0;
}