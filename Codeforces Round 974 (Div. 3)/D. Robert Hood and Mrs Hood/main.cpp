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
    int N, D, K; cin >> N >> D >> K;

    vector<int> s(K);
    vector<int> e(K);
    for (int j = 0; j < K; j++) {
      int a, b; cin >> a >> b;
      s[j] = a;
      e[j] = b;
    }

    sort(s.begin(), s.end());
    sort(e.begin(), e.end());


    int active = 0;
    int si = 0;
    int ei = 0;
    for (int j = 1; j <= D; j++) {
      while (si < K && j == s[si]) {
        active++;
        si++;
      }
    }

    int maxA = active;
    int maxI = 1;
    int minA = active;
    int minI = 1;
    int l = 1;
    int r = D;
    while (r < N) {
      while (ei < K && e[ei] == l) {
        active--;
        ei++;
      }

      while (si < K && s[si] == r+1) {
        active++;
        si++;
      }

      if (active > maxA) {
        maxI = l+1;
        maxA = active;
      } else if (active < minA) {
        minI = l+1;
        minA = active;
      }

      l++;
      r++;
    }

    cout << maxI << " " << minI << endl;
  }

  return 0;
}