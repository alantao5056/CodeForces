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
    int N; cin >> N;
    int prev = -1;
    int works = true;
    for (int i = 0; i < N; i++) {
      int cur; cin >> cur;
      if (prev != -1 && abs(cur-prev) != 5 && abs(cur-prev) != 7) {
        works = false;
      }
      prev = cur;
    }

    cout << (works ? "YES" : "NO") << endl;
  }

  return 0;
}