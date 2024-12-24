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
    string s; cin >> s;
    int N = s.size();
    int Q; cin >> Q;

    set<int> goods;

    for (int j = 0; j < N-3; j++) {
      string ss = "";
      for (int k = j; k < j+4; k++) {
        ss += s[k];
      }

      if (ss == "1100") {
        goods.insert(j);
      }
    }

    for (int j = 0; j < Q; j++) {
      int idx; char v; cin >> idx >> v; idx--;
      s[idx] = v;
      for (int k = max(0, idx-3); k <= idx; k++) {
        string ss = "";
        for (int l = k; l < min(k+4, N); l++) {
          ss += s[l];
        }

        if (ss == "1100" && goods.find(k) == goods.end()) {
          goods.insert(k);
        } else if (ss != "1100" && goods.find(k) != goods.end()) {
          goods.erase(k);
        }
      }

      if (goods.size() > 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}