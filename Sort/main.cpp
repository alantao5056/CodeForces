#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, Q; cin >> N >> Q;
    string s1, s2; cin >> s1 >> s2;

    vector<vector<int>> pref1(26, vector<int>(N+1));
    vector<vector<int>> pref2(26, vector<int>(N+1));

    for (int j = 1; j <= N; j++) {
      int c1 = s1[j-1] - 'a';
      int c2 = s2[j-1] - 'a';

      pref1[c1][j] = 1;
      pref2[c2][j] = 1;

      for (int k = 0; k < 26; k++ ) {
        pref1[k][j] += pref1[k][j-1];
        pref2[k][j] += pref2[k][j-1];
      }
    }

    for (int j = 0; j < Q; j++) {
      int l, r; cin >> l >> r;

      int same = 0;

      for (int k = 0; k < 26; k++) {
        same += min(pref1[k][r] - pref1[k][l-1], pref2[k][r] - pref2[k][l-1]);
      }

      cout << ((r-l+1)-same) << endl;
    }
  }

  return 0;
}